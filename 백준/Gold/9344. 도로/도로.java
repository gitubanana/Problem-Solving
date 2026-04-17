import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class Edge implements Comparable<Edge> {
    public int from, to, w;

    public Edge(int a, int b, int w) {
        this.from = Math.min(a, b);
        this.to = Math.max(a, b);
        this.w = w;
    }

    @Override
    public int compareTo(Edge other) {
        return Integer.compare(this.w, other.w);
    }
}

class UnionFind {
    private int[] parents;

    public UnionFind(int vCnt) {
        parents = new int[vCnt + 1];
        for (int v = 1; v <= vCnt; v++) {
            parents[v] = v;
        }
    }

    public int parentOf(int v) {
        if (parents[v] == v) {
            return v;
        }
        return parents[v] = parentOf(parents[v]);
    }

    public void union(int x, int y) {
        parents[parentOf(x)] = parentOf(y);
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static boolean kruskal(int vCnt, List<Edge> edges, Edge target) {
        int madeEcnt = 1;
        UnionFind uf = new UnionFind(vCnt);

        Collections.sort(edges);
        for (Edge edge : edges) {
            if (uf.parentOf(edge.from) == uf.parentOf(edge.to)) {
                continue;
            }

            if (edge.from == target.from && edge.to == target.to) {
                return true;
            }

            uf.union(edge.from, edge.to);
            if (++madeEcnt == vCnt) {
                break;
            }
        }
        return false;
    }

    static void solve() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int vCnt = Integer.parseInt(st.nextToken());
        int eCnt = Integer.parseInt(st.nextToken());
        List<Edge> edges = new ArrayList<>(eCnt);
        Edge target = new Edge(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), 0);

        for (int e = 0; e < eCnt; e++) {
            st = new StringTokenizer(br.readLine());
            edges.add(new Edge(
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken())
            ));
        }

        bw.append(
                kruskal(vCnt, edges, target)
                        ? "YES"
                        : "NO"
        ).append('\n');
    }

    public static void main(String[] args) throws IOException {
        int testCnt = Integer.parseInt(br.readLine());

        for (int t = 0; t < testCnt; t++) {
            solve();
        }
        bw.flush();
    }
}
