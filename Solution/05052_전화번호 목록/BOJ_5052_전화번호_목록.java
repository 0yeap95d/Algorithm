import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;

public class BOJ_5052_��ȭ��ȣ_��� {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder answer = new StringBuilder();
		
		int testcase = Integer.parseInt(br.readLine());
		
		while(testcase-- > 0) {
			HashSet<String> set = new HashSet<>();
			int n = Integer.parseInt(br.readLine());
			boolean isAns = true;
			ArrayList<String> list = new ArrayList<>();
			
			// ��ȭ��ȣ �Է� & ����
			for (int i = 0; i < n; i++) list.add(br.readLine());
			Collections.sort(list);
			
			// Set�� �̿��Ͽ� ���ξ� ���� ���� �Ǵ�
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
