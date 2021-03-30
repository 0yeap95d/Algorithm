import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BOJ_01747_소수_팰린드롬 {
	private static final int SIZE = 1000001;
	
	// 팰린드롬 체크
	public static boolean isPalindrome(int N) {
		boolean res = true;
		String number = Integer.toString(N);
		int sp = 0;
		int ep = number.length() - 1;
		
		while (sp < ep) {
			if (number.charAt(sp) != number.charAt(ep)) {
				res = false;
				break;
			}
			sp++; ep--;
		}
		
		return res;
	}
	
	// 소수 판정
	public static int isPrime(int N) {
		int answer = 2;
		boolean[] prime = new boolean[SIZE * 2];

		Arrays.fill(prime, true);
		prime[0] = prime[1] = false;
		
		for (int i = 2; i < SIZE * 2; i++) {
			if (!prime[i]) continue;
			if (i >= N && isPalindrome(i)) {
				answer = i;
				break;
			}
			for (int j = 2; i * j < SIZE * 2; j++) prime[i * j] = false;
		}
		
		return answer;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		System.out.println(isPrime(N));		
	}
}
