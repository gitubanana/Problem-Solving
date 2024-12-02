import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class FastIO {
    static final InputStream IN = System.in;
    static final int EOF = -1;

    public static int nextInt() throws IOException {
        int ret = 0;

        while (true) {
            int ascii = IN.read();
            if (ascii == EOF) {
                throw new IOException();
            }
            if (!Character.isWhitespace(ascii)) {
                ret = ascii - '0';
                break;
            }
        }

        while (true) {
            int ascii = IN.read();
            if (ascii == EOF || Character.isWhitespace(ascii)) {
                break;
            }

            ret = ret * 10 + (ascii - '0');
        }
        return ret;
    }
}

public class Main {
    static final int MAX_V = 1000;

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] dp;
    static int[] parents;
    static boolean[] visited;
    static List<Integer>[] childs;
    static List<Integer> leafNodes = new ArrayList<>(MAX_V);

    public static void main(String[] args) throws Exception {
        int vCnt = FastIO.nextInt();
        int eCnt = FastIO.nextInt();

        dp = new int[vCnt + 1];
        childs = new List[vCnt + 1];
        parents = new int[vCnt + 1];
        for (int v = 1; v <= vCnt; v++) {
            dp[v] = FastIO.nextInt();
            childs[v] = new ArrayList<>();
        }

        while (eCnt-- > 0) {
            int parent = FastIO.nextInt();
            int child = FastIO.nextInt();

            childs[parent].add(child);
            parents[child] = parent;
        }

        visited = new boolean[vCnt + 1];
        for (int v = 1; v <= vCnt; v++) {
            if (visited[v]) {
                continue;
            }

            dfs(v, 0);
        }

        bw.append(String.valueOf(findMin()));
        bw.flush();
    }

    static void dfs(int cur, int addAmount) {
        visited[cur] = true;
        dp[cur] += addAmount;

        if (childs[cur].isEmpty()) { // culminating concept
            leafNodes.add(cur);
            return;
        }

        for (int next : childs[cur]) {
            dfs(next, dp[cur]);
        }
    }

    static int findMin() {
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < leafNodes.size() - 1; i++) {
            for (int j = i + 1; j < leafNodes.size(); j++) {
                min = Math.min(
                        min,
                        calculateDp(leafNodes.get(i), leafNodes.get(j))
                );
            }
        }
        return min;
    }

    static int calculateDp(int a, int b) {
        return dp[a] + dp[b] - findCommon(a, b);
    }

    static int findCommon(int a, int b) {
        Arrays.fill(visited, false);

        while (a != 0) {
            a = parents[a];
            visited[a] = true;
        }

        int lca = 0;
        while (b != 0) {
            b = parents[b];
            if (visited[b]) {
                lca = b;
                break;
            }
        }

        return dp[lca];
    }
}
