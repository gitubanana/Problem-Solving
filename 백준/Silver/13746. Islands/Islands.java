import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final char LAND = 'L';
    static final char CLOUD = 'C';
    static final char VISITED = '!';
    static final int[] dy = {-1, 1, 0, 0};
    static final int[] dx = {0, 0, -1, 1};
    static final int dirSize = dy.length;

    static char[][] map;
    static int ySize, xSize;

    static boolean outOfRange(int y, int x) {
        return !(0 <= y && y < ySize)
                || !(0 <= x && x < xSize);
    }

    static void dfs(int y, int x) {
        map[y][x] = VISITED;
        for (int dir = 0; dir < dirSize; dir++) {
            int nextY = y + dy[dir];
            int nextX = x + dx[dir];
            if (outOfRange(nextY, nextX)
                    || (map[nextY][nextX] != LAND && map[nextY][nextX] != CLOUD)) {
                continue;
            }

            dfs(nextY, nextX);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        ySize = Integer.parseInt(st.nextToken());
        xSize = Integer.parseInt(st.nextToken());
        map = new char[ySize][];
        for (int y = 0; y < ySize; y++) {
            map[y] = br.readLine().toCharArray();
        }

        int landCnt = 0;
        for (int y = 0; y < ySize; y++) {
            for (int x = 0; x < xSize; x++) {
                if (map[y][x] != LAND) {
                    continue;
                }

                landCnt++;
                dfs(y, x);
            }
        }

        System.out.println(landCnt);
    }
}
