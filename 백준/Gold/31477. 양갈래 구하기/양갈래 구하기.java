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

class Edge {
    int v;
    int w;

    Edge(int v, int w) {
        this.v = v;
        this.w = w;
    }
}

public class Main {
    static final int ROOT = 1;

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static List<Edge>[] edges;

    public static void main(String[] args) throws IOException {
        int vCnt = FastIO.nextInt();

        edges = new List[vCnt + 1];
        for (int v = 1; v <= vCnt; v++) {
            edges[v] = new ArrayList<>();
        }

        for (int e = 1; e < vCnt; e++) {
            int from = FastIO.nextInt();
            int to = FastIO.nextInt();
            int weight = FastIO.nextInt();

            edges[from].add(new Edge(to, weight));
            edges[to].add(new Edge(from, weight));
        }

        bw.write(String.valueOf(dfs(ROOT, 0)));
        bw.flush();
    }

    static int dfs(int cur, int prev) {
        int ret = 0;

        for (Edge next : edges[cur]) {
            if (next.v == prev) {
                continue;
            }

            ret += Math.min(
                    next.w,
                    dfs(next.v, cur)
            );
        }
        return ret == 0 ? Integer.MAX_VALUE : ret;
    }
}
