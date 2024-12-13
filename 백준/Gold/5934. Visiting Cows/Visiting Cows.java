import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

class FastIO {
    static final InputStream IN = System.in;
    static final int EOF = -1;

    public static int nextInt() throws IOException {
        int ret = 0;
        int sign = 1;

        while (true) {
            int ascii = IN.read();
            if (ascii == EOF) {
                throw new IOException();
            }
            if (!Character.isWhitespace(ascii)) {
                if (ascii == '-') {
                    sign = -1;
                } else {
                    ret = ascii - '0';
                }
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
        return ret * sign;
    }

    public static long nextLong() throws IOException {
        long ret = 0;
        long sign = 1;

        while (true) {
            int ascii = IN.read();
            if (ascii == EOF) {
                throw new IOException();
            }
            if (!Character.isWhitespace(ascii)) {
                if (ascii == '-') {
                    sign = -1;
                } else {
                    ret = ascii - '0';
                }
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
        return ret * sign;
    }
}

public class Main {
    static final int ROOT = 1;
    static final int SKIPPED = 0;
    static final int SELECTED = 1;

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static List<Integer>[] edges;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        int vCnt = FastIO.nextInt();

        edges = new List[vCnt + 1];
        for (int v = 1; v <= vCnt; v++) {
            edges[v] = new ArrayList<>();
        }

        for (int e = 1; e < vCnt; e++) {
            int from = FastIO.nextInt();
            int to = FastIO.nextInt();

            edges[from].add(to);
            edges[to].add(from);
        }

        dp = new int[vCnt + 1][2];
        dfs(ROOT, 0);

        bw.write(String.valueOf(Math.max(dp[ROOT][SKIPPED], dp[ROOT][SELECTED])));
        bw.flush();
    }

    static void dfs(int cur, int prev) {
        dp[cur][SELECTED] = 1;

        for (int next : edges[cur]) {
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
}
