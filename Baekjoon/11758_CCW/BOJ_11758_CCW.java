import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_11758_CCW {
	
	public static class Point{
		int x;
		int y;
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
	}
	
	public static int CCW(Point p[]) {
		int a = p[0].x*p[1].y + p[1].x*p[2].y + p[2].x*p[0].y;
		int b = p[0].y*p[1].x + p[1].y*p[2].x + p[2].y*p[0].x;
		return a - b;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder answer = new StringBuilder();
		StringTokenizer st;
		
		Point[] points = new Point[3];
		for (int i = 0; i < 3; i++) {
			st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			points[i] = new Point(x, y);
		}
		
		int ccw = CCW(points);
		if (ccw > 0) answer.append(1);
		else if (ccw == 0) answer.append(0);
		else answer.append(-1);
		
		System.out.println(answer);
	}
}
