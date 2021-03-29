import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * BOJ_2902_KMP는 왜 KMP일까?
 */

public class BOJ_2902_KMP는_왜_KMP일까 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder answer = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine(), "-");
		
		while(st.hasMoreTokens()) answer.append(st.nextToken().charAt(0));
		System.out.println(answer);
	}
}
