import java.io.FileNotFoundException;
import java.io.IOException;


public class StackMain {

	private static MyStack DIFstack;
	private static MyStack AIKstack;
	private static MyStack HIFstack;
	private static int n;
	private static FileIO fileIO;
	
	public static void main(String[] args) {
		
		AIKstack = new MyStack(100);
		DIFstack = new MyStack(100);
		HIFstack = new MyStack(100);
		
		try {
			fileIO = new FileIO("Namn.dat");
			fileIO.InitReadFile();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		parseFile();
		
		System.out.println("AIK \n" + AIKstack.toString());
		System.out.println("DIF \n" + DIFstack.toString());
		System.out.println("HIF \n" + HIFstack.toString());
		
	}
	
	public static void parseFile() {
		
		try {
			n = Integer.parseInt(fileIO.getNextLine());
		} catch (NumberFormatException e1) {
			e1.printStackTrace();
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		String name;
		String club;
		
		for(int k= 0; k < n; k++) {
			try {
				name = fileIO.getNextLine();
				club = fileIO.getNextLine();
				
				if(club.equals("AIK")) {
					AIKstack.push(name);
				} else if ( club.equals("HIF")) {
					HIFstack.push(name);
				} else if ( club.equals("DIF")) {
					DIFstack.push(name);
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		
	}	

}
