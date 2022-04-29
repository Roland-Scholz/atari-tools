package codeAdjust;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Set;

public class codeAdjust {

	private String progName = "codeAdjust";
	private String srcName;
	private String dstName;
	private String defName;
	private Set<String> functions = new HashSet<String>();

	public String getDefName() {
		return defName;
	}

	public void setDefName(String defName) {
		this.defName = defName;
	}

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

	private void processDef(String defFileName) throws Exception {

		String line;
		BufferedReader fin = new BufferedReader(new FileReader(new File(defFileName)));

		line = fin.readLine();
		while (line != null) {

			if (line.indexOf("~~") == 0) {
				// System.out.println(line);
				functions.add(line.trim() + ":");
			}

			line = fin.readLine();
		}

		fin.close();
	}

	private void processFile(String srcName, String dstName) throws Exception {

		BufferedReader fin = new BufferedReader(new FileReader(new File(srcName)));
		FileWriter fw = new FileWriter(dstName);

		String line;
		String mnem;
		String func = null;

		line = fin.readLine();

		while (line != null) {
			line = line + "\n";
			mnem = line.trim();
			if (mnem.indexOf("~~") == 0) {
				func = mnem;
			}

			if (mnem.equals("phd")) {
				fw.write(line);
				// System.out.println(line);
				if (functions.contains(func)) {
					fw.write("        " + "phb\n");
					fw.write("        " + "phk\n");
					fw.write("        " + "plb\n");
				}
			} else if (mnem.equals("pld")) {
				if (functions.contains(func)) {
					fw.write("        " + "plb\n");
				}
				fw.write(line);
			} else {
				fw.write(line);
			}

			line = fin.readLine();
		}
		fin.close();
		fw.close();
	}

	private void processArgs(String[] args) throws Exception {

		String arg;

		for (int argc = 0; argc < args.length; argc++) {
			arg = args[argc];
			System.out.print(arg + " ");
		}
		System.out.println();

		if (args.length != 3) {
			System.out.println("usage: " + getProgName() + " <srcfile> <dstFile> <defFile>");
			System.exit(1);
		}

		setSrcName(args[0]);
		setDstName(args[1]);
		setDefName(args[2]);

	}

	public codeAdjust(String[] args) throws Exception {
		System.out.print("codeAdjust ");
		processArgs(args);
		processDef(getDefName());
		processFile(getSrcName(), getDstName());
	}

	public static void main(String[] args) throws Exception {
		new codeAdjust(args);
	}

}
