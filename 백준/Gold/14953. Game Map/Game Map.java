import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static final int NOT_VISITED = -1;

    static int[] dp;
    static List<Integer>[] edges;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int vCnt = Integer.parseInt(st.nextToken());
        int eCnt = Integer.parseInt(st.nextToken());

        dp = new int[vCnt];
        edges = new List[vCnt];
        for (int v = 0; v < vCnt; v++) {
            dp[v] = NOT_VISITED;
            edges[v] = new ArrayList<>();
        }

        for (int e = 0; e < eCnt; e++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            edges[a].add(b); // auto boxing
            edges[b].add(a);
        }

        int ans = 0;
        for (int v = 0; v < vCnt; v++) {
            ans = Math.max(ans, dfs(v));
        }
        System.out.println(ans);
    }

    static int dfs(int cur) {
        if (dp[cur] != NOT_VISITED) {
            return dp[cur];
        }

        dp[cur] = 1;
        for (Integer next : edges[cur]) {
            if (edges[next].size() <= edges[cur].size()) {
                continue;
            }

            dp[cur] = Math.max(dp[cur], dfs(next) + 1);
        }
        return dp[cur];
    }
}
