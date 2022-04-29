import java.io.File;
import java.io.FileInputStream;
import java.util.ArrayList;

public class Module {

	private ArrayList<Byte> code = new ArrayList<Byte>();
	private ArrayList<Byte> kdata = new ArrayList<Byte>();
	private ArrayList<Byte> data = new ArrayList<Byte>();
	private ArrayList<Byte> udata = new ArrayList<Byte>();
	private ArrayList<Expression> expressions = new ArrayList<Expression>();
	private Symbols symbols = new Symbols();

	private String name;
	private String libraryName;

	// enum {SECT_PAGE0, SECT_CODE, SECT_KDATA, SECT_DATA, SECT_UDATA };
	private int codeSize = 0;
	private int kdataSize = 0;
	private int dataSize = 0;
	private int udataSize = 0;

	private boolean debug = false;

	public boolean isDebug() {
		return debug;
	}

	public void setDebug(boolean debug) {
		this.debug = debug;
	}

	public ArrayList<Expression> getExpressions() {
		return expressions;
	}

	public void setExpressions(ArrayList<Expression> expressions) {
		this.expressions = expressions;
	}

	public String getLibraryName() {
		return libraryName;
	}

	private void setLibraryName(String name) {
		this.libraryName = name;
	}

	public String getName() {
		return name;
	}

	private void setName(String name) {
		this.name = name;
	}

	public ArrayList<Byte> getCode() {
		return code;
	}

	public void setCode(ArrayList<Byte> code) {
		this.code = code;
	}

	public ArrayList<Byte> getKdata() {
		return kdata;
	}

	public void setKdata(ArrayList<Byte> kdata) {
		this.kdata = kdata;
	}

	public ArrayList<Byte> getData() {
		return data;
	}

	public void setData(ArrayList<Byte> data) {
		this.data = data;
	}

	public Symbols getSymbols() {
		return symbols;
	}

	public void setSymbols(Symbols symbols) {
		this.symbols = symbols;
	}

	public int getCodeSize() {
		return codeSize;
	}

	public void setCodeSize(int codeSize) {
		this.codeSize = codeSize;
	}

	public int getKdataSize() {
		return kdataSize;
	}

	public void setKdataSize(int kdataSize) {
		this.kdataSize = kdataSize;
	}

	public int getDataSize() {
		return dataSize;
	}

	public void setDataSize(int dataSize) {
		this.dataSize = dataSize;
	}

	public int getUdataSize() {
		return udataSize;
	}

	public void setUdataSize(int udataSize) {
		this.udataSize = udataSize;
	}

	private void doObj(byte[] obj, int offset, boolean debug) throws Exception {
		boolean iterate = true;
		int num, startOffset;
		Section section = Section.SECT_CODE;
		ArrayList<Byte> l = code;

		startOffset = offset;

		setDebug(debug);

		offset += 24;

		code.clear();
		kdata.clear();
		data.clear();
		udata.clear();
		getExpressions().clear();

		setName(Helper.getString(obj, offset));

		/*
		 * if (getName().equals("..\\release\\obj\\startup_short.o")) { debug = true; }
		 * if (getName().equals("..\\release\\obj\\test65816.o")) { debug = true; }
		 */

		if (debug)
			System.out.println(getName());

		offset += getName().length() + 1;

		while (iterate) {

			switch (obj[offset] & 0xff) {

			// end of record
			case 0x00:
				offset += 1;

				while (true) {
					section = Section.getByOrdinal(obj[offset] & 0xff);
					num = obj[offset + 1] & 0xff;

					if (num == 0x40 || num == 0xC0 || num == 0xC8 || num == 0xE8) {
						switch (section) {
						case SECT_CODE:
							setCodeSize(Helper.long2int(obj, offset + 2));
							break;
						case SECT_KDATA:
							setKdataSize(Helper.long2int(obj, offset + 2));
							break;
						case SECT_DATA:
							setDataSize(Helper.long2int(obj, offset + 2));
							break;
						case SECT_UDATA:
							setUdataSize(Helper.long2int(obj, offset + 2));
							break;
						default:
							break;
						}
						offset += 10;
					} else {
						break;
					}

				}

				offset--;
				iterate = false;
				break;

			// switch SECTION, next word is section number
			case 0xf0:
				section = Section.getByOrdinal(obj[offset + 1] & 0xff);

				if (debug)
					System.out.println(Helper.hex4(offset - startOffset) + ": section " + section.toString());

				switch (section) {
				case SECT_CODE:
					l = code;
					break;
				case SECT_KDATA:
					l = kdata;
					break;
				case SECT_DATA:
					l = data;
					break;
				case SECT_UDATA:
					l = udata;
					break;
				default:
					l = null;
				}

				offset += 2;
				break;

			// expression follows
			case 0xf4:
				break;
			case 0xf1:

				if ((obj[offset] & 0xff) == 0xf4) {
					System.out.println();
				}

				// if (offset == 81739)
				// debug = true;
				Expression ex = new Expression(obj, offset + 1, l.size(), section);
				getExpressions().add(ex);

				if (debug)
					System.out.println(
							Helper.hex4(offset) + ":" + Helper.hex4(offset - startOffset) + ": " + ex.toString());

				for (int i = 0; i < ex.getCodeLength(); i++) {
					l.add((byte) 0x00);
				}

				offset += ex.getIncrement() + 1;

				break;

			// spaces /* word count of bytes to reserve */
			case 0xf2:
				num = Helper.word2int(obj, offset + 1);

				if (debug)
					System.out.println("reserve space " + num + " ");
				for (int i = 0; i < num; i++) {
					l.add((byte) 0x00);
					if (debug)
						System.out.print(Helper.hex2(0x00) + " ");
				}
				if (debug)
					System.out.println("\n");

				offset += 3;
				break;

			/* long word new pc */
			case 0xf3:
				break;

			/* pc-relative expression */
			// case 0xf4:
			// break;

			// debug bytes
			case 0xf5:
				num = Helper.word2int(obj[offset + 1], obj[offset + 2]);

				if (debug)
					System.out.println(Helper.hex4(offset - startOffset) + ": 0xf5 debug len: " + num);
				offset += 3 + num;
				break;

			/* bump line counter */
			case 0xf6:
				break;
			// data bytes
			default:
				num = obj[offset] & 0xff;

				if (debug)
					System.out.println(Helper.hex4(offset - startOffset) + ": data len: " + num + " section: " + section
							+ " addr: " + l.size() + " " + Helper.hex4(l.size()));

				offset++;

				for (int i = offset; i < num + offset; i++) {
					l.add(obj[i]);
					if (debug)
						System.out.print(Helper.hex2(obj[i]) + " ");
				}

				if (debug)
					System.out.println();

				offset += num;
			}
		} // while

		offset++;

		while (offset < obj.length) {
			if ((obj[offset] & 0xff) == 'Z') {
				break;
			}

			Symbol s = new Symbol(obj, offset);
			symbols.add(s);
			offset += s.getOffIncrement();
		}

		for (Expression ex : this.getExpressions()) {
			ex.linkSymbols(symbols);
		}
	}

