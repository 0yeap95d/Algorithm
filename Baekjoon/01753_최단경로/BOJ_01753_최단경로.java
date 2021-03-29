package ref;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BOJ_01753_최단경로 {
	
	public static class Edge {
		int v1;
		int v2;
		int weight;
		
		Edge() {}
		Edge(int v1, int v2, int weight) {
			this.v1 = v1;
			this.v2 = v2;
			this.weight = weight;
		}
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int V = Integer.parseInt(st.nextToken());
		int E = Integer.parseInt(st.nextToken());
		int start = Integer.parseInt(br.readLine());
		
		ArrayList<ArrayList<Edge>> list = new ArrayList<ArrayList<Edge>>();
		for (int i = 0; i < V + 1; i++) list.add(new ArrayList<Edge>());
		
		for (int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			int v1 = Integer.parseInt(st.nextToken());
			int v2 = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			list.get(v1).add(new Edge(v1, v2, w));
		}
		
		int[] ans = new int[V + 1];
		for (int i = 0; i < V + 1; i++) ans[i] = Integer.MAX_VALUE;
		ans[start] = 0;
		
		
		PriorityQueue<Edge> pq = new PriorityQueue<>(new Comparator<Edge>() {
			@Override
			public int compare(Edge o1, Edge o2) {
				return o1.weight > o2.weight ? 1 : -1;
			}
		});
		for (Edge e : list.get(start)) pq.offer(e);
		
		
		while(!pq.isEmpty()) {
			Edge edge = pq.poll();
			if (ans[edge.v2] > edge.weight) {
				ans[edge.v2] = edge.weight;
				for (Edge e : list.get(edge.v2)) pq.offer(new Edge(e.v1, e.v2, edge.weight + e.weight));				
			}
		}
		
		for (int i = 1; i <= V; i++) {
			if (ans[i] == Integer.MAX_VALUE) sb.append("INF\n");
			else sb.append(ans[i] + "\n");
		}
		
		System.out.println(sb);
	}
}
