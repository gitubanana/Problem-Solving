import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Edge implements Comparable<Edge> {
        static boolean isAscending = true;

        int v;
        int w;

        Edge(int v, int w) {
            this.v = v;
            this.w = w;
        }

        @Override
        public int compareTo(Edge o) {
            if (isAscending) {
                return this.w - o.w;
            }

            return o.w - this.w;
        }
    }

    static ArrayList<Edge>[] edges;

    static int prim() {
        int totalWeight = 0;
        int visitedCnt = 0;
        boolean[] visited = new boolean[edges.length];
        PriorityQueue<Edge> pq = new PriorityQueue<>();

        pq.add(new Edge(0, 0));
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();

            if (visited[cur.v]) {
                continue;
            }

            totalWeight += cur.w;
            visited[cur.v] = true;
            if (++visitedCnt == visited.length) {
                break;
            }

            for (Edge next : edges[cur.v]) {
                if (visited[next.v]) {
                    continue;
                }

                pq.add(next);
            }
        }

        return totalWeight;
    }

    static int toFatigue(int upHillCnt) {
        return upHillCnt * upHillCnt;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int vCnt = Integer.parseInt(st.nextToken());
        int eCnt = Integer.parseInt(st.nextToken()) + 1;

        edges = new ArrayList[vCnt + 1];
        for (int v = 0; v <= vCnt; ++v) {
            edges[v] = new ArrayList<>();
        }

        while (eCnt-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken()) ^ 1;

            edges[a].add(new Edge(b, w));
            edges[b].add(new Edge(a, w));
        }

        int minUpHill = prim();

        Edge.isAscending = false;
        int maxUpHill = prim();

        System.out.println(toFatigue(maxUpHill) - toFatigue(minUpHill));
    }
}
