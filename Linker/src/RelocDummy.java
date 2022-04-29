import java.util.ArrayList;

enum RelocType {
	SYMBOL, REL;
}

public class RelocDummy {
	private int codeAddr;
	private int addr;
	private int length;
	private int offIncrement;
	private Section section;
	private RelocType relocType;
	private Symbol symbol;

	public Symbol getSymbol() {
		return symbol;
	}

	public void setSymbol(Symbol symbol) {
		this.symbol = symbol;
	}

	public RelocType getRelocType() {
		return relocType;
	}

	public void setRelocType(RelocType relocType) {
		this.relocType = relocType;
	}

	public int getCodeaddr() {
		return codeAddr;
	}

	public void setCodeaddr(int addr) {
		this.codeAddr = addr;
	}

	public int getAddr() {
		return addr;
	}

	public void setAddr(int addr) {
		this.addr = addr;
	}

	public int getLength() {
		return length;
	}

	private void setLength(int length) {
		this.length = length;
	}

	public int getOffIncrement() {
		return offIncrement;
	}

	private void setOffIncrement(int offIncrement) {
		this.offIncrement = offIncrement;
	}

	public Section getSection() {
		return section;
	}

	private void setSection(Section section) {
		this.section = section;
	}

	@Override
	public String toString() {
		String ca = "CodeAddr:" + Helper.int2intHex(getCodeaddr());
		String ad;
		String se;

		if (getRelocType() == RelocType.SYMBOL) {
			ad = "Addr    :" + Helper.int2intHex(getSymbol().getOffset()) + " " + getSymbol().getName();
			se = "Section :" + getSymbol().getSection();
		} else {
			ad = "Addr    :" + Helper.int2intHex(getAddr());
			se = "Section :" + getSection();
		}
		String le = "Length  :" + Helper.int2intHex(getLength());
		String ty = "Type    :" + getRelocType();

		return ca + Helper.ls + le + Helper.ls + ad + Helper.ls + se + Helper.ls + ty;
	}
	/*
	 * public Reloc(Reloc r) { this.setAddr(r.getAddr());
	 * this.setCodeaddr(r.getCodeaddr()); this.setLength(r.getLength());
	 * this.setOffIncrement(r.getOffIncrement()); this.setSection(r.getSection());
	 * this.setSymbol(symbol); }
	 */

	public RelocDummy(byte[] b, int offset, ArrayList<Byte> sectionBytes) {

		setLength(b[offset + 1] & 0xff);
		setRelocType(Helper.int2RelocType(b[offset + 2] & 0xff));
		setCodeaddr(sectionBytes.size());
		setSymbol(null);

		switch (getRelocType()) {
		case SYMBOL:
			setSection(Section.UNKNOWN);
			setAddr(Helper.word2int(b, offset + 3));
			setOffIncrement(6);
			if ((b[offset + 5] & 0xff) != 0) {
				setOffIncrement(12);
			}
			break;
		case REL:
			setSection(Section.getByOrdinal(b[offset + 3] & 0xff));
			setAddr(Helper.long2int(b, offset + 4));
			setOffIncrement(9);
			if ((b[offset + 8] & 0xff) != 0) {
				setOffIncrement(15);
			}
			break;
		}
	}
}
