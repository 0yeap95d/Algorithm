import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;

public class BOJ_5052_전화번호_목록 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder answer = new StringBuilder();
		
		int testcase = Integer.parseInt(br.readLine());
		
		while(testcase-- > 0) {
			HashSet<String> set = new HashSet<>();
			int n = Integer.parseInt(br.readLine());
			boolean isAns = true;
			ArrayList<String> list = new ArrayList<>();
			
			// 전화번호 입력 & 정렬
			for (int i = 0; i < n; i++) list.add(br.readLine());
			Collections.sort(list);
			
			// Set을 이용하여 접두어 존재 여부 판단
			for (String nums : list) {
				StringBuilder sb = new StringBuilder();
				if (isAns) {					
					for (char num : nums.toCharArray()) {
						sb.append(num);
						if (set.contains(sb.toString())) {
							isAns = false;
							break;
						}
					}
					if (isAns) set.add(nums);
				}
			}
			
			if (isAns) answer.append("YES\n");
			else answer.append("NO\n");
		}
		
		System.out.println(answer);
	}
}
