import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static class Pos {
        public int y, x;

        public Pos(int y, int x) {
            this.y = y;
            this.x = x;
        }

        public boolean outOfRange() {
            return y < 0 || y >= SIZE
                || x < 0 || x >= SIZE;
        }
    }

    static final char END = 'E';
    static final char VISITED = 'V';
    static final int[] dy = {-2, -2, -1, 1, 2, 2, 1, -1};
    static final int[] dx = {-1, 1, 2, 2, 1, -1, -2, -2};
    static final int SIZE = 8;
    static final char[][] map = new char[SIZE][SIZE];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static Pos readPos() throws IOException {
        String line = br.readLine();
        String[] tokens = line.split(" ");

        return new Pos(
            SIZE - Integer.parseInt(tokens[1]),
            Integer.parseInt(tokens[0]) - 1
        );
    }

    static int bfs(Pos start) {
        if (map[start.y][start.x] == END) {
            return 0;
        }

        int dist = 1;
        Queue<Pos> q = new ArrayDeque<>();

        map[start.y][start.x] = VISITED;
        q.offer(start);
        do {
            for (int qSize = q.size(); qSize > 0; qSize--) {
                Pos cur = q.poll();
                for (int dir = 0; dir < dy.length; dir++) {
                    Pos next = new Pos(cur.y+dy[dir], cur.x+dx[dir]);
                    if (next.outOfRange() || map[next.y][next.x] == VISITED) {
                        continue;
                    }
    
                    if (map[next.y][next.x] == END) {
                        return dist;
                    }
    
                    map[next.y][next.x] = VISITED;
                    q.offer(next);
                }
            }

            dist++;
        } while (!q.isEmpty());
        return -1;
    }

    public static void main(String[] args) throws IOException {
        Pos start = readPos();
        Pos end = readPos();

        map[end.y][end.x] = END;
        System.out.println(bfs(start));
    }
}