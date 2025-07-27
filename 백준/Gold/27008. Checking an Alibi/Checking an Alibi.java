import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Edge implements Comparable<Edge> {
        int v;
        int w;

        Edge(int v, int w) {
            this.v = v;
            this.w = w;
        }

        @Override
        public int compareTo(Edge o) {
            return this.w - o.w;
        }
    }

    static final int START = 1;
    static final int INF = (int) 1e9;

    static List<Edge>[] edges;
    static List<Integer>[] cowsByField;
    static int goalDist;

    static List<Integer> findSuspects() {
        int[] dist = new int[edges.length];
        List<Integer> suspects = new ArrayList<>();
        PriorityQueue<Edge> pq = new PriorityQueue<>();

        for (int v = 1; v < dist.length; v++) {
            dist[v] = INF;
        }
        dist[START] = 0;

        pq.add(new Edge(START, 0));
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            if (cur.w > goalDist) {
                break;
            }
            if (cur.w != dist[cur.v]) {
                continue;
            }

            suspects.addAll(cowsByField[cur.v]);
            for (Edge next : edges[cur.v]) {
                int nextDist = cur.w + next.w;
                if (dist[next.v] <= nextDist) {
                    continue;
                }

                dist[next.v] = nextDist;
                pq.add(new Edge(next.v, nextDist));
            }
        }
        return suspects;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int vCnt = Integer.parseInt(st.nextToken());
        int eCnt = Integer.parseInt(st.nextToken());
        int cowCnt = Integer.parseInt(st.nextToken());
        goalDist = Integer.parseInt(st.nextToken());

        edges = new List[vCnt + 1];
        cowsByField = new List[vCnt + 1];
        for (int v = 1; v <= vCnt; v++) {
            edges[v] = new ArrayList<>();
            cowsByField[v] = new ArrayList<>();
        }
        for (int e = 0; e < eCnt; e++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            edges[a].add(new Edge(b, w));
            edges[b].add(new Edge(a, w));
        }
        for (int c = 1; c <= cowCnt; c++) {
            int field = Integer.parseInt(br.readLine());

            cowsByField[field].add(c);
        }

        List<Integer> suspects = findSuspects();

        System.out.println(suspects.size());
        suspects.stream()
                .sorted()
                .forEach(System.out::println);
    }
}
