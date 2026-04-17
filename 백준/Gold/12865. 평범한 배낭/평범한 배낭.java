import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = new StringTokenizer("");

    static int nextInt() throws IOException {
        if (!st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine());
        }
        return Integer.parseInt(st.nextToken());
    }

    public static void main(String[] args) throws IOException {
        int size = nextInt();
        int knapsack = nextInt();
        int[] weights = new int[size + 1];
        int[] values = new int[size + 1];

        for (int i = 1; i <= size; i++) {
            weights[i] = nextInt();
            values[i] = nextInt();
        }

        int[] dp = new int[knapsack + 1];
        for (int i = 1; i <= size; i++) {
            for (int w = knapsack; w >= weights[i]; w--) {
                dp[w] = Math.max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }

        System.out.println(dp[knapsack]);
    }
}
