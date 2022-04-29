import java.util.ArrayList;

public class ByteHolder extends ArrayList<Byte> {

	private static final long serialVersionUID = 3083335260988022862L;

	public byte[] getBytes() {
		int size = this.size();
		byte[] result = new byte[size];
		for (int i = 0; i < size; i++) {
			result[i] = this.get(i).byteValue();
		}
		return result;
	}

	public void add(byte[] b) {
		for (int i = 0; i < b.length; i++) {
			this.add(b[i]);
		}
	}
	
	public void add(int i) {
		this.add(Byte.valueOf((byte)(i & 0xff)));
	}
	
	public void add4(int i) {
		this.add(Helper.int2long(i));
	}
	
	public String toString() {
		StringBuffer s = new StringBuffer();
		s.append('[');
		for (Byte b: this) {
			s.append(Helper.hex2(b));
			s.append(',');
		}
		s.setCharAt(s.length()-1, ']');
		
		return s.toString();
	}

}
