import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Pos {
    int y, x;

    public Pos() {
    }

    public Pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

public class Main {
    final static char WHITE = '1';
    final static char BLACK = '0';
    final static int MAX_SIZE = 182;
    final static int[] dy = {-1, 1, 0, 0};
    final static int[] dx = {0, 0, -1, 1};
    final static int dirSize = dy.length;

    static int ySize, xSize;
    static char[][] map = new char[MAX_SIZE][MAX_SIZE];
    static int[][] dists = new int[MAX_SIZE][MAX_SIZE];
    static Queue<Pos> q = new LinkedList<>();

    static void bfs() {
        while (!q.isEmpty()) {
            Pos cur = q.poll();
            int curDist = dists[cur.y][cur.x];

            for (int dir = 0; dir < dirSize; ++dir) {
                Pos next = new Pos(cur.y+dy[dir], cur.x+dx[dir]);

                if (!(0 <= next.y && next.y < ySize)
                    || !(0 <= next.x && next.x < xSize)
                    || map[next.y][next.x] == WHITE)
                    continue;

                dists[next.y][next.x] = curDist + 1;
                map[next.y][next.x] = WHITE;
                q.add(next);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] firstLine = br.readLine().split(" ");

        ySize = Integer.parseInt(firstLine[0]);
        xSize = Integer.parseInt(firstLine[1]);
        for (int y = 0; y < ySize; ++y) {
            String line = br.readLine();

            for (int x = 0; x < xSize; ++x) {
                map[y][x] = line.charAt(x);
                if (map[y][x] == WHITE) {
                    q.add(new Pos(y, x));
                }
            }
        }

        bfs();
        StringBuilder result = new StringBuilder();

        for (int y = 0; y < ySize; ++y) {
            for (int x = 0; x < xSize; ++x) {
                result.append(dists[y][x]+" ");
            }
            result.append("\n");
        }
        System.out.print(result);
    }
}

