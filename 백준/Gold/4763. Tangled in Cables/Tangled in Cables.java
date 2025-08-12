import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static class Edge implements Comparable<Edge> {
        int v;
        double w;

        Edge(int v, double w) {
            this.v = v;
            this.w = w;
        }

        @Override
        public int compareTo(Edge o) {
            return Double.compare(this.w, o.w);
        }
    }

    static class IdMapper {
        private int gId = 0;
        private final Map<String, Integer> map = new HashMap<>();

        public void put(String name) {
            map.put(name, gId++);
        }

        public Integer get(String name) {
            return map.get(name);
        }
    }

    static double prim(List<Edge>[] edges) {
        final int START = 0;
        PriorityQueue<Edge> pq = new PriorityQueue<>();
        boolean[] visited = new boolean[edges.length];
        double totalLength = 0;
        int madeEcnt = 0;

        pq.add(new Edge(START, 0));
        while (!pq.isEmpty()) {
            Edge cur = pq.poll();
            if (visited[cur.v]) {
                continue;
            }

            visited[cur.v] = true;
            totalLength += cur.w;
            if (++madeEcnt == edges.length) {
                return totalLength;
            }

            for (Edge next : edges[cur.v]) {
                if (visited[next.v]) {
                    continue;
                }

                pq.add(new Edge(next.v, next.w));
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        double spoolLength = Double.parseDouble(br.readLine());
        int vCnt = Integer.parseInt(br.readLine());
        IdMapper idMapper = new IdMapper();
        List<Edge>[] edges = new List[vCnt];

        for (int v = 0; v < vCnt; v++) {
            edges[v] = new ArrayList<>();
            idMapper.put(br.readLine());
        }

        int eCnt = Integer.parseInt(br.readLine());

        for (int e = 0; e < eCnt; e++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = idMapper.get(st.nextToken());
            int b = idMapper.get(st.nextToken());
            double w = Double.parseDouble(st.nextToken());

            edges[a].add(new Edge(b, w));
            edges[b].add(new Edge(a, w));
        }

        double needLength = prim(edges);
        if (spoolLength < needLength) {
            System.out.println("Not enough cable");
        } else {
            System.out.printf("Need %.1f miles of cable", needLength);
        }
    }
}
