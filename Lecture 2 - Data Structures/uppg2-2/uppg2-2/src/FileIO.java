import java.io.*;

public class FileIO {
	
	private String fileName;
	private String strLine;
	private String entireString;
	private BufferedReader br;
	private DataInputStream in;
	private FileInputStream fstream;
	
	public FileIO(String fileName) {
		this.fileName = fileName;
//		entireString = new String("");
		
	}
	
	public void InitReadFile() throws FileNotFoundException {
		fstream = new FileInputStream(fileName);
		in = new DataInputStream(fstream);
		br = new BufferedReader(new InputStreamReader(in));
	}
	
	public String getEntireText() throws IOException {
		while((strLine = br.readLine()) != null) {
			entireString += strLine + "\n";
		}
		
		in.close();
		
		return entireString;
	}
	public String getNextLine() throws IOException {
			return strLine = br.readLine();
	}
	
	
	
}
