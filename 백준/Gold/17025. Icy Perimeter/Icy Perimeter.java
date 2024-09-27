import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;


public class Main {
    final static char ICECREAM = '#';
    final static char VISITED = '!';
    final static int[] dy = {-1, 1, 0, 0};
    final static int[] dx = {0, 0, -1, 1};
    final static int dirSize = 4;

    static int size;
    static int maxArea, cmpArea;
    static int minPerimeter, cmpPerimeter;
    static char[][] map;

    public static void dfs(int y, int x) {
        ++cmpArea;
        map[y][x] = VISITED;

        for (int dir = 0; dir < dirSize; ++dir) {
            int nextY = y + dy[dir];
            int nextX = x + dx[dir];

            if (!(0 <= nextY && nextY < size)
                || !(0 <= nextX && nextX < size))
            {
                ++cmpPerimeter;
                continue ;
            }

            switch (map[nextY][nextX]) {
                case VISITED:
                    break;
                case ICECREAM:
                    dfs(nextY, nextX);
                    break;
                default:
                    ++cmpPerimeter;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        size = Integer.parseInt(br.readLine());
        map = new char[size][];
        for (int y = 0; y < size; ++y) {
            map[y] = br.readLine().toCharArray();
        }

        for (int y = 0; y < size; ++y) {
            for (int x = 0; x < size; ++x) {
                if (map[y][x] != ICECREAM)
                    continue ;

                cmpArea = cmpPerimeter = 0;
                dfs(y, x);
                if (maxArea < cmpArea) {
                    maxArea = cmpArea;
                    minPerimeter = cmpPerimeter;
                } else if (maxArea == cmpArea && minPerimeter > cmpPerimeter) {
                    minPerimeter = cmpPerimeter;
                }
            }
        }

        System.out.println(maxArea+" "+minPerimeter);
    }
}
