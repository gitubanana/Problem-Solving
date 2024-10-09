import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    static int[][] dp;
    static ArrayList<Integer>[] edges;

    static int dfs(int cur) {
        int edgeSize = edges[cur].size();
        int[] nextTimes = new int[edgeSize];

        for (int i = 0; i < edgeSize; ++i) {
            Integer next = edges[cur].get(i);

            nextTimes[i] = dfs(next);
        }

        int maxTime = 0;
        int startCalling = 0;

        Arrays.sort(nextTimes);
        for (int i = nextTimes.length - 1; i >= 0; --i) {
            ++startCalling;
            maxTime = Math.max(
                    maxTime,
                    startCalling + nextTimes[i]
            );
        }

        return maxTime;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int vCnt = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        edges = new ArrayList[vCnt];
        for (int v = 0; v < vCnt; ++v) {
            edges[v] = new ArrayList<>();
        }

        for (int child = 0; child < vCnt; ++child) {
            int parent = Integer.parseInt(st.nextToken());
            if (parent == -1) {
                continue;
            }

            edges[parent].add(child);
        }

        System.out.println(dfs(0));
    }
}
