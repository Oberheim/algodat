
public class MyStack {
	
	private String stack[];
	private int plats;
	
	public MyStack(int size) {
		stack = new String[size];
		plats = 0;
	}
	
	public String getLine(int n) { return stack[n]; }
	
	public void push(String t) {
		stack[plats] = t;
		plats++;
	}
	
	public String pop() {
		String t1;
		plats--;
		t1 = stack[plats];
		return t1;
	}
	
	public boolean isEmpty() {
		return (plats<0);
	}
	
	public String toString() {
		String tmp = "";
		for(int z = 0; z < plats; z++) {
			tmp += getLine(z) + "\n";
		}
		return tmp;
	}
}
