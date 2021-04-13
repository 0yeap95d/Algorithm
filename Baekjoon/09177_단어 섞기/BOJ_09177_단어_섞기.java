import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class BOJ_09177_´Ü¾î_¼¯±â {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder answer = new StringBuilder();
		
		int N = Integer.parseInt(br.readLine());
		for (int tc = 1; tc <= N; tc++) {
			StringTokenizer token = new StringTokenizer(br.readLine());
			String[] word = new String[3];
			HashMap<Character, Integer> map = new HashMap<Character, Integer>();
			boolean ans = true;
			
			for (int i = 0; i < 3; i++) {
				word[i] = token.nextToken();
				for (char c : word[i].toCharArray()) {
					if (i == 2) {
						if (map.containsKey(c)) {
							if (map.get(c) - 1 == 0) map.remove(c);
							else map.put(c, map.get(c) - 1);							
						}
						else ans = false;
					}
					else {
						if (map.containsKey(c)) map.put(c, map.get(c) + 1);
						else map.put(c, 1);
					}
				}
			}
						
			answer.append("Data set ").append(tc).append(": ");
			if (ans) answer.append(isPossible(word, new int[] {0, 0, 0}) ? "yes\n" : "no\n");
			else answer.append("no\n");
		}
		
		System.out.println(answer);
	}
	
	public static boolean isPossible(String[] word, int[] idx) {
		if (idx[2] == word[2].length()) return true;
		
		char[] ch = new char[3];
		for (int i = 0; i < 3; i++) {
			if (idx[i] < word[i].length()) ch[i] = word[i].charAt(idx[i]);
		}
				
		if (ch[2] != ch[0] && ch[2] != ch[1]) return false;
		else if (ch[0] == ch[1]) {
			if (idx[0] < word[0].length() && isPossible(word, new int[] {idx[0] + 1, idx[1], idx[2] + 1})) return true;
			if (idx[1] < word[1].length() && isPossible(word, new int[] {idx[0], idx[1] + 1, idx[2] + 1})) return true;
		}
		else if (ch[2] == ch[0]) {
			if (idx[0] == word[0].length()) return false;
			idx[0]++; idx[2]++;
			return isPossible(word, idx);
		}
		else if (ch[2] == ch[1]) {
			if (idx[1] == word[1].length()) return false;
			idx[1]++; idx[2]++;
			return isPossible(word, idx);
		}
		
		return false;
	}
}
