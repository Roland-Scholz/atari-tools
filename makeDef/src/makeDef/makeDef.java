package makeDef;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Set;

public class makeDef {

	private String progName = "makeDef";
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

	private void processFile(String srcName, String dstName) throws Exception {

		BufferedReader fin = new BufferedReader(new FileReader(new File(srcName)));
		FileWriter fw = new FileWriter(dstName);

		String line;
		String mnem;
		String func = null;
		String words[];

		line = fin.readLine();

		while (line != null) {
			words = line.split("\\s+");
			if (words.length > 2) {
				if (words[1].equals("CALL")) {
					// System.out.println(words[1] + " * " + words[2]);
					fw.write(words[2] + "\n");
				}
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

		if (args.length != 2) {
			System.out.println("usage: " + getProgName() + " <srcfile> <dstFile>");
			System.exit(1);
		}

		setSrcName(args[0]);
		setDstName(args[1]);

	}

	public makeDef(String[] args) throws Exception {
		System.out.print(getProgName());
		processArgs(args);
		processFile(getSrcName(), getDstName());
	}

	public static void main(String[] args) throws Exception {
		new makeDef(args);
	}

}
