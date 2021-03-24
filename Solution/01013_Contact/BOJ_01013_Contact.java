import java.io.*;

public class BOJ_01013_Contact {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int testCase = Integer.parseInt(br.readLine());
		while (testCase-- > 0) System.out.println(br.readLine().matches("(100+1+|01)+") ? "YES" : "NO");
	}
}
