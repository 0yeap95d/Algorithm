import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_12871_무한_문자열 {
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		String s = br.readLine();
		String t = br.readLine();
		
		String fs = s, ft = t;
		while(fs.length() != ft.length()) {
			if (fs.length() > ft.length()) ft = ft + t;
			else if (fs.length() < ft.length()) fs = fs + s;
		}
		
		if (fs.equals(ft)) sb.append(1);
		else sb.append(0);
		
		System.out.println(sb);
	}
}
