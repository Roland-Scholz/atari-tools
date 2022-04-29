// 0001 0118 : 65816 (magic number)
// ee ee ee ee : offset to __main (entry)
// cc cc cc cc : length of CODE section
// dd dd dd dd : length of DATA section
// ud ud ud ud : length of UDATA section
// rl rl rl rl : #entries of reloc table

// of of of of : offset in code
// le le : length of relocinfo in code (2-4 bytes)
// os os os os : offset in SECTION
// st st : section type (1:CODE, 3:DATA; 4:UDATA)

// code : aligned at 2-byte boundary
// data : aligned at 2-byte boundary
// (udata) : aligned at 2-byte boundary
public class Reloc {

	private Section targetSection;
	private int targetOffset;
	private int targetLength;
	private Section section;
	private int offset;
	private Symbol symbol;

	public Symbol getSymbol() {
		return symbol;
	}

	public void setSymbol(Symbol symbol) {
		this.symbol = symbol;
	}

	public Section getTargetSection() {
		return targetSection;
	}

	public void setTargetSection(Section targetSection) {
		this.targetSection = targetSection;
	}

	public int getTargetOffset() {
		return targetOffset;
	}

	public void setTargetOffset(int targetOffset) {
		this.targetOffset = targetOffset;
	}

	public int getCodeLength() {
		return targetLength;
	}

	public void setCodeLength(int length) {
		this.targetLength = length;
	}

	public int getOffset() {
		return offset;
	}

	public void setOffset(int offset) {
		this.offset = offset;
	}

	public Section getSection() {
		return section;
	}

	public void setSection(Section section) {
		this.section = section;
	}

	@Override
	public String toString() {
		String symbol = "";

		if (this.getSymbol() != null) {
			symbol = this.getSymbol().getName();
		}

		return String.format("Target Section: %5s TargetOffset: %06X Length: %02X Section: %5s Offset: %06X %s",
				this.getTargetSection(), this.getTargetOffset(), this.getCodeLength(), this.getSection(),
				this.getOffset(), symbol);
	}

	public byte[] getBytes() {
		byte[] b;
		byte[] r = new byte[14];

		b = Helper.int2word(this.getTargetSection().ordinal() + 1); // 2
		System.arraycopy(b, 0, r, 0, b.length);

		b = Helper.int2long(this.getTargetOffset()); // 4
		System.arraycopy(b, 0, r, 2, b.length);

		b = Helper.int2word(this.getCodeLength()); // 2
		System.arraycopy(b, 0, r, 6, b.length);

		b = Helper.int2word(this.getSection().ordinal() + 1); // 2
		System.arraycopy(b, 0, r, 8, b.length);

		b = Helper.int2long(this.getOffset()); // 4
		System.arraycopy(b, 0, r, 10, b.length);

		return r;
	}

	public Reloc() {

	}
}
