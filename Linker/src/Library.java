import java.io.File;
import java.io.FileInputStream;
import java.util.ArrayList;

public class Library {
	private ArrayList<String> libraryFiles = new ArrayList<String>();
	private ArrayList<Integer> fileNumbers = new ArrayList<Integer>();
	private ArrayList<LibrarySymbol> librarySymbols = new ArrayList<LibrarySymbol>();
	private Modules modules = new Modules();
	private ArrayList<Integer> codeoffsets = new ArrayList<Integer>();

	private int codestart;
	private int numberSymbols;
	private String libraryName;

	public String getLibraryName() {
		return libraryName;
	}

	public void setLibraryName(String libraryName) {
		this.libraryName = libraryName;
	}

	public Modules getModules() {
		return modules;
	}

	/*
	 * public Module getModuleBySymbolName(Symbol sym) {
	 * sym.setLinkage(Linkage.REL); return modules.getBySymbol(sym); }
	 */
	private int readFiles(byte[] lib) {
		int offset = 24;
		int filenum;
		int numfiles;
		int length;
		String filename;

		codestart = Helper.long2int(lib, 8);
		numberSymbols = Helper.long2int(lib, 12);
		numfiles = Helper.long2int(lib, 20);

		System.out.println("Codestart: " + codestart + " files: " + numfiles + " numberSymbols: " + numberSymbols);

		for (int i = 0; i < numfiles; i++) {
			filenum = Helper.word2int(lib, offset);
			length = lib[offset + 2] & 0xff;
			filename = Helper.getString(lib, offset + 3, length);
			offset += 3 + length;

			libraryFiles.add(filename);
			fileNumbers.add(filenum);

			// System.out.println(filename + " " + filenum);
		}

		return offset;
	}

	private int readSymbols(byte[] b, int offset) {

		int nameOffset = offset + numberSymbols * LibrarySymbol.getOffsetIncrement();

		for (int i = 0; i < numberSymbols; i++) {
			LibrarySymbol sym = new LibrarySymbol(b, offset, nameOffset, codestart);
			offset += LibrarySymbol.getOffsetIncrement();
			librarySymbols.add(sym);

			// System.out.println(sym.toString());
		}

		return offset;
	}

	private void readModules(byte[] b) throws Exception {
		for (LibrarySymbol sym : librarySymbols) {
			// System.out.println(sym.toString());

			if (!codeoffsets.contains(sym.getCodeOffset())) {
				codeoffsets.add(sym.getCodeOffset());
				Module m = new Module(b, sym.getCodeOffset(), false, getLibraryName());
				// m.printModule();
				// System.out.println(m.toString());
				modules.add(m);
			}
		}
	}

	public Library(String filename) throws Exception {

		int offset;
		File f = new File(filename);
		FileInputStream fin = new FileInputStream(f);
		byte[] lib = new byte[(int) f.length()];
		fin.read(lib);
		fin.close();

		setLibraryName(filename);
		System.out.println("Library : " + filename);
		offset = readFiles(lib);
		readSymbols(lib, offset);

		readModules(lib);

		// System.out.println();
	}
}
