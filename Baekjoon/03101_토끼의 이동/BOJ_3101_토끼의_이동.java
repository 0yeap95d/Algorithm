import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_3101_≈‰≥¢¿«_¿Ãµø {
	
	private static final int[] dx = { -1, 1, 0, 0 };
	private static final int[] dy = { 0, 0, -1, 1 };
	private static final char[] direction = { 'U', 'D', 'L', 'R' };
	
	public static long getScore(long x, long y, long size) {
		long sum = x + y;
		if (sum < size) {	// ªÔ∞¢«¸ ¿≠ ∫Œ∫–
			long n = sum;
			long sp = 1 + (1 + n) * n / 2;
			if (n % 2 == 0) return sp + y;	// x¡¬«•øÕ y¡¬«•¿« «’¿Ã ¬¶ºˆ¿Œ ∞ÊøÏ
			else return sp + x;				// x¡¬«•øÕ y¡¬«•¿« «’¿Ã »¶ºˆ¿Œ ∞ÊøÏ
		}
		else {	// ªÔ∞¢«¸ æ∆∑ß ∫Œ∫–
			long n = (size - 1) + (size - 1) - sum;
			long ep = size * size - ((1 + n) * n / 2);
			if (n % 2 == 0) return ep - (size - 1 - y);
			else return ep - (size - 1 - x);		
		}
	}
	
	public static int getDirNum(char dir) {
		for (int i = 0; i < 4; i++) 
			if (dir == direction[i]) return i;
		return 0;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		String dirList = br.readLine();
		
		long answer = 1;
		int x = 0, y = 0;
		for (char dir : dirList.toCharArray()) {
			int dirNum = getDirNum(dir);
			x = x + dx[dirNum]; y = y + dy[dirNum];
			answer = answer + getScore(x, y, N);
		}
		
		System.out.println(answer);
	}
}
