import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Vector;

public class Linker {

	private Modules modules = new Modules();
	private String outputFile = "a.out";
	private String headerMagic = "R816";
	private boolean disass = false;
	private Symbols outSymbols = new Symbols();
	private boolean debug = false;

	public boolean isDebug() {
		return debug;
	}

	public void setDebug(boolean debug) {
		this.debug = debug;
	}

	public boolean isDisass() {
		return disass;
	}

	public void setDisass(boolean disass) {
		this.disass = disass;
	}

	public String getOutputFile() {
		return outputFile;
	}

	public void setOutputFile(String outputFile) {
		this.outputFile = outputFile;
	}

	public Modules getModules() {
		return modules;
	}

	public static void main(String[] args) {

		try {
			new Linker(args);
		} catch (Exception e) {
			System.out.println(e);
			e.printStackTrace();
			System.exit(16);
		}

	}

	private void printArgs(String argv[]) {
		int i = 0;
		for (String s : argv) {
			System.out.println("arg " + i + ":" + s);
			i++;
		}
	}

	private void resolveSymbols(Module m, Modules lib) {
		int index = 0;
		Symbol sym;
		Symbol relSymbol;
		Symbol absSymbol;
		boolean symbolDone;

		// resolve UNDEFINES symbols
		while (index < m.getSymbols().size()) {

			sym = m.getSymbols().get(index);

			if (sym.getLinkage() == Linkage.S_UND) {

				symbolDone = false;

				// System.out.println("resolving symbol: " + sym.getName() + " " +
				// sym.getSection());

				/* remove this symbol if an ABSOLUTE Symbol is already in the module */
				if ((absSymbol = m.getSymbolAbs(sym)) != null) {

					m.replaceSymbolInExpressions(sym, absSymbol);
					m.getSymbols().remove(sym);

					System.out.println("Symbol: " + sym.getName() + " found absolute, removing...");
					index -= 2;
					symbolDone = true;
				}

				/* remove this symbol if an REL Symbol is already in the module */
				if (!symbolDone && (relSymbol = m.getSymbolRel(sym)) != null) {

					m.replaceSymbolInExpressions(sym, relSymbol);
					m.getSymbols().remove(sym);

					// System.out.println("Symbol : " + sym.getName() + " found in module,
					// removing...");
					index -= 2;
					symbolDone = true;
				}

				if (!symbolDone) {

					/* find a REL Symbol in Libraries */
					Module m0 = lib.getBySymbolRel(sym);

					if (m0 != null) {

						System.out.println("Symbol: " + sym.getName() + " adding module:" + m0.getName() + " size:"
								+ m0.getCodeSize() + " lib:" + m0.getLibraryName());

						Symbol sym1 = m0.getSymbolRel(sym);

						int codeOffset = m.getCodeSize();
						int kdataOffset = m.getKdataSize();
						int dataOffset = m.getDataSize();
						int udataOffset = m.getUdataSize();

						// remove the UNDEFINED Symbol from module;
						m.replaceSymbolInExpressions(sym, sym1);
						m.removeSymbol(sym);

						m.addCode(m0.getCode());
						m.addKdata(m0.getKdata());
						m.addData(m0.getData());

						m0.adjustOffsets(codeOffset, kdataOffset, dataOffset, udataOffset);

						m.addExpressions(m0.getExpressions());
						m.addSymbols(m0.getSymbols());

						m.setCodeSize(codeOffset + m0.getCodeSize());
						m.setKdataSize(dataOffset + m0.getKdataSize());
						m.setDataSize(dataOffset + m0.getDataSize());
						m.setUdataSize(udataOffset + m0.getUdataSize());

						index--;

					} else {
						System.out.println("Symbol: " + sym.getName() + " could not be resolved.");
					}
				}
			}
			index++;
		}

	}

