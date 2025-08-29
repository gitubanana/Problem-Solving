import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    static final int SIZE = 8;
    static final int INF = (int) 1e9;
    static final char START = 'S';
    static final char END = 'E';
    static final char MUD = 'M';
    static final int[] dy = {-1, 1, 0, 0};
    static final int[] dx = {0, 0, -1, 1};
    static final String[] map = new String[SIZE];
    static final int[][] mud = new int[SIZE][SIZE];
    static Pos start = new Pos(0, 0);

    static class Pos {
        public int y;
        public int x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }

        public boolean outOfBoundary() {
            return (y < 0 || y >= SIZE)
                    || (x < 0 || x >= SIZE);
        }
    }

    static boolean takeInput(BufferedReader br) throws IOException {
        for (int y = 0; y < SIZE; y++) {
            map[y] = br.readLine();
            if (map[y] == null) {
                return false;
            }

            for (int x = 0; x < SIZE; x++) {
                mud[y][x] = INF;

                if (map[y].charAt(x) == START) {
                    start.y = y;
                    start.x = x;
                }
            }
        }
        return true;
    }

    static int bfs01() {
        Deque<Pos> deque = new ArrayDeque<>();
        int ans = INF;

        mud[start.y][start.x] = 0;
        deque.addFirst(start);
        do {
            Pos cur = deque.pollFirst();
            int curMud = mud[cur.y][cur.x];

            for (int dir = 0; dir < dy.length; dir++) {
                Pos next = new Pos(cur.y + dy[dir], cur.x + dx[dir]);
                if (next.outOfBoundary()) {
                    continue;
                }

                if (map[next.y].charAt(next.x) == END) {
                    ans = Math.min(ans, curMud);
                    continue;
                }

                boolean isMud = (map[next.y].charAt(next.x) == MUD);
                int nextMud = curMud + (isMud ? 1 : 0);
                if (mud[next.y][next.x] <= nextMud) {
                    continue;
                }

                mud[next.y][next.x] = nextMud;
                if (isMud) {
                    deque.addLast(next);
                } else {
                    deque.addFirst(next);
                }
            }
        } while (!deque.isEmpty());
        return ans;
    }

    public static void main(String[] args) throws IOException {
        StringBuilder result = new StringBuilder();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (takeInput(br)) {
            result.append(bfs01()).append('\n');
            br.readLine();
        }

        System.out.println(result);
    }
}
