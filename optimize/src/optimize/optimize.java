package optimize;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

public class optimize {

	private String progName = "optimize";
	private String srcName;
	private String dstName;

	public String getDstName() {
		return dstName;
	}

	public void setDstName(String dstName) {
		this.dstName = dstName;
	}

	public String getProgName() {
		return progName;
	}

	public void setProgName(String progName) {
		this.progName = progName;
	}

	public String getSrcName() {
		return srcName;
	}

	public void setSrcName(String srcName) {
		this.srcName = srcName;
	}

	private void addOpcode(int ops, String opcode, String value, int index, ArrayList<String> af) {
		String dest = null;

		af.set(index, ";" + af.get(index));

		switch (ops) {
		case 0:
			dest = ">MULINBL";
			break;
		case 1:
			dest = ">MULINBH";
			break;
		case 2:
			dest = ">MULINAL";
			break;
		case 3:
			dest = ">MULINAH";
			break;
		}

		af.add(index + 1, "\tsta\t" + dest);

		if (!opcode.equals("pha")) {
			af.add(index + 1, "\tlda\t" + value);
		}
	}

	private void processFile(String srcName, String dstName) throws Exception {

		BufferedReader fin = new BufferedReader(new FileReader(new File(srcName)));
		FileWriter fw = new FileWriter(dstName);
		ArrayList<String> af = new ArrayList<String>();

		String line;
		String mnem;
		String opcode, value;

		int index, ops, lineCnt;

		// System.out.println(srcName + " " + dstName);
		line = fin.readLine();
		af.add("\t.include homebrewWDC.inc");

		lineCnt = 0;
		try {
			while (line != null) {
				lineCnt++;

				af.add(line);
				index = af.size() - 1;

				mnem = line.trim();

				if (mnem.indexOf("jsl	~~~mulx") == 0) {
					af.set(index, ";" + af.get(index));
					opcode = "\tlda\t>MULOUTL";
					af.add(index + 1, opcode);
					index--;
					af.set(index, ";" + af.get(index));
					opcode = "\tsta\t>MULINBL";
					af.add(index, opcode);
					af.add(index, "\ttxa");
					index--;
					opcode = "\tsta\t>MULINAL";
					af.add(index, opcode);
				}

				if (mnem.indexOf("jsl	~~~lmulx") == 0) {
					af.set(index, ";" + af.get(index));

					opcode = "\tlda\t>MULOUTL";
					af.add(index + 1, opcode);
					af.add(index + 1, "\ttax");
					opcode = "\tlda\t>MULOUTH";
					af.add(index + 1, opcode);

					index--;
					af.set(index, ";" + af.get(index));

					ops = 0;
					while (true) {
						index--;
						String s[] = af.get(index).split("\t");
						// System.out.println("*** s1:" + s[1] + " s2:" + s[2]);

						if (s.length > 2)
							value = s[2];
						else
							value = "";

						switch (s[1]) {
						case "pei":
						case "pea":
						case "pha":
							addOpcode(ops, s[1], value, index, af);
							ops++;
							break;
						}
						if (ops > 3)
							break;
					}

				}

				if (mnem.indexOf("jsl	~~~lasl") == 0 && af.get(index-2).equals("\tlda\t#$1")) {
					for(int i = 0; i < 7; i++) {
						if (i == 5) continue;
						af.set(index-i, ";" + af.get(index-i));						
					}
					
					String[] s = af.get(index-5).split("\t");
					af.add(index-4,"\tldx\t" + s[2]);
					af.add(index-4,"\trol\t" + s[2]);
					af.add(index-4,"\tasl\ta");
					/*
					af.set(index, ";" + af.get(index));

					opcode = "\tlda\t>MULOUTL";
					af.add(index + 1, opcode);
					af.add(index + 1, "\ttax");
					opcode = "\tlda\t>MULOUTH";
					af.add(index + 1, opcode);

					index--;
					//af.set(index, ";" + af.get(index));

					index--;
					af.add(index + 1, "\tsta\t>MULINAL");
					af.add(index + 1, "\tdb $d0, $fc");
					af.add(index + 1, "\tdex");
					af.add(index + 1, "\tasl a");
					//af.add(index + 1, "\tsec");
					af.add(index + 1, "\tlda #1");
					af.add(index + 1, "\ttax");

					ops = 0;
					while (true) {
						index--;
						String s[] = af.get(index).split("\t");
						// System.out.println("*** s1:" + s[1] + " s2:" + s[2]);

						if (s.length > 2)
							value = s[2];
						else
							value = "";

						switch (s[1]) {
						case "pei":
						case "pea":
						case "pha":
							addOpcode(ops, s[1], value, index, af);
							ops++;
							break;
						}
						if (ops > 1)
							break;		
					}
				*/	
				}

				line = fin.readLine();
			}
		} catch (java.lang.ArrayIndexOutOfBoundsException e) {
			System.out.println(lineCnt + " " + line);
			e.printStackTrace();

		}
		fin.close();

		for (String outline : af) {
			fw.write(outline + "\n");
			//System.out.println(outline);
		}

		fw.close();
	}

	private void processArgs(String[] args) throws Exception {

		String arg;

		for (int argc = 0; argc < args.length; argc++) {
			arg = args[argc];
			System.out.print(arg + " ");
		}
		System.out.println();

		if (args.length != 2) {
			System.out.println("usage: " + getProgName() + " <srcfile> <dstFile>");
			System.exit(1);
		}

		setSrcName(args[0]);
		setDstName(args[1]);
	}

	public optimize(String[] args) throws Exception {
		System.out.print("optimize ");
		processArgs(args);
		processFile(getSrcName(), getDstName());

	}

	public static void main(String[] args) throws Exception {
		new optimize(args);
	}

}
