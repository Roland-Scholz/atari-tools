
public class LibrarySymbol {

	private String name;

	private int stringOffset;
	private int filenum;
	private String fileName;
	private int codeOffset;
	static int offsetIncrement = 8;

	public String getFileName() {
		return fileName;
	}

	public String getName() {
		return name;
	}

	private void setName(String name) {
		this.name = name;
	}

	public static int getOffsetIncrement() {
		return offsetIncrement;
	}

	private int getStringOffset() {
		return stringOffset;
	}

	private void setStringOffset(int stringOffset) {
		this.stringOffset = stringOffset;
	}

	public int getFilenum() {
		return filenum;
	}

	private void setFilenum(int filenum) {
		this.filenum = filenum;
	}

	public int getCodeOffset() {
		return codeOffset;
	}

	private void setCodeOffset(int codeOffset) {
		this.codeOffset = codeOffset;
	}

	@Override
	public String toString() {
		return String.format("%-24s filenum: %02d codeoffset: %010d, %08X", getName(), getFilenum(), getCodeOffset(),
				getCodeOffset());
	}

	public LibrarySymbol(byte[] b, int offset, int nameOffset, int codestart) {
		int nameLen;

		setStringOffset(Helper.word2int(b, offset));
		setFilenum(Helper.word2int(b, offset + 2));
		setCodeOffset(Helper.long2int(b, offset + 4) + codestart);

		nameOffset += getStringOffset();

		nameLen = b[nameOffset] & 0xff;

		setName(Helper.getString(b, nameOffset + 1, nameLen));
	}
}
