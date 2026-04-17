import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Pos {
    public int y, x;

    public Pos(int y, int x) {
        this.y = y;
        this.x = x;
    }

    @Override
    public boolean equals(Object other) {
        if (other instanceof Pos) {
            Pos o = (Pos) other;

            return y == o.y && x == o.x;
        }
        return false;
    }
}

public class Main {
    static final int[] dy = {0, 1};
    static final int[] dx = {1, 0};
    static final char VISITED = 'x';

    static boolean outOfBoundary(Pos pos, int size) {
        return pos.y >= size || pos.x >= size;
    }

    static boolean isAbleToGoHome(Pos cur, Pos home, char[][] map) {
        if (cur.equals(home)) {
            return true;
        }

        for (int dir = 0; dir < dy.length; dir++) {
            Pos next = new Pos(cur.y+dy[dir], cur.x+dx[dir]);
            if (outOfBoundary(next, map.length) || map[next.y][next.x] == VISITED) {
                continue;
            }

            map[next.y][next.x] = VISITED;
            if (isAbleToGoHome(next, home, map)) {
                return true;
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(br.readLine());
        char[][] map = new char[size][];

        for (int y = 0; y < size; y++) {
            map[y] = br.readLine().toCharArray();
        }

        System.out.println(isAbleToGoHome(new Pos(0, 0), new Pos(size - 1, size - 1), map) ? "Yes" : "No");
    }
}
