import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

public class ObjUtil {

	public static void main(String[] args) {

		try {
			new ObjUtil(args);
		} catch (Exception e) {
			System.out.println(e.getMessage());
		}

	}

	private void error(String s) throws Exception {
		throw new Exception("MakeCOM: object-file start-adr(hex), " + s);
	}

	private int hex2int(String h) throws Exception {

		try {
			return Integer.decode("0X" + h).intValue();
		} catch (NumberFormatException e) {
			error("argument 2 must be a valid hexadecimal number");
		}

		return -1;
	}

	private int adr2int(byte b0, byte b1, byte b2) {
		return ((b0 & 0xff) + ((b1 & 0xff) << 8) + ((b2 & 0xff) << 16));
	}

	private String hex4(int i) {
		return String.format("%04X", i);
	}

	private void convertFromWDC(byte[] b, FileOutputStream fout) throws Exception {
		int i, start, len, old_start, out_index, first_start;
		boolean first = true;

		byte c[] = new byte[b.length];

		old_start = 0;
		first_start = 0;
		out_index = 0;

		for (i = 1; i < b.length;) {
			start = adr2int(b[i], b[i + 1], b[i + 2]);
			len = adr2int(b[i + 3], b[i + 4], b[i + 5]);

			// System.out.println("chunk from : " + hex4(start) + String.format("len: %04X",
			// len));

			if (first) {
				first = false;
				old_start = start;
				first_start = start;
			}

			if (!(old_start == start)) {

				fout.write(255);
				fout.write(255);
				fout.write(first_start & 0xff);
				fout.write((first_start >> 8) & 0xff);
				fout.write((first_start + out_index - 1) & 0xff);
				fout.write(((first_start + out_index - 1) >> 8) & 0xff);
				fout.write(c, 0, out_index);

				System.out.println(String.format("chunk written     : %s to: %s len: %s", hex4(first_start),
						hex4(first_start + out_index - 1), hex4(out_index)));

				out_index = 0;
				old_start = first_start = start;

			}

			System.arraycopy(b, i + 6, c, out_index, len);

			old_start += len;
			out_index += len;

			i += len + 6;

		}
	}

	private void ObjFill(String fname, String size) throws Exception {

		File f1 = new File(fname);
		int isize = hex2int(size);
		int inread;

		byte b[] = new byte[isize];

		FileInputStream fin = new FileInputStream(f1);
		inread = fin.read(b);
		fin.close();

		System.out.println(String.format("ObjFill %s, file len: %s, fill-size: %s", fname, hex4(inread), size));
		// FileOutputStream fout = new FileOutputStream(f1);

		for (int i = inread; i < isize; i++) {
			b[i] = (byte) 0xff;
		}

		FileOutputStream fout = new FileOutputStream(f1);
		fout.write(b);
		fout.close();
	}

	public ObjUtil(String[] args) throws Exception {

		if (args.length < 2) {
			error("at least function (Obj2Com | ObjFill) and filename must be given!");
		}

		if (args[0].equals("ObjFill")) {
			if (args.length < 3) {
				error("ObjFill: no Size given");
			}
			ObjFill(args[1], args[2]);
			return;
		}

		File f1 = new File(args[1]);
		int len = (int) f1.length();

		if (len <= 0) {
			error("File does not exist");
		}

		int index = args[1].lastIndexOf(".") + 1;

		String s1 = null;

		if (index == -1) {
			s1 = args[1] + ".com";
		} else {
			s1 = args[1].substring(0, index) + "com";
		}

		byte b[] = new byte[len];

		FileOutputStream fout = new FileOutputStream(s1);
		FileInputStream fin = new FileInputStream(f1);

		fin.read(b);

		System.out.println();
		if (b[0] == 'Z') {
			System.out.println("MakeCOM Ver 1.0   : " + args[1]);
		} else {
			System.out.println("MakeCOM Ver 1.0   : " + args[1] + " " + args[2]);
		}
		System.out.println("Input  file       : " + args[1]);
		System.out.println("Output file       : " + s1);
		System.out.println();

		if (b[0] == 'Z') {
			convertFromWDC(b, fout);
		} else {

			if (args.length != 3) {
				error("please enter 3 parameters");
			}

			int start = hex2int(args[2]);
			int end = start + len - 1;

			fout.write(255);
			fout.write(255);
			fout.write(start & 0xff);
			fout.write((start >> 8) & 0xff);
			fout.write(end & 0xff);
			fout.write((end >> 8) & 0xff);
			fout.write(b);

			System.out.println("Load Address      : " + args[2]);
			System.out.println("End  Address      : " + hex4(end));
			System.out.println("Length            : " + hex4(len));
			System.out.println("Done...");
		}

		fout.close();
		fin.close();
	}

}
