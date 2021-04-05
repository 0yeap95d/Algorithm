import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_07579_¾Û {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		StringTokenizer memToken = new StringTokenizer(br.readLine());
		StringTokenizer costToken = new StringTokenizer(br.readLine());		
		int[] memory = new int[N + 1];
		int[] cost = new int[N + 1];
		int costSum = 0;
		for (int i = 1; i <= N; i++) {
			memory[i] = Integer.parseInt(memToken.nextToken());
			cost[i] = Integer.parseInt(costToken.nextToken());
			costSum = costSum + cost[i];
		}
		
		int[][] dp = new int[N + 1][costSum + 1];
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= costSum; j++) {
				if (j - cost[i] >= 0) dp[i][j] = dp[i - 1][j - cost[i]] + memory[i];
				dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
			}
		}
		
		for (int i = 0; i <= costSum; i++) {
			if (dp[N][i] >= M) {
				System.out.println(i);
				break;
			}
		}
	}
}
