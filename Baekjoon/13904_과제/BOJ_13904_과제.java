import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_13904_°úÁ¦ {
	
	public static class Assign{
		int deadline;
		int score;
		public Assign(int deadline, int score) {
			super();
			this.deadline = deadline;
			this.score = score;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int answer = 0;
		
		int N = Integer.parseInt(br.readLine());
		ArrayList<Assign> assignList = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			StringTokenizer token = new StringTokenizer(br.readLine());
			int deadline = Integer.parseInt(token.nextToken());
			int score = Integer.parseInt(token.nextToken());			
			assignList.add(new Assign(deadline, score));
		}
		
		Collections.sort(assignList, new Comparator<Assign>() {
			@Override
			public int compare(Assign a1, Assign a2) {
				if (a1.deadline == a2.deadline) return a1.score - a2.score;
				return a1.deadline - a2.deadline;
			}
		});
		
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		int time = 0;
		for (Assign assign : assignList) {
			int d = assign.deadline;
			int s = assign.score;
			time++;
			
			pq.offer(s);
			if (time > d) {
				pq.poll();
				time--;
			}
		}
		
		while (!pq.isEmpty()) answer = answer + pq.poll();
		System.out.println(answer);
	}
}
