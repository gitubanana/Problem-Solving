import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static int[][] beauty;
    static int[] chosenColor;
    static ArrayList<Integer>[] edges;
    static final String colorName = "RGB";
    static final int RED = 0;
    static final int GREEN = 1;
    static final int BLUE = 2;

    static void dfs(int cur, int prev) {
        for (Integer next : edges[cur]) {
            if (next == prev) {
                continue;
            }

            dfs(next, cur);
            beauty[cur][RED] += Math.max(beauty[next][GREEN], beauty[next][BLUE]);
            beauty[cur][GREEN] += Math.max(beauty[next][RED], beauty[next][BLUE]);
            beauty[cur][BLUE] += Math.max(beauty[next][RED], beauty[next][GREEN]);
        }
    }

    static int findMaxDpColor(int v, int except) {
        int maxColor = 0;
        int maxDp = -1;

        for (int c = 0; c < 3; ++c) {
            if (c == except) {
                continue;
            }

            if (maxDp < beauty[v][c]) {
                maxDp = beauty[v][c];
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

        beauty = new int[vCnt + 1][3];
        for (int v = 1; v <= vCnt; ++v) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int c = 0; c < 3; ++c) {
                beauty[v][c] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(1, 0);
        int startColor = findMaxDpColor(1, -1);

        chosenColor = new int[vCnt + 1];
        makeResult(1, startColor, 0);

        StringBuilder result = new StringBuilder();

        result.append(beauty[1][startColor]+"\n");
        for (int v = 1; v <= vCnt; ++v) {
            result.append(colorName.charAt(chosenColor[v]));
        }
        System.out.println(result);
    }
}
