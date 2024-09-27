import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;


public class Main {
    final static char ICECREAM = '#';
    final static int[] dy = {-1, 1, 0, 0};
    final static int[] dx = {0, 0, -1, 1};
    final static int dirSize = 4;

    static int size;
    static int maxArea, cmpArea;
    static int minPerimeter, cmpPerimeter;
    static ArrayList<String> map = new ArrayList<>();
    static boolean[][] visited;

    public static void dfs(int y, int x) {
        ++cmpArea;
        visited[y][x] = true;

        for (int dir = 0; dir < dirSize; ++dir) {
            int nextY = y + dy[dir];
            int nextX = x + dx[dir];

            if (!(0 <= nextY && nextY < size)
                || !(0 <= nextX && nextX < size)
                || map.get(nextY).charAt(nextX) != ICECREAM)
            {
                ++cmpPerimeter;
                continue ;
            }

            if (visited[nextY][nextX])
                continue ;

            dfs(nextY, nextX);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        size = Integer.parseInt(br.readLine());
        visited = new boolean[size][size];
        for (int y = 0; y < size; ++y) {
            map.add(br.readLine());
        }

        for (int y = 0; y < size; ++y) {
            for (int x = 0; x < size; ++x) {
                if (map.get(y).charAt(x) != ICECREAM)
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
