import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

class Edge {
    int v;
    int w;

    public Edge(int v, int w) {
        this.v = v;
        this.w = w;
    }
}

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
    static final int MAX_V = 1_000;

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static List<Edge>[] edges = new List[MAX_V + 1];

    static {
        for (int v = 1; v <= MAX_V; v++) {
            edges[v] = new ArrayList<>(MAX_V);
        }
    }

    public static void main(String[] args) throws Exception {
        try {
            while (true) {
                int vCnt = FastIO.nextInt();
                int root = FastIO.nextInt();

                initEdges(vCnt);
                bw.append(String.valueOf(dfs(root, 0)));
                bw.append(System.lineSeparator());
            }
        } catch (IOException e) {
            bw.flush();
        }
    }

    static void initEdges(int vCnt) throws Exception {
        for (int v = 1; v <= vCnt; v++) {
            edges[v].clear();
        }

        for (int e = 1; e < vCnt; e++) {
            int from = FastIO.nextInt();
            int to = FastIO.nextInt();
            int w = FastIO.nextInt();

            edges[from].add(new Edge(to, w));
            edges[to].add(new Edge(from, w));
        }
    }

    static int dfs(int cur, int prev) {
        int totalWeight = 0;

        for (Edge next : edges[cur]) {
            if (next.v == prev) {
                continue;
            }

            totalWeight += Math.min(
                    next.w,
                    dfs(next.v, cur)
            );
        }
        return totalWeight == 0 ? Integer.MAX_VALUE : totalWeight;
    }
}
