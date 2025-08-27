import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

class Edge {
    public int v;
    public int w;

    public Edge(int v, int w) {
        this.v = v;
        this.w = w;
    }
}

public class Main {
    static List<Edge>[] edges;

    static int dfs(int cur, int end, int prev) {
        if (cur == end) {
            return 0;
        }

        for (Edge next : edges[cur]) {
            if (next.v == prev) {
                continue;
            }

            int length = dfs(next.v, end, cur);
            if (length != -1) {
                return length + next.w;
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int vCnt = Integer.parseInt(st.nextToken());
        int qCnt = Integer.parseInt(st.nextToken());

        edges = new List[vCnt + 1];
        for (int v = 1; v <= vCnt; v++) {
            edges[v] = new ArrayList<>();
        }
        for (int e = 1; e < vCnt; e++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            edges[a].add(new Edge(b, w));
            edges[b].add(new Edge(a, w));
        }

        StringBuilder result = new StringBuilder();
        for (int q = 0; q < qCnt; q++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());

            result.append(dfs(start, end, 0))
                    .append('\n');
        }

        System.out.println(result);
    }
}
