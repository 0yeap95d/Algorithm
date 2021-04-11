import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_01915_가장_큰_정사각형 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer token = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(token.nextToken());
		int m = Integer.parseInt(token.nextToken());
		
		int[][] dp = new int[n + 1][m + 1];
		for (int i = 0; i < n; i++) {
			char[] map = br.readLine().toCharArray();
			for (int j = 0; j < m; j++) dp[i + 1][j + 1] = map[j] - '0';
		}
		
		int answer = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (dp[i][j] == 0) continue;
				if (dp[i - 1][j - 1] != 0 && dp[i - 1][j] != 0 && dp[i][j - 1] != 0) 
					dp[i][j] = Math.min(dp[i - 1][j - 1], Math.min(dp[i - 1][j], dp[i][j - 1])) + 1;
				answer = Math.max(answer, dp[i][j]);
			}
		}
		
		System.out.println(answer * answer);
	}
}
