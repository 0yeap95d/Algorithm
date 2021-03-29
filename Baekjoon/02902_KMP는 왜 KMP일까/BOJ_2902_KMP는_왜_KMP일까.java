import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * BOJ_2902_KMP�� �� KMP�ϱ�?
 */

public class BOJ_2902_KMP��_��_KMP�ϱ� {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder answer = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine(), "-");
		
		while(st.hasMoreTokens()) answer.append(st.nextToken().charAt(0));
		System.out.println(answer);
	}
}
