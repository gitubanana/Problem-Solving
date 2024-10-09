import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    final static int SKIPPED = 0;
    final static int SELECTED = 1;

    static int[][] dp;
    static int[] weights;
    static ArrayList<Integer>[] edges;
    static ArrayList<Integer> independentSet = new ArrayList<>();

    static void dfs(int cur, int prev) {
        dp[cur][SELECTED] = weights[cur];

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

    static void makeSet(int cur, int prev, boolean isSelected) {
        if (isSelected) {
            independentSet.add(cur);
        }

        for (Integer next : edges[cur]) {
            if (next == prev) {
                continue;
            }

            if (isSelected) {
                makeSet(next, cur, false);
                continue;
            }

            makeSet(next, cur, dp[next][SELECTED] > dp[next][SKIPPED]);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int vCnt = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        weights = new int[vCnt + 1];
        edges = new ArrayList[vCnt + 1];
        for (int v = 1; v <= vCnt; ++v) {
            weights[v] = Integer.parseInt(st.nextToken());
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
        makeSet(1, 0, dp[1][SELECTED] > dp[1][SKIPPED]);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.append(Math.max(dp[1][SELECTED], dp[1][SKIPPED])+"\n");
        independentSet.sort(Comparator.naturalOrder());
        for (Integer elem : independentSet) {
            bw.append(elem+" ");
        }

        bw.flush();
    }
}
