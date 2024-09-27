import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;


public class Main {
    final static char FENCE = '#';
    final static char VISITED = '!';
    final static int size = 101;
    final static int[] dy = {-1, 1, 0, 0};
    final static int[] dx = {0, 0, -1, 1};
    final static int dirSize = 4;

    static int perimeter;
    static char[][] map;

    public static void dfs(int y, int x) {
        map[y][x] = VISITED;
        for (int dir = 0; dir < dirSize; ++dir) {
            int nextY = y + dy[dir];
            int nextX = x + dx[dir];

            if (!(0 <= nextY && nextY < size)
                || !(0 <= nextX && nextX < size))
            {
                ++perimeter;
                continue ;
            }

            switch (map[nextY][nextX]) {
                case VISITED:
                    break;
                case FENCE:
                    dfs(nextY, nextX);
                    break;
                default:
                    ++perimeter;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder result = new StringBuilder();

        while (true) {
            int fenceCnt = Integer.parseInt(br.readLine());
            if (fenceCnt == 0) {
                break ;
            }

            map = new char[size][size];
            while (fenceCnt > 0) {
                String[] coordinate = br.readLine().split(" ");
                int x = Integer.parseInt(coordinate[0]);
                int y = Integer.parseInt(coordinate[1]);

                map[y][x] = FENCE;
                --fenceCnt;
            }

            perimeter = 0;
            for (int y = 0; y < size; ++y) {
                for (int x = 0; x < size; ++x) {
                    if (map[y][x] != FENCE)
                        continue ;

                    dfs(y, x);
                }
            }

            result.append(perimeter + "\n");
        }

        System.out.print(result);
    }
}
