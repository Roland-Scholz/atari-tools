//enum { S_UND, S_ABS, S_REL, S_EXP, S_REG, S_FREG };
enum Linkage {
	S_UND, S_ABS, S_REL, S_EXP, S_REG, S_FREG;

	public static Linkage getByOrdinal(int i) {
		for (Linkage l : Linkage.values()) {
			if (i == l.ordinal())
				return l;
		}
		return null;
	}
}

enum Section {
//enum {SECT_PAGE0, SECT_CODE, SECT_KDATA, SECT_DATA, SECT_UDATA };
	SECT_PAGE0, SECT_CODE, SECT_KDATA, SECT_DATA, SECT_UDATA, UNKNOWN;

	public static Section getByOrdinal(int i) {
		for (Section s : Section.values()) {
			if (i == s.ordinal())
				return s;
		}
		return null;
	}
}

public class Symbol {

	private String name;
	private int offset;
	private Linkage linkage;
	private int offIncrement;
	private Section section;

	public Section getSection() {
		return section;
	}

	public void setSection(Section section) {
		this.section = section;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getOffset() {
		return offset;
	}

	public void setOffset(int offset) {
		this.offset = offset;
	}

	public Linkage getLinkage() {
		return linkage;
	}

	public void setLinkage(Linkage l) {
		this.linkage = l;
	}

	public int getOffIncrement() {
		return offIncrement;
	}

	public void setOffIncrement(int offIncrement) {
		this.offIncrement = offIncrement;
	}

	@Override
	public String toString() {
		return (String.format("Link:%-8s Sect:%-10s Off:%s Name:%s bytes:%s", getLinkage(), getSection(),
				Helper.int2intHex(getOffset()), getName(), getByteHolder().toString()));
	}

	public Symbol(Symbol sym) {
		this.setName(sym.getName());
		this.setOffset(sym.getOffset());
		this.setLinkage(sym.getLinkage());
		this.setOffIncrement(sym.getOffIncrement());
		this.setSection(sym.getSection());
	}

	public Symbol(String symbolName) {
		this.setName(symbolName);
		this.setOffset(0);
		this.setLinkage(Linkage.S_UND);
		this.setOffIncrement(0);
		this.setSection(Section.UNKNOWN);
	}

	public Symbol(byte[] b, int offset) {
		int bLinkage = b[offset] & 0x0f;
		int bSection = b[offset + 2] & 0xff;
		int adjust = 0;

		Linkage linkage = Linkage.getByOrdinal(bLinkage);
		Section section = Section.getByOrdinal(bSection);

		setLinkage(linkage);
		setSection(section);
		setOffset(0);

		if (linkage != Linkage.S_UND) {
			setOffset(Helper.long2int(b, offset + 3));
			adjust += 4;
		}

		setName(Helper.getString(b, offset + adjust + 3));
		setOffIncrement(getName().length() + adjust + 4);

		// System.out.println(this.getName());
		// System.out.println(this.toString());
	}

	public byte[] getBytes() {
		return getByteHolder().getBytes();
	}

	public ByteHolder getByteHolder() {
		ByteHolder b = new ByteHolder();
		// b.add(0);
		b.add(getLinkage().ordinal());
		if (getSection() != null)
			b.add(getSection().ordinal());
		else
			b.add(0);

		if (getLinkage() != Linkage.S_UND) {
			b.add4(getOffset());
		}
		// b.add(getName().getBytes());
		// b.add(0);
		// b.set(0, (byte)(b.size() - 1));

		return b;
	}
}
