import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static List<Integer>[] edges;
    static List<Integer> cutNodes = new ArrayList<>();
    static int vCnt;
    static int halfVcnt;

    public static void main(String[] args) throws Exception {
        vCnt = Integer.parseInt(br.readLine());
        halfVcnt = vCnt / 2;
        edges = new List[vCnt + 1];
        for (int v = 1; v <= vCnt; v++) {
            edges[v] = new ArrayList<>();
        }

        for (int e = 1; e < vCnt; e++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            edges[from].add(to);
            edges[to].add(from);
        }

        dfs(1, 0);

        StringBuilder result = new StringBuilder();
        if (cutNodes.isEmpty()) {
            result.append("NONE");
        } else {
            cutNodes.sort(Comparator.naturalOrder());
            cutNodes.forEach(node -> result.append(node).append(System.lineSeparator()));
        }

        bw.append(result);
        bw.flush();
    }

    static int dfs(int cur, int prev) {
        int linkedNodeCount = 1;
        boolean isCutNodeForChild = true;

        for (int next : edges[cur]) {
            if (next == prev) {
                continue;
            }

            int nextNodeCount = dfs(next, cur);
            if (nextNodeCount > halfVcnt) {
                isCutNodeForChild = false;
            }

            linkedNodeCount += nextNodeCount;
        }

        if (isCutNodeForChild && vCnt - linkedNodeCount <= halfVcnt) {
            cutNodes.add(cur);
        }

        return linkedNodeCount;
    }
}
