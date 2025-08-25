import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Edge implements Comparable<Edge> {
    public int v;
    public int w;

    public Edge(int v, int w) {
        this.v = v;
        this.w = w;
    }

    @Override
    public int compareTo(Edge o) {
        return this.w - o.w;
    }
}

public class Main {
    static final int INF = (int) 1e9;
    static List<Edge>[] edges;

    static int dijkstra(int start, int end) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        int[] dists = new int[edges.length];
        int[] cnt = new int [edges.length];

        for (int v = 1; v < dists.length; v++) {
            dists[v] = INF;
        }
        dists[start] = 0;

        pq.add(new Edge(start, 0));
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            if (cur.w != dists[cur.v]) {
                continue;
            }

            for (Edge next : edges[cur.v]) {
                int nextDist = cur.w + next.w;
                if (dists[next.v] < nextDist) {
                    continue;
                }

                if (dists[next.v] == nextDist) {
                    cnt[next.v]++;
                } else {
                    cnt[next.v] = 1;
                    dists[next.v] = nextDist;
                }
                pq.add(new Edge(next.v, nextDist));
            }
        }
        return dists[end] * cnt[end];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int vCnt = Integer.parseInt(st.nextToken());
        int eCnt = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(st.nextToken());
        int end = Integer.parseInt(st.nextToken());
        int totalLength = 0;

        edges = new List[vCnt + 1];
        for (int v = 1; v <= vCnt; v++) {
            edges[v] = new ArrayList<>();
        }
        for (int e = 0; e < eCnt; e++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            totalLength += w;
            edges[a].add(new Edge(b, w));
            edges[b].add(new Edge(a, w));
        }

        System.out.println(totalLength - dijkstra(start, end));
    }
}
