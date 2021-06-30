import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

/*
 * BOJ_14719_빗물
 */
public class BOJ_14719_빗물 {
	
	public static class Block {
		int pos;
		int height;
		
		Block (int pos, int height) {
			this.pos = pos;
			this.height = height;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer token = new StringTokenizer(br.readLine());
		
		int answer = 0;
		int H = Integer.parseInt(token.nextToken());
		int W = Integer.parseInt(token.nextToken());
		token = new StringTokenizer(br.readLine());
		
		Stack<Block> stack = new Stack<Block>();
		int maxHeight = 0;	// stack에서 최대 높이 저장
		
		for (int i = 0; i < W; i++) {
			Block next = new Block(i, Integer.parseInt(token.nextToken()));
			while (!stack.isEmpty()) {
				Block pre = stack.peek();
				if (pre.height > next.height) break;
				answer += (Math.min(maxHeight, next.height) - pre.height) * (next.pos - pre.pos);
				next.pos = pre.pos;
				stack.pop();
			}
			maxHeight = Math.max(maxHeight, next.height);
			stack.add(next);
		}
		
		System.out.println(answer);
	}
}
