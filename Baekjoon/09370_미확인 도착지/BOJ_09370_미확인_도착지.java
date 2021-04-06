import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_09370_미확인_도착지 {
	
	public static class Edge{
		int vertex;
		int weight;
		public Edge(int vertex, int weight) {
			super();
			this.vertex = vertex;
			this.weight = weight;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder answer = new StringBuilder();
		StringTokenizer token;
		
		int TC = Integer.parseInt(br.readLine());
		while (TC-- > 0) {
			token = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(token.nextToken());
			int M = Integer.parseInt(token.nextToken());
			int T = Integer.parseInt(token.nextToken());

			token = new StringTokenizer(br.readLine());
			int S = Integer.parseInt(token.nextToken());
			int G = Integer.parseInt(token.nextToken());
			int H = Integer.parseInt(token.nextToken());
			
			ArrayList<ArrayList<Edge>> adjList = new ArrayList<>();
			for (int i = 0; i <= N; i++) adjList.add(new ArrayList<>());
			
			for (int i = 0; i < M; i++) {
				token = new StringTokenizer(br.readLine());
				int sp = Integer.parseInt(token.nextToken());
				int ep = Integer.parseInt(token.nextToken());
				int weight = Integer.parseInt(token.nextToken()) * 2;
				if ((sp == G && ep == H) || (sp == H && ep == G)) weight--; 
				adjList.get(sp).add(new Edge(ep, weight));
				adjList.get(ep).add(new Edge(sp, weight));
			}
			
			ArrayList<Integer> dests = new ArrayList<>();
			for (int i = 0; i < T; i++) dests.add(Integer.parseInt(br.readLine()));
			Collections.sort(dests);
			
			PriorityQueue<Edge> pq = new PriorityQueue<>(new Comparator<Edge>() {
				@Override
				public int compare(Edge e1, Edge e2) {
					return e1.weight - e2.weight;
				}
			});
			
			boolean[] visited = new boolean[N + 1];
			int[] dist = new int[N + 1];
			Arrays.fill(dist, Integer.MAX_VALUE);
			pq.offer(new Edge(S, 0));
			dist[S] = 0;
			
			while (!pq.isEmpty()) {
				Edge edge = pq.poll();
				int v = edge.vertex;
				int w = edge.weight;
				
				if (visited[v]) continue;
				visited[v] = true;
				
				for (Edge e : adjList.get(v)) {
					int nv = e.vertex;
					int nw = e.weight;
					
					if (visited[nv] || dist[nv] < w + nw) continue;
					dist[nv] = w + nw;
					pq.offer(new Edge(nv, dist[nv]));
				}
			}
			
			for (int idx : dests) {
				if (dist[idx] == Integer.MAX_VALUE || dist[idx] % 2 != 1) continue;
				answer.append(idx).append(" ");
			}
			answer.append("\n");
		}
		
		System.out.println(answer);
	}
}
