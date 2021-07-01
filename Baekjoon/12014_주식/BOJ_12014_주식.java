import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

/*
 * BOJ_12014_주식
 */
public class BOJ_12014_주식 {
	
	// Lower Bound
	public static int lowerBound(ArrayList<Integer> arr, int value) {
		int start = 0;
		int end = arr.size();
		
		while(start < end) {
			int mid = (start + end) / 2;
			if (arr.get(mid) >= value) end = mid;
			else start = mid + 1;
		}
		
		return end;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int TC = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= TC; tc++) {
			int answer = 0;
			StringTokenizer token = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(token.nextToken());
			int K = Integer.parseInt(token.nextToken());

			ArrayList<Integer> arr = new ArrayList<>();
			token = new StringTokenizer(br.readLine());
			for (int i = 0; i < N; i++) {
				int value = Integer.parseInt(token.nextToken());
				int idx = lowerBound(arr, value);
				if (idx >= arr.size()) arr.add(value);
				else arr.set(idx, value);
				
				if (arr.size() >= K) { // K개를 살 수 있는 경우 
					answer = 1;
					break;
				}
			}
			
			sb.append("Case #").append(tc).append("\n").append(answer).append("\n");
		}
		System.out.println(sb.toString());
	}
}