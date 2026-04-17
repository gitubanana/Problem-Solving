import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCnt = Integer.parseInt(br.readLine());
        StringBuilder result = new StringBuilder();

        for (int t = 0; t < testCnt; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int size = Integer.parseInt(st.nextToken());
            int knapsackSize = Integer.parseInt(st.nextToken());
            int[] weights = new int[size + 1];
            int[] values = new int[size + 1];

            for (int i = 1; i <= size; i++) {
                st = new StringTokenizer(br.readLine());
                weights[i] = Integer.parseInt(st.nextToken());
                values[i] = Integer.parseInt(st.nextToken());
            }

            int[][] dp = new int[size + 1][knapsackSize + 1];
            for (int i = 1; i <= size; i++) {
                for (int w = 1; w <= knapsackSize; w++) {
                    if (w >= weights[i]) {
                        dp[i][w] = Math.max(dp[i - 1][w], values[i] + dp[i - 1][w - weights[i]]);
                    } else {
                        dp[i][w] = dp[i - 1][w];
                    }
                }
            }

            result.append(dp[size][knapsackSize]).append('\n');
        }

        System.out.println(result);
    }
}
