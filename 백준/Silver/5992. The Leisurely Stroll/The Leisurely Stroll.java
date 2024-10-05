import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][] edges;
    static int maxDepth;

    static void dfs(int cur, int depth) {
        if (cur == 0) {
            maxDepth = Math.max(maxDepth, depth);
            return;
        }

        dfs(edges[cur][0], depth + 1);
        dfs(edges[cur][1], depth + 1);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int vCnt = Integer.parseInt(br.readLine());

        edges = new int[vCnt][2];
        for (int e = 1; e < vCnt; ++e) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int parent = Integer.parseInt(st.nextToken());

            edges[parent][0] = Integer.parseInt(st.nextToken());
            edges[parent][1] = Integer.parseInt(st.nextToken());
        }

        dfs(1, 0);
        System.out.println(maxDepth);
    }
}