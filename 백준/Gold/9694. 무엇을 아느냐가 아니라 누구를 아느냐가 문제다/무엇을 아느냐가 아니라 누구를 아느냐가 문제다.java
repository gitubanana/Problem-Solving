import java.util.*;
import java.lang.*;
import java.io.*;

class Edge implements Comparable<Edge> {
    int v, w;

    public Edge(int v, int w) {
        this.v = v;
        this.w = w;
    }

    public int compareTo(Edge other) {
        return this.w - other.w;
    }
}

class Main {
    final static int MAX_V = 20;
    final static int INF = (int)1e8;
    static int vCnt;
    static int[] dist = new int[MAX_V];
    static int[] prev = new int[MAX_V];
    static ArrayList<Edge>[] edges;
    static StringBuilder result = new StringBuilder();

    static void dijkstra() {
        PriorityQueue<Edge> pq = new PriorityQueue<>();

        dist[0] = 0;
        pq.add(new Edge(0, 0));
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();

            if (dist[cur.v] != cur.w) {
                continue;
            }

            for (Edge next : edges[cur.v]) {
                int nextDist = cur.w + next.w;
                if (dist[next.v] <= nextDist) {
                    continue;
                }

                dist[next.v] = nextDist;
                prev[next.v] = cur.v;
                pq.add(new Edge(next.v, nextDist));
            }
        }

        ArrayList<Integer> path = new ArrayList<>();
        if (dist[vCnt - 1] == INF) {
            path.add(-1);
        } else {
            int cur = vCnt - 1;
            while (true) {
                path.add(cur);
                if (cur == 0) {
                    break;
                }

                cur = prev[cur];
            }
        }

        for (int i=path.size()-1; i>=0; --i) {
            result.append(" "+path.get(i));
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br
                = new BufferedReader(
                new InputStreamReader(System.in)
        );

        int testCnt = Integer.parseInt(br.readLine());
        for (int t=1; t<=testCnt; ++t) {
            StringTokenizer l = new StringTokenizer(br.readLine());
            int eCnt = Integer.parseInt(l.nextToken());

            vCnt = Integer.parseInt(l.nextToken());
            edges = new ArrayList[vCnt];
            for (int v = 0; v < vCnt; ++v) {
                dist[v] = INF;
                edges[v] = new ArrayList<>();
            }

            while (eCnt-- > 0) {
                StringTokenizer line = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(line.nextToken());
                int b = Integer.parseInt(line.nextToken());
                int w = Integer.parseInt(line.nextToken());

                edges[a].add(new Edge(b, w));
                edges[b].add(new Edge(a, w));
            }

            result.append("Case #"+t+":");
            dijkstra();
            result.append("\n");
        }

        System.out.print(result);
    }
}