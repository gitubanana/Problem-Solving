import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
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
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int vCnt;
    static List<Integer>[] edges;
    static List<Integer> maxDisconnectedSizes;
    static int maxDisconnectedPairCount = Integer.MIN_VALUE;

    public static void main(String[] args) throws Exception {
        vCnt = FastIO.nextInt() + 1;

        edges = new List[vCnt];
        for (int v = 0; v < vCnt; v++) {
            edges[v] = new ArrayList<>();
        }

        for (int e = 1; e < vCnt; e++) {
            int from = FastIO.nextInt();
            int to = FastIO.nextInt();

            edges[from].add(to);
            edges[to].add(from);
        }

        dfs(0, -1);

        bw.append(String.valueOf(maxDisconnectedPairCount)).append(" ");
        bw.append(String.valueOf(calculateDisconnectedPairCountAfterAddingBestLine()));

        bw.flush();
    }

    static int dfs(int cur, int prev) {
        int totalConnectedSize = 1;
        List<Integer> disconnectedSizes = new ArrayList<>(edges[cur].size());

        for (int next : edges[cur]) {
            if (next == prev) {
                continue;
            }

            int nextConnectedSize = dfs(next, cur);

            disconnectedSizes.add(nextConnectedSize);
            totalConnectedSize += nextConnectedSize;
        }
        disconnectedSizes.add(vCnt - totalConnectedSize);

        int disconnectedPairCount = calculatePairCount(disconnectedSizes);
        if (maxDisconnectedPairCount < disconnectedPairCount) {
            maxDisconnectedPairCount = disconnectedPairCount;
            maxDisconnectedSizes = disconnectedSizes;
        }
        return totalConnectedSize;
    }

    static int calculatePairCount(List<Integer> numbers) {
        int pairCount = 0;

        for (int i = 0; i < numbers.size() - 1; i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                pairCount += numbers.get(i) * numbers.get(j);
            }
        }
        return pairCount;
    }

    static int calculateDisconnectedPairCountAfterAddingBestLine() {
        if (maxDisconnectedSizes.size() <= 2) {
            return 0;
        }

        maxDisconnectedSizes.sort(Comparator.reverseOrder());
        int addAmount = maxDisconnectedSizes.remove(0);
        maxDisconnectedSizes.set(0, maxDisconnectedSizes.get(0) + addAmount);

        return calculatePairCount(maxDisconnectedSizes);
    }
}
