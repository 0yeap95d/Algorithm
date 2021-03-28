import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_05430_AC {
	
	public static class Deque {
		int front;
		int rear;
		int[] arr;
		
		Deque(int length) {
			this.front = 0;
			this.rear = 0;
			this.arr = new int[length];
		}
		
		public void offer(int value) {
			this.arr[rear++] = value;
		}
		
		public void pollFirst() {
			this.front++;
		}
		
		public void pollLast() {
			this.rear--;
		}
		
		public int length() {
			return rear - front;
		}
		
		public String toString(boolean isReverse) {
			StringBuilder res = new StringBuilder("[");
			if (isReverse) {	// 역방향
				for (int i = rear - 1; i >= front; i--) {
					res.append(arr[i]);
					if (i != front) res.append(",");
				}
			} else {	// 정방향
				for (int i = front; i < rear; i++) {
					res.append(arr[i]);
					if (i != rear - 1) res.append(",");
				}
			}
			return res.append("]").toString();
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder answer = new StringBuilder();
		
		int testcase = Integer.parseInt(br.readLine());
		while (testcase-- > 0) {
			String p = br.readLine();
			int n = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine().replace("[", "").replace("]", ""), ",");
			
			Deque deque = new Deque(n);
			while(st.hasMoreTokens()) deque.offer(Integer.parseInt(st.nextToken()));
			
			boolean isReverse = false;
			String res = new String();
			for (char ch : p.toCharArray()) {
				if (ch == 'R') isReverse = !isReverse;
				else {
					if (deque.length() == 0) {
						res = "error";
						break;
					} else {
						if (isReverse) deque.pollLast();
						else deque.pollFirst();
					}
				}
			}
			if (!res.equals("error")) res = deque.toString(isReverse);
			
			answer.append(res).append("\n");
		}
		
		System.out.println(answer);
	}
}
