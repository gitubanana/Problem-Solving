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
    static final int ROOT = 0;
    static final int MAX_V = 10_000;
    static final int DIVISOR = 1_000_000_007;

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static List<Integer>[] childs = new List[MAX_V];
    static int[] weights = new int[MAX_V];

    static {
        for (int v = 0; v < MAX_V; v++) {
            childs[v] = new ArrayList<>();
        }
    }

    public static void main(String[] args) throws IOException {
        int testCount = FastIO.nextInt();

        while (testCount-- > 0) {
            int vCnt = FastIO.nextInt();
            if (vCnt == 1) {
                bw.append("1").append(System.lineSeparator());
                continue;
            }

            readEdges(vCnt);
            readWeights(vCnt);
            long output = dfs(ROOT);

            bw.append(((output & 1) == 0) ? "FREAK OUT" : String.valueOf(output % DIVISOR));
            bw.newLine();
        }
        bw.flush();
    }

    static void readEdges(int vCnt) throws IOException {
        for (int v = 0; v < vCnt; v++) {
            childs[v].clear();
        }

        for (int child = 1; child < vCnt; child++) {
            int parent = FastIO.nextInt();

            childs[parent].add(child);
        }
    }

    static void readWeights(int vCnt) throws IOException {
        for (int v = 1; v < vCnt; v++) {
            weights[v] = FastIO.nextInt();
        }
    }

    static long dfs(int cur) {
        if (childs[cur].isEmpty()) {
            return 1;
        }

        long ret = 0;

        for (int child : childs[cur]) {
            ret += dfs(child) * weights[child];
            ret %= (2 * DIVISOR);
        }
        return ret;
    }
}
