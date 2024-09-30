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
    final static char WALL = 'X';
    final static char START = 'S';
    final static char GOAL = 'G';
    final static int MAX_SIZE = 15;
    final static int[] dy = {-1, 1, 0, 0};
    final static int[] dx = {0, 0, -1, 1};
    final static int dirSize = dy.length;

    static int ySize, xSize;
    static char[][] map = new char[MAX_SIZE][MAX_SIZE];
    static StringBuilder result = new StringBuilder();

    static void bfs(Pos start) {
        int dist = 0;
        Queue<Pos> q = new LinkedList<>();

        map[start.y][start.x] = WALL;
        q.add(start);
        while (!q.isEmpty())
        {
            int qSize = q.size();

            ++dist;
            while (qSize-- > 0) {
                Pos cur = q.poll();

                for (int dir = 0; dir < dirSize; ++dir) {
                    Pos next = new Pos(cur.y + dy[dir], cur.x + dx[dir]);

                    if (!(0 <= next.y && next.y < ySize)
                        || !(0 <= next.x && next.x < xSize)
                        || map[next.y][next.x] == WALL)
                        continue;

                    if (map[next.y][next.x] == GOAL) {
                        result.append("Shortest Path: "+dist+"\n");
                        return;
                    }

                    map[next.y][next.x] = WALL;
                    q.add(next);
                }
            }
        }

        result.append("No Exit\n");
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testCnt = Integer.parseInt(br.readLine());
        while (testCnt-- > 0) {
            Pos start = new Pos();
            String[] firstLine = br.readLine().split(" ");

            ySize = Integer.parseInt(firstLine[0]);
            xSize = Integer.parseInt(firstLine[1]);
            for (int y = 0; y < ySize; ++y) {
                String line = br.readLine();

                for (int x = 0; x < xSize; ++x) {
                    map[y][x] = line.charAt(x);
                    if (map[y][x] == START) {
                        start.y = y;
                        start.x = x;
                    }
                }
            }

            bfs(start);
        }

        System.out.print(result);
    }
}

