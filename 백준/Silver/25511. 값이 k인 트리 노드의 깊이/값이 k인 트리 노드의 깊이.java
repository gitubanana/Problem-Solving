import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    static ArrayList<Integer>[] edges;
    static int[] values;
    static int wantValue;
    static int ans;

    static boolean dfs(int cur, int depth) {
        if (values[cur] == wantValue) {
            ans = depth;
            return true;
        }

        for (Integer next : edges[cur]) {
            if (dfs(next, depth + 1)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int vCnt = Integer.parseInt(input[0]);

        wantValue = Integer.parseInt(input[1]);
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

        values = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        dfs(0, 0);
        System.out.println(ans);
    }
}