	private Module linkModule() throws Exception {

		Modules ms = this.getModules();
		Module m;
		ArrayList<Expression> removeList = new ArrayList<Expression>();

		// get first module and remove from module list
		// this module is taken as the starting point for the link process
		if (ms.size() > 0) {
			m = ms.get(0);
			ms.remove(m);
		} else {
			throw new Exception("nothing to generate.");
		}

		resolveSymbols(m, ms);

		Symbol begData = new Symbol("_BEG_DATA");
		begData.setLinkage(Linkage.S_REL);
		begData.setOffset(0);
		begData.setSection(Section.SECT_UDATA);

		m.addSymbol(begData);

		resolveSymbols(m, ms);

//		resolve ABSOLUTE Symbols in code
		for (Expression ex : m.getExpressions()) {

			ExpressionItem ei = ex.getList();

			if (ei.isSymbol() && ei.getSymbol().getLinkage() == Linkage.S_ABS) {

				// System.out.println(ex.toString());

				byte[] adr = Helper.int2long(ei.getSymbol().getOffset());
				ArrayList<Byte> code = m.getCode();
				int off = ex.getOffset();

				for (int i = 0; i < ex.getCodeLength(); i++) {
					code.set(off + i, adr[i]);
				}

				removeList.add(ex);
			}
		}

		m.getExpressions().removeAll(removeList);

		// compute needed symbols for output
		System.out.println("compute output symbols:");
		Symbol sym;
		int index;

		for (Expression ex : m.getExpressions()) {
			ExpressionItem ei = ex.getList();

			while (ei != null) {
				if (ei.isSymbol()) {
					sym = ei.getSymbol();
					index = outSymbols.indexOf(sym);
					if (index == -1) {
						outSymbols.add(sym);
						index = outSymbols.size() - 1;
					}
					ei.setValue(index);
				}
				ei = ei.getNext();
			}
		}

		return m;
	}

	private Vector<String> generatePathlist(String strPaths, String fileName) {
		Vector<String> filePaths = new Vector<String>();

		int index = 0;
		if (strPaths == null) {
			strPaths = "";
		}

		while (index != -1) {
			String path = strPaths;

			index = strPaths.indexOf(';');
			if (index != -1) {
				path = strPaths.substring(0, index);
				strPaths = strPaths.substring(index + 1);
			}

			if (!path.endsWith(File.separator)) {
				path = path + File.separator;
			}

			path = path + fileName;

			filePaths.add(path);
		}

		return filePaths;
	}

	private void processDef(String defFileName) throws Exception {
		Symbols syms = new Symbols();
		Symbol sym;

		String line;
		int base = 0x10000;
		String words[];
		BufferedReader fin = new BufferedReader(new FileReader(new File(defFileName)));

		line = fin.readLine();
		while (line != null) {
			words = line.split("\\s+");

			switch (words.length) {
			case 1:
				if (words[0].length() > 0) {
					base += 3;
					sym = new Symbol(words[0]);
					sym.setLinkage(Linkage.S_ABS);
					sym.setOffset(base);
					sym.setSection(Section.SECT_CODE);
					syms.add(sym);
					// System.out.println(words[0] + ":" + base);
				}
				break;
			case 2:
				base = Helper.hex2int(words[1]);
				// System.out.println(words[0] + ":" + words[1] + ":" + base);
				break;
			}

			line = fin.readLine();
		}
		this.getModules().get(0).addSymbols(syms);

		fin.close();
	}

	private void importDef(String defName) throws Exception {
		String wdcLib = System.getenv("WDC_LIB");
		Vector<String> libPaths = generatePathlist(wdcLib, defName);

		boolean defFound = false;

		for (String libPath : libPaths) {
			if (!defFound) {
				try {
					processDef(libPath);
					defFound = true;
				} catch (FileNotFoundException e) {
				}
			}
		}

		if (!defFound) {
			throw new Exception("cannot load definition: " + defName);
		}

	}

	private void importLibrary(String libraryName) throws Exception {

		String wdcLib = System.getenv("WDC_LIB");

		Vector<String> libPaths = generatePathlist(wdcLib, libraryName);

		boolean libFound = false;

		for (String libPath : libPaths) {
			if (!libFound) {
				try {
					// System.out.println(libPath);
					Library l = new Library(libPath);
					getModules().addAll(l.getModules());
					libFound = true;
					// System.out.println("loaded.");
				} catch (FileNotFoundException e) {
				}
			}
		}

		if (!libFound) {
			throw new Exception("cannot load library: " + libraryName);
		}

	}

	private void processObject(String objectName) throws Exception {
		// System.out.println(System.getProperty("user.dir"));
		Module m = new Module(objectName);
		getModules().add(m);
	}

	private void processArgs(String[] args) throws Exception {

		String arg;

		for (int argc = 0; argc < args.length; argc++) {

			arg = args[argc];

			if (arg.charAt(0) == '-') {
				if (arg.length() >= 2) {
					char parm = arg.toLowerCase().charAt(1);
					if (argc + 1 < args.length) {
						switch (parm) {
						case 'l':
							importLibrary(args[argc + 1]);
							argc++;
							continue;
						case 'o':
							setOutputFile(args[argc + 1]);
							argc++;
							continue;
						case 'a':
							importDef(args[argc + 1]);
							argc++;
							continue;
						default:
							break;
						}
					}

					switch (parm) {
					case 'd':
						setDisass(true);
						break;
					case 'v':
						setDebug(true);
						break;
					default:
						throw new Exception("unknown parameter -" + parm);
					// break;
					}

				} else {
					throw new Exception("no parameter oder value for parameter given.");
				}
			} else {
				processObject(args[argc]);
			}
		}

	}