	@Override
	public String toString() {
		int i = 1;
		StringBuilder s = new StringBuilder();

		s.append("Module   : " + getName() + " CodeSize : " + codeSize + " DataSize : " + dataSize + " UDataSize: "
				+ udataSize + Helper.ls);

		for (Symbol sym : symbols) {
			if (sym.getLinkage() == Linkage.S_ABS)
				continue;

			s.append(String.format("%06d ", i++) + sym.toString() + Helper.ls);
		}
		/*
		 * i = 1; for (Expression ex : expressions) { s.append(String.format("%06d ",
		 * i++) + ex.toString() + Helper.ls); s.append(ex.getByteHolder().toString() +
		 * Helper.ls); }
		 */
		return s.toString();
	}

	public void printModule() {
		System.out.println(this.toString());

		// System.out.println("Code:");
		// Helper.dump(code);
		// System.out.println("Data:");
		// Helper.dump(data);

	}

	public void removeSymbol(Symbol sym) {
		this.getSymbols().remove(sym);
	}

	public void addExpressions(ArrayList<Expression> exs) {
		this.getExpressions().addAll(exs);
	}

	public void addSymbols(ArrayList<Symbol> syms) {
		this.getSymbols().addAll(syms);
	}

	public void addSymbol(Symbol sym) {
		this.getSymbols().add(sym);
	}

	public void addCode(ArrayList<Byte> bytes) {
		this.getCode().addAll(bytes);
	}

	public void addKdata(ArrayList<Byte> bytes) {
		this.getKdata().addAll(bytes);
	}

	public void addData(ArrayList<Byte> bytes) {
		this.getData().addAll(bytes);
	}

	public void replaceSymbolInExpressions(Symbol src, Symbol dest) {

		ExpressionItem item;

		for (Expression ex : getExpressions()) {
			item = ex.getList();
			while (item != null) {
				if (item.isSymbol() && item.getSymbol().equals(src)) {
					item.setSymbol(dest);
				}
				item = item.getNext();
			}
		}
	}

	public boolean existsUndefinedSymbol() {
		boolean found = false;
		for (Symbol s : this.getSymbols()) {
			if (s.getLinkage().equals(Linkage.S_UND)) {
				System.out.println("Symbol: " + s.toString() + " could not be resolved.");
				found = true;
			}
		}
		return found;
	}

	public int getSymbolIndex(Symbol sym) {
		return getSymbols().indexOf(sym);
	}

