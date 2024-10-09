import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    final static int SKIPPED = 0;
    final static int SELECTED = 1;

    static int[][] dp;
    static int[] people;
    static ArrayList<Integer>[] edges;

    static void dfs(int cur, int prev) {
        dp[cur][SELECTED] = people[cur];

        for (Integer next : edges[cur]) {
            if (next == prev) {
                continue;
            }

            dfs(next, cur);
            dp[cur][SELECTED] += dp[next][SKIPPED];
            dp[cur][SKIPPED] += Math.max(
                    dp[next][SKIPPED],
                    dp[next][SELECTED]
            );
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int vCnt = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        people = new int[vCnt + 1];
        edges = new ArrayList[vCnt + 1];
        for (int v = 1; v <= vCnt; ++v) {
            people[v] = Integer.parseInt(st.nextToken());
            edges[v] = new ArrayList<>();
        }

        for (int e = 1; e < vCnt; ++e) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            edges[from].add(to);
            edges[to].add(from);
        }

        dp = new int[vCnt + 1][2];
        dfs(1, 0);
        System.out.println(Math.max(dp[1][SELECTED], dp[1][SKIPPED]));
    }
}
