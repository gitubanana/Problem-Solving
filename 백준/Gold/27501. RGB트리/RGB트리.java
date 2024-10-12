import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int[][] dp;
    static int[][] beauty;
    static int[] chosenColor;
    static ArrayList<Integer>[] edges;
    static final String colorName = "RGB";

    static int dfs(int cur, int color, int prev) {
        if (dp[cur][color] != -1) {
            return dp[cur][color];
        }

        int nextC1 = (color + 1) % 3;
        int nextC2 = (color + 2) % 3;

        dp[cur][color] = beauty[cur][color];
        for (Integer next : edges[cur]) {
            if (next == prev) {
                continue;
            }

            dp[cur][color] += Math.max(
                    dfs(next, nextC1, cur),
                    dfs(next, nextC2, cur)
            );
        }

        return dp[cur][color];
    }

    static int findMaxDpColor(int v, int except) {
        int maxColor = 0;
        int maxDp = -1;

        for (int c = 0; c < 3; ++c) {
            if (c == except) {
                continue;
            }

            if (maxDp < dp[v][c]) {
                maxDp = dp[v][c];
                maxColor = c;
            }
        }

        return maxColor;
    }

    static void makeResult(int cur, int color, int prev) {
        chosenColor[cur] = color;

        for (Integer next : edges[cur]) {
            if (next == prev) {
                continue;
            }

            int nextColor = findMaxDpColor(next, color);

            makeResult(next, nextColor, cur);
        }
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

        dp = new int[vCnt + 1][3];
        beauty = new int[vCnt + 1][3];
        for (int v = 1; v <= vCnt; ++v) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int c = 0; c < 3; ++c) {
                dp[v][c] = -1;
                beauty[v][c] = Integer.parseInt(st.nextToken());
            }
        }

        for (int c = 0; c < 3; ++c) {
            dfs(1, c, 0);
        }

        int startColor = findMaxDpColor(1, -1);

        chosenColor = new int[vCnt + 1];
        makeResult(1, startColor, 0);

        StringBuilder result = new StringBuilder();
        for (int v = 1; v <= vCnt; ++v) {
            result.append(colorName.charAt(chosenColor[v]));
        }

        System.out.println(dp[1][startColor]);
        System.out.println(result);
    }
}
