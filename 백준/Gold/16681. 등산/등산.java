import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Edge implements Comparable<Edge> {
    long w;
    int v;

    public Edge(int v, long w) {
        this.v = v;
        this.w = w;
    }

    public int compareTo(Edge other) {
        if (this.w > other.w) {
            return 1;
        } else if (this.w < other.w) {
            return -1;
        }
        return 0;
    }
}

public class Main {
    final static long INF = (long)1e11;

    static int[] heights;
    static ArrayList<Edge>[] edges;

    static void dijkstra(int start, long[] dist) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();

        dist[start] = 0;
        pq.add(new Edge(start, 0));
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();

            if (dist[cur.v] != cur.w) {
                continue;
            }

            for (Edge next : edges[cur.v]) {
                if (heights[cur.v] >= heights[next.v]) {
                    continue;
                }

                long nextDist = cur.w + next.w;
                if (dist[next.v] <= nextDist) {
                    continue;
                }

                dist[next.v] = nextDist;
                pq.add(new Edge(next.v, nextDist));
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int vCnt = Integer.parseInt(st.nextToken());
        int eCnt = Integer.parseInt(st.nextToken());
        int D = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());

        heights = new int[vCnt + 1];
        edges = new ArrayList[vCnt + 1];
        long[] sDist = new long[vCnt + 1];
        long[] eDist = new long[vCnt + 1];

        st = new StringTokenizer(br.readLine());
        for (int v = 1; v <= vCnt; ++v) {
            heights[v] = Integer.parseInt(st.nextToken());
            edges[v] = new ArrayList<>();
            sDist[v] = eDist[v] = INF;
        }

        while (eCnt-- > 0) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            edges[a].add(new Edge(b, w));
            edges[b].add(new Edge(a, w));
        }

        dijkstra(1, sDist);
        dijkstra(vCnt, eDist);

        long maxHappy = Long.MIN_VALUE;
        for (int v = 2; v < vCnt; ++v) {
            if (sDist[v] == INF || eDist[v] == INF) {
                continue;
            }

            maxHappy = Math.max(
                    maxHappy,
                    ((long)heights[v] * E) - ((sDist[v] + eDist[v]) * D)
            );
        }

        if (maxHappy == Long.MIN_VALUE) {
            System.out.println("Impossible");
        } else {
            System.out.println(maxHappy);
        }
    }
}
