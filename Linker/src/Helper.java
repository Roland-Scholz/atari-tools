import java.util.ArrayList;

public class Helper {
	public static String ls = System.getProperty("line.separator");

	public static String int2intHex(int i) {
		return String.format("%08d $%06X", i, i);
	}

	public static byte[] int2long(int i) {
		byte[] b = new byte[4];

		b[0] = (byte) (i & 0xff);
		b[1] = (byte) ((i >> 8) & 0xff);
		b[2] = (byte) ((i >> 16) & 0xff);
		b[3] = (byte) ((i >> 24) & 0xff);

		return b;
	}

	public static byte[] int2word(int i) {
		byte[] b = new byte[2];

		b[0] = (byte) (i & 0xff);
		b[1] = (byte) ((i >> 8) & 0xff);

		return b;
	}

	public static int hex2int(String h) throws Exception {

		return Integer.decode("0X" + h).intValue();
		/*
		 * catch (NumberFormatException e) {
		 * error("argument 2 must be a valid hexadecimal number"); } return -1;
		 */
	}

	public static int long2int(byte[] b, int offset) {
		return long2int(b[offset], b[offset + 1], b[offset + 2], b[offset + 3]);
	}

	public static int long2int(byte b0, byte b1, byte b2, byte b3) {
		return ((b0 & 0xff) + ((b1 & 0xff) << 8) + ((b2 & 0xff) << 16) + ((b3 & 0xff) << 24));
	}

	public static int adr2int(byte b0, byte b1, byte b2) {
		return ((b0 & 0xff) + ((b1 & 0xff) << 8) + ((b2 & 0xff) << 16));
	}

	public static int word2int(byte[] b, int offset) {
		return (word2int(b[offset], b[offset + 1]));
	}

	public static int word2int(byte b0, byte b1) {
		return ((b0 & 0xff) + ((b1 & 0xff) << 8));
	}

	public static String hex2(int i) {
		return String.format("%02X", i & 0xff);
	}

	public static String hex4(int i) {
		return String.format("%04X", i);
	}
	
	public static String hex8(int i) {
		return String.format("%08X", i);
	}

	public static String getString(byte[] b, int offset) {
		StringBuffer s = new StringBuffer();
		while (b[offset] != 0) {
			s.append((char) b[offset]);
			offset++;
		}

		return s.toString();
	}

	public static String getString(byte[] b, int offset, int length) {
		StringBuffer s = new StringBuffer();
		for (int i = 0; i < length; i++) {
			s.append((char) b[offset]);
			offset++;
		}

		return s.toString();
	}

	public static void dump(byte[] bs) {
		ArrayList<Byte> b = new ArrayList<Byte>();
		
		for (int i = 0; i < bs.length; i++) {
			b.add(bs[i]);
		}
		dump(b);
	}
	
	public static void dump(ArrayList<Byte> b) {

		for (int i = 0; i < b.size(); i++) {
			if (i % 16 == 0) {
				if (i != 0) {
					System.out.println();
				}
				System.out.print(hex4(i) + ": ");
			}

			System.out.print(hex2(b.get(i)) + " ");
		}

		System.out.println();
	}

	public static RelocType int2RelocType(int section) {
		switch (section) {
		case 1:
			return RelocType.SYMBOL;
		case 3:
			return RelocType.REL;
		}
		return null;
	}

	public static byte[] getBytes(ArrayList<Byte> ab) {
		int size = ab.size();
		byte[] result = new byte[size];
		for (int i = 0; i < size; i++) {
			result[i] = ab.get(i).byteValue();
		}
		return result;
	}
}
