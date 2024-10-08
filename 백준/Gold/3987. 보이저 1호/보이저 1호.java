import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Pos {
    final static int[] dy = {-1, 0, 1, 0};
    final static int[] dx = {0, 1, 0, -1};

    int y, x;

    Pos(int y, int x) {
        this.y = y;
        this.x = x;
    }

    void move(int dir) {
        this.y += dy[dir];
        this.x += dx[dir];
    }
}

public class Main {
    final static char EMPTY = '.';
    final static char BLACKHOLE = 'C';
    final static String planet = "/\\";
    final static int[][] changeDir = {
            {1, 0, 3, 2},
            {3, 2, 1, 0}
    };

    static int ySize, xSize;
    static char[][] map;

    static int getAliveTime(Pos start, int dir) {
        int time = 1;
        Pos cur = new Pos(start.y, start.x);
        boolean[][][] visited = new boolean[ySize][xSize][Pos.dy.length];

        while (true) {
            visited[cur.y][cur.x][dir] = true;
            cur.move(dir);
            if (!(0 <= cur.y && cur.y < ySize)
                    || !(0 <= cur.x && cur.x < xSize)
                    || (map[cur.y][cur.x] == BLACKHOLE)) {
                break;
            }

            if (visited[cur.y][cur.x][dir]) {
                return Integer.MAX_VALUE;
            }

            int pIdx = planet.indexOf(map[cur.y][cur.x]);
            if (pIdx != -1) {
                dir = changeDir[pIdx][dir];
            }

            ++time;
        }

        return time;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        ySize = Integer.parseInt(st.nextToken());
        xSize = Integer.parseInt(st.nextToken());
        map = new char[ySize][xSize];
        for (int y = 0; y < ySize; ++y) {
            String line = br.readLine();

            for (int x = 0; x < xSize; ++x) {
                map[y][x] = line.charAt(x);
            }
        }

        st = new StringTokenizer(br.readLine());
        Pos start = new Pos(
                Integer.parseInt(st.nextToken()) - 1,
                Integer.parseInt(st.nextToken()) - 1
        );

        char dirCh = 'U';
        int maxTime = -1;

        String dirStr = "URDL";
        for (int dir = 0; dir < Pos.dy.length; ++dir) {
            int cmpTime = getAliveTime(start, dir);

            if (maxTime < cmpTime) {
                maxTime = cmpTime;
                dirCh = dirStr.charAt(dir);
            }
        }

        StringBuilder result = new StringBuilder();
        result.append(dirCh + "\n");
        if (maxTime == Integer.MAX_VALUE) {
            result.append("Voyager");
        } else {
            result.append(maxTime);
        }

        System.out.println(result);
    }
}
