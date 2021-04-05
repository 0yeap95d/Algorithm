import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ_03197_백조의_호수 {
	
	private static final int[] dx = {0, 0, -1, 1};
	private static final int[] dy = {-1, 1, 0, 0};
	private static int[] root;

	public static class Position {
		int x;
		int y;
		public Position(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		int R = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		
		char[][] inp = new char[R][C];
		int[][] Lake = new int[R][C];
		
		
		for (int i = 0; i < R; i++) {
			inp[i] = br.readLine().toCharArray();
			for (int j = 0; j < C; j++) {
				if (inp[i][j] == 'X') Lake[i][j] = -1;
				else if (inp[i][j] == 'L') Lake[i][j] = -2;			
				else Lake[i][j] = 0;
			}
		}
		
		int[] swans = new int[2];
		boolean[][] visited = new boolean[R][C];
		ArrayList<Position> delList = new ArrayList<>();
		
		int number = setInfo(Lake, R, C, delList, swans, visited);
		root = new int[number + 1];
		makeSet(number);
		
		int answer = 0;
		while (Find(swans[0]) != Find(swans[1])) {
			delIce(Lake, delList, visited);
			answer++;
		}
		
		System.out.println(answer);
	}
	
	public static void makeSet(int size) {
		for (int i = 0; i <= size; i++) {
			root[i] = i;
		}		
	}
	
	public static int Find(int x) {
		if (root[x] == x) return x;
		return root[x] = Find(root[x]);
	}
	
	public static void Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		if (x != y) root[x] = y;
		return;
	}
	
	public static void delIce(int[][] Lake, ArrayList<Position> delList, boolean[][] visited) {
		ArrayList<Position> temp = new ArrayList<>(delList);
		delList.clear();
		
		for (Position pos : temp) {
			ArrayList<Integer> around = new ArrayList<>();
			for (int i = 0; i < 4; i++) {
				try {
					int nx = pos.x + dx[i];
					int ny = pos.y + dy[i];
					if (Lake[nx][ny] == -1) {
						if (visited[nx][ny]) continue;
						delList.add(new Position(nx, ny));
						visited[nx][ny] = true;
					}
					else {
						around.add(Lake[nx][ny]);
					}	
				} catch (Exception e) {
					continue;
				}
			}
			
			Lake[pos.x][pos.y] = around.get(0);
			for (int num : around) Union(around.get(0), num);
		}
	}
	
	public static int setInfo(int[][] Lake, int R, int C, ArrayList<Position> delList, int[] swans, boolean[][] visited) {
			
		Queue<Position> que = new LinkedList<>();
		int number = 1;
		
		for (int r = 0; r < R; r++) {
			for (int c = 0; c < C; c++) {
				if (visited[r][c] || Lake[r][c] == -1) continue;
				
				que.offer(new Position(r, c));
				visited[r][c] = true;
				
				while (!que.isEmpty()) {
					Position pos = que.poll();
					if (Lake[pos.x][pos.y] == -2) {
						if (swans[0] == 0) swans[0] = number;
						else swans[1] = number;
					}
					Lake[pos.x][pos.y] = number;
					
					for (int i = 0; i < 4; i++) {						
						try {
							int nx = pos.x + dx[i];
							int ny = pos.y + dy[i];
							if (visited[nx][ny]) continue;
							if (Lake[nx][ny] == -1) {
								delList.add(new Position(nx, ny));
								visited[nx][ny] = true;
								continue;
							}
							que.offer(new Position(nx, ny));
							visited[nx][ny] = true;
						} catch (Exception e) {
							continue;
						}
					}
				}
				
				number++;
			}
		}
		
		return number;
	}
}
