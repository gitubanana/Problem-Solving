import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Inet4Address;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    static ArrayList<Integer>[] edges;
    static int[][] costs;

    static long dfs(int cur, int cIdx) {
        long totalCost = costs[cur][cIdx];

        for (Integer next : edges[cur]) {
            totalCost += dfs(next, cIdx ^ 1);
        }
        return (totalCost);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int vCnt = Integer.parseInt(br.readLine());

        edges = new ArrayList[vCnt];
        for (int v = 0; v < vCnt; ++v) {
            edges[v] = new ArrayList<>();
        }

        for (int e = 1; e < vCnt; ++e) {
            String[] line = br.readLine().split(" ");
            int parent = Integer.parseInt(line[0]);
            int child = Integer.parseInt(line[1]);

            edges[parent].add(child);
        }

        costs = new int[vCnt][2];
        for (int v = 0; v < vCnt; ++v) {
            int c = 0;
            for (String cost : br.readLine().split(" ")) {
                costs[v][c] = Integer.parseInt(cost);
                ++c;
            }
        }

        System.out.println(Math.min(dfs(0, 0), dfs(0, 1)));
    }
}

