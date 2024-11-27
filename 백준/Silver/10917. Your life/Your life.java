import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static final int START = 1;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int vCnt = Integer.parseInt(st.nextToken());
        int eCnt = Integer.parseInt(st.nextToken());
        List<Integer> edges[] = new List[vCnt + 1];

        for (int v = 1; v <= vCnt; v++) {
            edges[v] = new ArrayList<>();
        }

        while (eCnt-- > 0) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            edges[from].add(to);
        }

        bw.append(String.valueOf(bfs(START, vCnt, edges)));
        bw.flush();
    }

    static int bfs(int start, int end, List<Integer>[] edges) {
        Queue<Integer> q = new ArrayDeque<>();
        int minDist = 0;
        boolean[] visited = new boolean[edges.length];

        visited[start] = true;
        q.add(start);
        while (!q.isEmpty()) {
            int qSize = q.size();

            minDist++;
            while (qSize-- > 0) {
                int cur = q.poll();

                for (int next : edges[cur]) {
                    if (visited[next]) {
                        continue;
                    }

                    if (next == end) {
                        return minDist;
                    }

                    visited[next] = true;
                    q.add(next);
                }
            }
        }
        return -1;
    }
}
