import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_2234_성곽 {
	private static final int[] dx = {0, -1, 0, 1};
	private static final int[] dy = {-1, 0, 1, 0};
	
	public static class Catsle {
		int x;
		int y;
		int wall;
		int number;
		
		public Catsle() {

		}
		
		public Catsle(int x, int y, int wall) {
			super();
			this.x = x;
			this.y = y;
			this.wall = wall;
			this.number = 0;
		}
	}
	
	public static int countRoom(int n, int m, Catsle[][] catsle, ArrayList<Integer> areas) {
		int result = 0;
		int num = 1;
		Queue<Catsle> que = new LinkedList<>();
		areas.add(0);
		
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				if (catsle[x][y].number != 0) continue;
				
				int cnt = 1;
				catsle[x][y].number = num;
				que.offer(catsle[x][y]);
				
				while(!que.isEmpty()) {
					Catsle cs = que.poll();
					for (int dir = 0; dir < 4; dir++) {
						if ((cs.wall & 1 << dir) > 0) continue;
						try {
							int nx = cs.x + dx[dir];
							int ny = cs.y + dy[dir];
							if (catsle[nx][ny].number != 0) continue;
							cnt++;
							catsle[nx][ny].number = num;
							que.offer(catsle[nx][ny]);
						} catch (Exception e) {
							continue;
						}
					}
				}
				num++;
				areas.add(cnt);
			}
		}
		result = areas.size() - 1;
		return result;
	}
	
	public static int getMaxArea(ArrayList<Integer> areas) {
		int result = 0;
		for (int area : areas) result = Math.max(result, area);
		return result;
	}
	
	public static int getDelWallArea(int n, int m, Catsle[][] catsle, ArrayList<Integer> areas) {
		int result = 0;
		
		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				for (int dir = 0; dir < 4; dir++) {
					try {
						int nx = x + dx[dir];
						int ny = y + dy[dir];
						int num1 = catsle[x][y].number;
						int num2 = catsle[nx][ny].number;
						
						if (num1 == num2) continue;
						result = Math.max(result, areas.get(num1) + areas.get(num2));		
					} catch (Exception e) {
						continue;
					}
				}
			}
		}
			
		return result;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder answer = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		Catsle[][] catsle = new Catsle[n][m];
		ArrayList<Integer> areas = new ArrayList<>();
		
		// 성곽 입력
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < m; j++) {
				catsle[i][j] = new Catsle(i, j, Integer.parseInt(st.nextToken()));
			}
		}
		
		// 방의 개수 구하기 (각 구역마다 넘버링)
		answer.append(countRoom(n, m, catsle, areas)).append("\n");
		
		// 가장 넓은 방의 넓이
		answer.append(getMaxArea(areas)).append("\n");
		
		// 하나의 벽을 제거하고 얻을 수 있는 가장 넓은 방의 크기
		answer.append(getDelWallArea(n, m, catsle, areas)).append("\n");
		
		System.out.println(answer.toString());
	}
}
