import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_16916_부분_문자열 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println(KMP(br.readLine(), br.readLine()) ? 1 : 0);
	}
	
	public static boolean KMP(String str, String pattern) {
		int lenStr = str.length();
		int lenPattern = pattern.length();
		int[] pi = getPi(str, pattern);
		
		int idx = 0;
		for (int pos = 0; pos < lenStr; pos++) {
			while (idx > 0 && pattern.charAt(idx) != str.charAt(pos)) idx = pi[idx - 1];
			if (pattern.charAt(idx) == str.charAt(pos)) {
				if (idx == lenPattern - 1) return true;
				else idx++;
			}
		}
		
		return false;
	}
	
	public static int[] getPi(String str, String pattern) {
		int len = pattern.length();
		int[] pi = new int[len];
		char[] p = pattern.toCharArray();
		
		int idx = 0;
		for (int pos = 1; pos < len; pos++) {
			while (idx > 0 && p[pos] != p[idx]) idx = pi[idx - 1];
			if (p[idx] == p[pos]) pi[pos] = ++idx;
		}
		
		return pi;
	}
}
