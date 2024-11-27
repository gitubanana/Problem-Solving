import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] arr;
    static int[] dp;

    public static void main(String[] args) throws Exception {
        int size = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        arr = new int[size];
        dp = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int maxDp = 0;
        for (int i = 0; i < size; i++) {
            maxDp = Math.max(maxDp, dfs(i));
        }

        bw.append(String.valueOf(maxDp));
        bw.flush();
    }

    static int dfs(int index) {
        if (dp[index] != 0) {
            return dp[index];
        }

        int nextNumber = arr[index] + 1;

        dp[index] = 1;
        for (int nextIndex = index + 1; nextIndex < arr.length; nextIndex++) {
            if (nextNumber == arr[nextIndex]) {
                dp[index] += dfs(nextIndex);
                break;
            }
        }
        return dp[index];
    }
}
