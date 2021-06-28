import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1292_쉽게_푸는_문제 {

    private static final int MAX = 1001;
    private static int[] arr;

    public static void setArr() {
        arr = new int[MAX];
        int idx = 1;

        loop: for (int i = 1; i < MAX; i++) {
            for (int j = 0; j < i; j++, idx++) {
                if (idx >= MAX) break loop;
                arr[idx] = i;
            }
        }
    }

    public static int sumArr(int A, int B) {
        int sum = 0;
        for (int i = A; i <= B; i++) sum += arr[i];
        return sum;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int A = Integer.parseInt(st.nextToken());
        int B = Integer.parseInt(st.nextToken());

        setArr();
        System.out.println(sumArr(A, B));

    }
}
