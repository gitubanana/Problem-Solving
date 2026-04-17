import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

class UnionFind {
    private final int[] parents;

    public UnionFind(int vCnt) {
        parents = new int[vCnt + 1];
        for (int v = 1; v <= vCnt; v++) {
            parents[v] = v;
        }
    }

    // representative(parent) : 대표자
    public int representativeOf(int x) {
        if (x == parents[x]) {
            return x;
        }

        return parents[x] = representativeOf(parents[x]);
    }

    public void union(int a, int b) {
        parents[representativeOf(a)] = representativeOf(b);
    }
}

class Edge implements Comparable<Edge> {
    private static int nextId = 1;

    public int a, b, w, id;

    public Edge(int a, int b, int w) {
        this.a = a;
        this.b = b;
        this.w = w;
        this.id = nextId++;
    }

    @Override
    public int compareTo(Edge other) {
        return Integer.compare(this.w, other.w);
    }
}

public class Main {
    static void kruskal(List<Edge> edges, int vCnt) {
        int madeEcnt = 1;
        UnionFind uf = new UnionFind(vCnt);
        StringBuilder result = new StringBuilder(vCnt * 4);

        Collections.sort(edges);
        result.append(vCnt-1).append('\n');
        for (Edge edge : edges) {
            if (uf.representativeOf(edge.a) == uf.representativeOf(edge.b)) {
                continue;
            }

            result.append(edge.id).append('\n');
            if (++madeEcnt == vCnt) {
                break;
            }

            uf.union(edge.a, edge.b);
        }

        System.out.print(result);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int vCnt = Integer.parseInt(st.nextToken());
        int eCnt = Integer.parseInt(st.nextToken());
        List<Edge> edges = new ArrayList<>(eCnt);

        for (int e = 0; e < eCnt; e++) {
            st = new StringTokenizer(br.readLine());
            edges.add(new Edge(
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken()),
                    Integer.parseInt(st.nextToken())
            ));
        }

        kruskal(edges, vCnt);
    }
}
