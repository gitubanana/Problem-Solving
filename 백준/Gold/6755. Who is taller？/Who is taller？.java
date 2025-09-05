import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int vCnt = Integer.parseInt(st.nextToken());
        int eCnt = Integer.parseInt(st.nextToken());
        List<Integer>[] edges = new List[vCnt + 1];

        for (int v = 1; v <= vCnt; v++) {
            edges[v] = new ArrayList<>();
        }
        for (int e = 0; e < eCnt; e++) {
            st = new StringTokenizer(br.readLine());
            edges[Integer.parseInt(st.nextToken())].add(Integer.parseInt(st.nextToken()));
        }

        st = new StringTokenizer(br.readLine());
        int taller = Integer.parseInt(st.nextToken());
        int smaller = Integer.parseInt(st.nextToken());
        boolean[] visited = new boolean[vCnt + 1];
        String result;

        if (dfs(taller, smaller, edges, visited)) {
            result = "yes";
        } else if (dfs(smaller, taller, edges, visited)) {
            result = "no";
        } else {
            result = "unknown";
        }

        System.out.println(result);
    }

    static boolean dfs(int cur, int target, List<Integer>[] edges, boolean[] visited) {
        visited[cur] = true;
        for (Integer next : edges[cur]) {
            if (next == target) {
                return true;
            }

            if (visited[next]) {
                continue;
            }

            if (dfs(next, target, edges, visited)) {
                return true;
            }
        }
        return false;
    }
}