	/*
	 * public void adjustSymbolRelocs(int oldindex, int newindex) { for (Reloc r :
	 * this.getRelocs()) { if (r.getRelocType() == RelocType.SYMBOL && r.getAddr()
	 * == oldindex) { r.setAddr(newindex); } } }
	 */

	public void adjustOffsets(int codeOffset, int kdataOffset, int dataOffset, int udataOffset) {

		ExpressionItem item;

		for (Expression ex : getExpressions()) {
			switch (ex.getSection()) {
			case SECT_CODE:
				ex.setOffset(ex.getOffset() + codeOffset);
				break;
			case SECT_KDATA:
				ex.setOffset(ex.getOffset() + kdataOffset);
				break;
			case SECT_DATA:
				ex.setOffset(ex.getOffset() + dataOffset);
				break;
			default:
				break;
			}

			item = ex.getList();
			while (item != null) {
				if (item.isOffset()) {
					switch (item.getSection()) {
					case SECT_CODE:
						item.setValue(item.getValue() + codeOffset);
						break;
					case SECT_KDATA:
						item.setValue(item.getValue() + kdataOffset);
						break;
					case SECT_DATA:
						item.setValue(item.getValue() + dataOffset);
						break;
					case SECT_UDATA:
						item.setValue(item.getValue() + udataOffset);
						break;
					case UNKNOWN:
						break;
					default:
						break;

					}
				}
				item = item.getNext();
			}
		}

		for (Symbol sym : getSymbols()) {
			switch (sym.getLinkage()) {
			case S_REL:
				switch (sym.getSection()) {
				case SECT_CODE:
					sym.setOffset(sym.getOffset() + codeOffset);
					break;
				case SECT_KDATA:
					sym.setOffset(sym.getOffset() + kdataOffset);
					break;
				case SECT_DATA:
					sym.setOffset(sym.getOffset() + dataOffset);
					break;
				case SECT_UDATA:
					sym.setOffset(sym.getOffset() + udataOffset);
					break;
				case UNKNOWN:
					break;
				default:
					break;
				}
				break;
			case S_UND:
				break;
			default:
				break;

			}
		}
	}

	public Symbol getSymbol(Symbol sym, Linkage linkage) {
		for (Symbol s : this.getSymbols()) {
			if (s.getName().equals(sym.getName()) && s.getLinkage().equals(linkage)) {
				// System.out.println("found Symbol " + linkage + " " + sym.getName() + " in
				// module: " + this.getName());
				return s;
			}
		}
		return null;
	}

	public Symbol getSymbolAbs(Symbol sym) {
		return getSymbol(sym, Linkage.S_ABS);
	}

	public Symbol getSymbolRel(Symbol sym) {
		return getSymbol(sym, Linkage.S_REL);
	}

	public Symbol getSymbolRel(String symName) {
		return getSymbol(new Symbol(symName), Linkage.S_REL);
	}

	public Symbol getSymbolUndefined(Symbol sym) {
		return getSymbol(sym, Linkage.S_UND);
	}

	public byte[] getBytes(Section section) {
		switch (section) {
		case SECT_CODE:
			return Helper.getBytes(this.getCode());
		case SECT_KDATA:
			return Helper.getBytes(this.getKdata());
		case SECT_DATA:
			return Helper.getBytes(this.getData());
		default:
			return null;
		}
	}

	public Module(byte[] obj, int offset, boolean debug, String libraryName) throws Exception {
		doObj(obj, offset, debug);
		setLibraryName(libraryName);
		// printModule();
	}

	public Module(byte[] obj, int offset, boolean debug) throws Exception {
		doObj(obj, offset, debug);
		// printModule();
	}

	public Module(byte[] obj, int offset) throws Exception {
		doObj(obj, offset, false);
		// printModule();
	}

	public Module(byte[] obj) throws Exception {

		doObj(obj, 0, true);
		// printModule();
	}

	public Module(String moduleName) throws Exception {
		System.out.println("loading Module: " + moduleName);
		File f = new File(moduleName);
		// System.out.println(f.canRead());

		FileInputStream fin = new FileInputStream(f);
		byte[] obj = new byte[(int) f.length()];
		fin.read(obj);
		fin.close();

		doObj(obj, 0, false);
		// System.out.println("finished.");
	}
	/*
	 * public Module(Module m) {
	 * 
	 * this.setName(m.getName()); this.setCodeSize(m.getCodeSize());
	 * this.setDataSize(m.getDataSize()); this.setUdataSize(m.getUdataSize());
	 * 
	 * this.setCode(m.getCode()); this.setData(m.getData()); this.setRelocs(new
	 * ArrayList<Reloc>()); this.setSymbols(new ArrayList<Symbol>());
	 * 
	 * for (Reloc r : m.getRelocs()) { this.relocs.add(new Reloc(r)); }
	 * 
	 * for (Symbol sym : m.getSymbols()) { this.symbols.add(new Symbol(sym)); }
	 * 
	 * }
	 */
}
