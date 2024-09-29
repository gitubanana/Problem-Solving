import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    final static char EMPTY = '0';
    final static int[] dy = {-1, -1, -1, 0, 1, 1, 1, 0};
    final static int[] dx = {-1, 0, 1, 1, 1, 0, -1, -1};
    final static int dirSize = dy.length;

    static char[][] map;
    static int ySize;
    static int xSize;

    static void dfs(int y, int x) {
        map[y][x] = EMPTY;
        for (int dir = 0; dir < dirSize; ++dir) {
            int nextY = y + dy[dir];
            int nextX = x + dx[dir];

            if (!(0 <= nextY && nextY < ySize)
                || !(0 <= nextX && nextX < xSize)
                || map[nextY][nextX] == EMPTY)
                continue ;

            dfs(nextY, nextX);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        ySize = Integer.parseInt(input[0]);
        xSize = Integer.parseInt(input[1]);
        map = new char[ySize][xSize];
        for (int y = 0; y < ySize; ++y) {
            int x = 0;
            for (String space : br.readLine().split(" ")) {
                map[y][x] = space.charAt(0);
                ++x;
            }
        }

        int landCnt = 0;
        for (int y = 0; y < ySize; ++y) {
            for (int x = 0; x < xSize; ++x) {
                if (map[y][x] == EMPTY) {
                    continue;
                }

                ++landCnt;
                dfs(y, x);
            }
        }

        System.out.println(landCnt);
    }
}

