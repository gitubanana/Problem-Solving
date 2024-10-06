import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<Integer>[] edges;
    static int[] weights;
    static int sum;
    static int minDiff = Integer.MAX_VALUE;
    static int[] edge = new int[2];

    static int dfs(int cur, int prev) {
        int curWeight = weights[cur];

        for (Integer next : edges[cur]) {
            if (next == prev) {
                continue;
            }

            int nextWeight = dfs(next, cur);
            int cmpDiff = Math.abs((sum - nextWeight) - nextWeight);
            if (minDiff > cmpDiff) {
                minDiff = cmpDiff;
                edge[0] = cur;
                edge[1] = next;
            }

            curWeight += nextWeight;
        }

        return curWeight;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int vCnt = Integer.parseInt(br.readLine());

        edges = new ArrayList[vCnt + 1];
        for (int v = 1; v <= vCnt; ++v) {
            edges[v] = new ArrayList<>();
        }
        for (int e = 1; e < vCnt; ++e) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            edges[a].add(b);
            edges[b].add(a);
        }

        weights = new int[vCnt + 1];
        for (int v = 1; v <= vCnt; ++v) {
            weights[v] = Integer.parseInt(br.readLine());
            sum += weights[v];
        }

        dfs(1, 0);
        System.out.println(minDiff);
        System.out.println(edge[0]+" "+edge[1]);
    }
}
