import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    static ArrayList<Integer>[] edges;
    static int[] weights;

    static long dfs(int cur) {
        long maxScore = weights[cur];

        for (Integer next : edges[cur]) {
            long nextScore = dfs(next);
            if (nextScore <= 0) {
                continue;
            }

            maxScore += nextScore;
        }

        return maxScore;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int vCnt = Integer.parseInt(br.readLine());

        edges = new ArrayList[vCnt];
        for (int v = 0; v < vCnt; ++v) {
            edges[v] = new ArrayList<>();
        }
        for (int e = 1; e < vCnt; ++e) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int parent = Integer.parseInt(st.nextToken());
            int child = Integer.parseInt(st.nextToken());

            edges[parent].add(child);
        }

        weights = new int[vCnt];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int v = 0; v < vCnt; ++v) {
            weights[v] = Integer.parseInt(st.nextToken());
        }

        System.out.println(dfs(0));
    }
}
