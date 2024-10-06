import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    public enum Status {
        SKIPPED(0),
        SELECTED(1);


        private int idx;

        private Status(int idx) {
            this.idx = idx;
        }

        public int getIdx() {
            return this.idx;
        }
    }

    static ArrayList<Integer>[] edges;
    static int dp[][];

    static void dfs(int cur, int prev) {
        dp[cur][Status.SKIPPED.getIdx()] = 0;
        dp[cur][Status.SELECTED.getIdx()] = 1;

        for (Integer next : edges[cur]) {
            if (next == prev) {
                continue;
            }

            dfs(next, cur);
            dp[cur][Status.SKIPPED.getIdx()] += dp[next][Status.SELECTED.getIdx()];
            dp[cur][Status.SELECTED.getIdx()] += Math.min(
                    dp[next][Status.SKIPPED.getIdx()],
                    dp[next][Status.SELECTED.getIdx()]
            );
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int vCnt = Integer.parseInt(br.readLine());

        edges = new ArrayList[vCnt + 1];
        for (int v = 1; v <= vCnt; ++v) {
            edges[v] = new ArrayList<>();
        }
        for (int e = 1; e < vCnt; ++e) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            edges[a].add(b);
            edges[b].add(a);
        }

        dp = new int[vCnt + 1][2];
        dfs(1, 0);

        System.out.println(Math.min(dp[1][0], dp[1][1]));
    }
}