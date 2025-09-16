import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static final char START = 'S';
    static final char EMPTY = '#';
    static final char VISITED = '.';
    static final int[] dy = {-1, 1, 0, 0};
    static final int[] dx = {0, 0, -1, 1};

    static int ySize, xSize;
    static char[][] map;

    static class Pos {
        public int y, x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }

        boolean shallNotPass() {
            return map[y][x] != EMPTY;
        }
    }

    static int bfs(Pos start) {
        Queue<Pos> q = new ArrayDeque<>();
        int cnt = 1;

        map[start.y][start.x] = VISITED;
        q.add(start);
        do {
            Pos cur = q.poll();

            for (int dir = 0; dir < dy.length; dir++) {
                Pos next = new Pos(cur.y + dy[dir], cur.x + dx[dir]);
                if (next.shallNotPass()) {
                    continue;
                }

                map[next.y][next.x] = VISITED;
                q.add(next);
                cnt++;
            }
        } while (!q.isEmpty());

        return cnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        Pos start = new Pos(-1, -1);

        ySize = Integer.parseInt(st.nextToken());
        xSize = Integer.parseInt(st.nextToken());
        map = new char[ySize][];
        for (int y = 0; y < ySize; y++) {
            map[y] = br.readLine().toCharArray();
            if (start.y != -1) {
                continue;
            }

            for (int x = 0; x < xSize; x++) {
                if (map[y][x] == START) {
                    start.y = y;
                    start.x = x;
                    break;
                }
            }
        }

        System.out.println(bfs(start));
    }
}
