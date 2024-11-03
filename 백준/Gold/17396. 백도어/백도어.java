import java.util.*;
import java.lang.*;
import java.io.*;

class Edge implements Comparable<Edge> {
    int v;
    long w;

    public Edge(int v, long w) {
        this.v = v;
        this.w = w;
    }

    @Override
    public int compareTo(Edge other) {
        if (this.w > other.w) {
            return 1;
        }

        if (this.w < other.w) {
            return -1;
        }

        return 0;
    }
}

class Main {
    static final long INF = (long)1e11;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static long[] dists;
    static boolean[] cannotGo;
    static List<Edge>[] edges;

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int vCnt = Integer.parseInt(st.nextToken());
        int eCnt = Integer.parseInt(st.nextToken());

        dists = new long[vCnt];
        edges = new ArrayList[vCnt];
        cannotGo = new boolean[vCnt];
        st = new StringTokenizer(br.readLine());
        for (int v = 0; v < vCnt; v++) {
            dists[v] = INF;
            edges[v] = new ArrayList<>();
            cannotGo[v] = Integer.parseInt(st.nextToken()) == 1 ? true : false;
        }
        cannotGo[vCnt - 1] = false;
        
        while (eCnt-- > 0) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            edges[from].add(new Edge(to, w));
            edges[to].add(new Edge(from, w));
        }

        dijkstra(0);
        bw.append((dists[vCnt - 1] == INF ? -1 : dists[vCnt - 1])+"\n");
        bw.flush();
    }

    static void dijkstra(int start) {
        PriorityQueue<Edge> pq = new PriorityQueue<>();

        dists[start] = 0;
        pq.add(new Edge(start, 0));
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();

            if (dists[cur.v] != cur.w) {
                continue;
            }

            for (Edge next : edges[cur.v]) {
                if (cannotGo[next.v]) {
                    continue;
                }

                long nextDist = cur.w + next.w;
                if (dists[next.v] <= nextDist) {
                    continue;
                }

                dists[next.v] = nextDist;
                pq.add(new Edge(next.v, nextDist));
            }
        }
    }
}