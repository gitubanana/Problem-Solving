import java.util.*;
import java.lang.*;
import java.io.*;

public class Main {
    static ArrayList<Integer>[] edges;
    static long[] money;

    static int dfs(int cur, int prev) {
        money[cur] = 1;

        int childCnt = 1;
        for (Integer next : edges[cur]) {
            childCnt += dfs(next, cur);
        }

        money[prev] += money[cur] + childCnt;
        return childCnt;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int vCnt = Integer.parseInt(br.readLine());

        edges = new ArrayList[vCnt + 1];
        for (int v = 1; v <= vCnt; ++v) {
            edges[v] = new ArrayList<>();
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int child = 2; child <= vCnt; ++child) {
            int parent = Integer.parseInt(st.nextToken());

            edges[parent].add(child);
        }

        money = new long[vCnt + 1];
        dfs(1, 0);

        StringBuilder result = new StringBuilder();
        for (int v = 1; v <= vCnt; ++v) {
            result.append(money[v]+" ");
        }

        System.out.println(result);
    }
}
