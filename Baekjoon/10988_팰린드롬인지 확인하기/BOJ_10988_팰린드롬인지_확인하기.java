import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_10988_�Ӹ��������_Ȯ���ϱ� {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str = br.readLine();
		System.out.println(str.contentEquals(new StringBuilder(str).reverse()) ? 1 : 0);
	}
}
