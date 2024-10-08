import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Pos {
    final static int[] dy = {-1, 0, 1, 0};
    final static int[] dx = {0, 1, 0, -1};
    final static String dirs = "URDL";

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
    final static char VISIBLE = '.';
    final static char BLIND = '#';

    static int ySize, xSize;
    static char[][] map;

    static boolean outOfBound(Pos pos) {
        return pos.y == -1 || pos.y == ySize
                || pos.x == -1 || pos.x == xSize;
    }

    static void expandView(Pos start) {
        char wantSpace = map[start.y][start.x];
        Queue<Pos> q = new LinkedList<>();

        map[start.y][start.x] = VISIBLE;
        q.add(start);
        while (!q.isEmpty()) {
            Pos cur = q.poll();

            for (int dir = 0; dir < Pos.dy.length; ++dir) {
                Pos next = new Pos(
                        cur.y + Pos.dy[dir],
                        cur.x + Pos.dx[dir]
                );

                if (outOfBound(next)
                        || wantSpace != map[next.y][next.x]) {
                    continue;
                }

                map[next.y][next.x] = VISIBLE;
                q.add(next);
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        ySize = Integer.parseInt(st.nextToken());
        xSize = Integer.parseInt(st.nextToken());
        map = new char[ySize][];
        for (int y = 0; y < ySize; ++y) {
            map[y] = br.readLine().toCharArray();
        }

        st = new StringTokenizer(br.readLine());
        Pos cur = new Pos(
                Integer.parseInt(st.nextToken()) - 1,
                Integer.parseInt(st.nextToken()) - 1
        );

        String action = br.readLine();
        for (int i = 0; i < action.length(); ++i) {
            char cmd = action.charAt(i);
            int dir = Pos.dirs.indexOf(cmd);

            if (dir != -1) {
                cur.move(dir);
                continue;
            }

            if (map[cur.y][cur.x] != VISIBLE) {
                expandView(cur);
            }
        }

        map[cur.y][cur.x] = VISIBLE;
        for (int dir = 0; dir < Pos.dy.length; ++dir) {
            Pos next = new Pos(
                    cur.y + Pos.dy[dir],
                    cur.x + Pos.dx[dir]
            );

            if (outOfBound(next)) {
                continue;
            }

            map[next.y][next.x] = VISIBLE;
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int y = 0; y < ySize; ++y) {
            for (int x = 0; x < xSize; ++x) {
                if (map[y][x] == VISIBLE) {
                    bw.append(VISIBLE);
                } else {
                    bw.append(BLIND);
                }
            }
            bw.append("\n");
        }
        bw.flush();
    }
}