	// 0001 0118 : 65816 (magic number)
	// ee ee ee ee : offset to __main (entry)
	// cc cc cc cc : length of CODE section
	// dd dd dd dd : length of DATA section
	// ud ud ud ud : length of UDATA section
	// rl rl rl rl : #entries of reloc table

	// tst tst : target section type
	// of of of of : offset to target section
	// le le : length of relocinfo in code (2-4 bytes)
	// st st : section type (1:CODE, 3:DATA; 4:UDATA)
	// os os os os : offset in SECTION

	// code : aligned at 2-byte boundary
	// data : aligned at 2-byte boundary
	// (udata) : aligned at 2-byte boundary

	private void writeOutputFile(Module m) throws Exception {
		File f = new File(getOutputFile());
		String strMain = "~~main";
		int i;

		FileOutputStream fout = new FileOutputStream(f);

		fout.write(headerMagic.getBytes());

		Symbol main = m.getSymbolRel(strMain);

		if (main == null) {
			fout.write(Helper.int2long(0));
		} else {
			fout.write(Helper.int2long(main.getOffset()));
		}

		fout.write(Helper.int2long(m.getCodeSize()));
		fout.write(Helper.int2long(m.getDataSize()));
		fout.write(Helper.int2long(m.getUdataSize()));
		fout.write(Helper.int2long(outSymbols.size()));
		fout.write(Helper.int2long(m.getExpressions().size()));

		// write code and data bytes
		fout.write(m.getBytes(Section.SECT_CODE));
		fout.write(m.getBytes(Section.SECT_DATA));

		i = 0;
		for (Symbol sym : outSymbols) {
			System.out.println(String.format("%06d ", i++) + sym.toString());
			fout.write(sym.getBytes());
		}

		i = 0;
		for (Expression ex : m.getExpressions()) {
			if (isDebug()) {
				System.out.println(String.format("%06d ", i++) + ex.toString());
				System.out.println(ex.getByteHolder().toString());
			}
			fout.write(ex.getBytes());
		}

		fout.close();
	}

	private void writeModules(Module m) throws IOException, InterruptedException {
		int i, j, symNum, offsetEnd, len;
		Symbol symbol, symbolNext = null;
		Symbols symbols = m.getSymbols();
		byte b[] = m.getBytes(Section.SECT_CODE);
		String fileName;
		Process p = null;

		String pythonPath = System.getenv("PYTHON_PATH");

		symNum = m.getSymbols().size();

		for (i = 0; i < symNum; i++) {
			symbol = symbols.get(i);
			if (symbol.getSection().equals(Section.SECT_CODE) && symbol.getLinkage().equals(Linkage.S_REL)) {

				for (j = i + 1; j < symNum; j++) {
					symbolNext = symbols.get(j);
					if (symbolNext.getSection().equals(Section.SECT_CODE)
							&& symbolNext.getLinkage().equals(Linkage.S_REL)) {
						break;
					}
				}

				if (j >= symNum) {
					offsetEnd = m.getCodeSize();
				} else {
					offsetEnd = symbolNext.getOffset();
				}

				len = offsetEnd - symbol.getOffset();
				byte[] r = new byte[len];

				System.arraycopy(b, symbol.getOffset(), r, 0, len);

				fileName = symbol.getName() + ".obj";
				File f = new File(fileName);
				FileOutputStream fout = new FileOutputStream(f);
				fout.write(r);
				fout.close();

				p = Runtime.getRuntime()
						.exec("cmd /c " + pythonPath + "python C:\\atarigit\\Tools\\disasm\\disasm65816.py " + fileName
								+ " > " + symbol.getName() + ".txt");

			}
		}

		if (p != null) {
			p.waitFor();
		}

	}

	public Linker(String[] args) throws Exception {

		int cs, ds, us;

		processArgs(args);

		System.out.println("Linking...");
		Module m = linkModule();
		System.out.println("ready...");

		cs = m.getCodeSize();
		ds = m.getDataSize();
		us = m.getUdataSize();

		if (!m.existsUndefinedSymbol()) {
			// m.printModule();

			System.out.println(String.format("Code  size:%s", Helper.int2intHex(cs)));
			System.out.println(String.format("Data  size:%s", Helper.int2intHex(ds)));
			System.out.println(String.format("UData size:%s", Helper.int2intHex(us)));
			System.out.println(String.format("Total size:%s", Helper.int2intHex(cs + ds + us)));

			writeOutputFile(m);

			if (this.isDisass()) {
				writeModules(m);
			}
			System.exit(0);
		}

		System.out.println("ERROR: rc=8");
		System.exit(8);
	}
}
