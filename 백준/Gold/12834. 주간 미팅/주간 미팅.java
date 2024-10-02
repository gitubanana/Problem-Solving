import java.util.*;

import java.lang.*;

import java.io.*;

class Edge implements Comparable<Edge> {

    int v;

    int w;

    public Edge(int v, int w) {

        this.v = v;

        this.w = w;

    }

    public int compareTo(Edge other) {

        return this.w - other.w;

    }

}

class Main {

    final static int INF = (int)1e8;

    static ArrayList<Edge>[] edges;

    static void dijkstra(int s, int[] dist) {

        PriorityQueue<Edge> pq = new PriorityQueue<>();

        for (int i = 0; i < dist.length; ++i) {

            dist[i] = INF;

        }

        dist[s] = 0;

        pq.add(new Edge(s, 0));

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

                pq.add(new Edge(next.v, nextDist));

            }

        }

    }

    public static int validateVal(int val) {

        if (val == INF) {

            return -1;

        }

        return val;

    }

    

    public static void main(String[] args) throws Exception {

        BufferedReader br =

            new BufferedReader(

                new InputStreamReader(System.in)

            );

        StringTokenizer st = new StringTokenizer(br.readLine());

        int homeCnt = Integer.parseInt(st.nextToken());

        int vCnt = Integer.parseInt(st.nextToken());

        int eCnt = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());

        int a = Integer.parseInt(st.nextToken());

        int b = Integer.parseInt(st.nextToken());

        

        int[] homes = new int[homeCnt];

        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < homeCnt; ++i) {

            homes[i] = Integer.parseInt(st.nextToken());

        }

        edges = new ArrayList[vCnt + 1];

        for (int v = 1; v <= vCnt; ++v) {

            edges[v] = new ArrayList<>();

        }

        while (eCnt-- > 0) {

            st = new StringTokenizer(br.readLine());

            int s = Integer.parseInt(st.nextToken());

            int e = Integer.parseInt(st.nextToken());

            int w = Integer.parseInt(st.nextToken());

            edges[s].add(new Edge(e, w));

            edges[e].add(new Edge(s, w));

        }

        int[][] dists = new int[2][vCnt + 1];

        dijkstra(a, dists[0]);

        dijkstra(b, dists[1]);

        int sum = 0;

        for (Integer v : homes) {

            sum +=

                validateVal(dists[0][v])

                + validateVal(dists[1][v]);

        }

        

        System.out.println(sum);

    }

}