import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/*
 * BOJ_15486_퇴사 2
 * 
 */
public class BOJ_15486_퇴사_2 {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int[] time = new int[N + 5];
		int[] cost = new int[N + 5];
		int[] dp = new int[N + 5];
		
		// 상담 시간 및 비용 입력
		for (int i = 1; i <= N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			time[i] = Integer.parseInt(st.nextToken());
			cost[i] = Integer.parseInt(st.nextToken());
		}
		
		// 다이나믹 프로그래밍
		for (int i = N; i > 0; i--) {
			if (i + time[i] > N + 1) dp[i] = dp[i + 1];
			else dp[i] = Math.max(dp[i + 1], cost[i] + dp[i + time[i]]);				
		}
		
		// 출력
		System.out.println(dp[1]);
	}
}
