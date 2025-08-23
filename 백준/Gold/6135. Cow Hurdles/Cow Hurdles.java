import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final int INF = (int) 1e9;

    static int[][] heights;

    static void floydWarshall() {
        for (int mid = 1; mid < heights.length; mid++) {
            for (int from = 1; from < heights.length; from++) {
                for (int to = 1; to < heights.length; to++) {
                    heights[from][to] = Math.min(
                            heights[from][to],
                            Math.max(heights[from][mid], heights[mid][to])
                    );
                }
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int vCnt = Integer.parseInt(st.nextToken());
        int eCnt = Integer.parseInt(st.nextToken());
        int qCnt = Integer.parseInt(st.nextToken());

        heights = new int[vCnt + 1][vCnt + 1];
        for (int from = 1; from <= vCnt; from++) {
            for (int to = 1; to <= vCnt; to++) {
                heights[from][to] = INF;
            }
        }
        for (int e = 0; e < eCnt; e++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            int h = Integer.parseInt(st.nextToken());

            heights[from][to] = Math.min(heights[from][to], h);
        }

        StringBuilder result = new StringBuilder();

        floydWarshall();
        for (int q = 0; q < qCnt; q++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            result.append(heights[from][to] == INF ? -1 : heights[from][to])
                    .append('\n');
        }

        System.out.println(result);
    }
}
