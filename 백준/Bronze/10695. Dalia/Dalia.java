import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;

class FastIO {
    static final InputStream IN = System.in;
    static final int EOF = -1;

    public static int nextInt() throws IOException {
        int ret = 0;

        while (true) {
            int ascii = IN.read();
            if (ascii == EOF) {
                throw new IOException();
            }
            if (!Character.isWhitespace(ascii)) {
                ret = ascii - '0';
                break;
            }
        }

        while (true) {
            int ascii = IN.read();
            if (ascii == EOF || Character.isWhitespace(ascii)) {
                break;
            }

            ret = ret * 10 + (ascii - '0');
        }
        return ret;
    }
}

class Pos {
    public final int y;
    public final int x;

    public Pos(int y, int x) {
        this.y = y;
        this.x = x;
    }

    public boolean equals(Pos other) {
        return y == other.y && x == other.x;
    }
}

public class Main {
    static final int[] dy = {-1, -1, 1, 1, -2, -2, 2, 2};
    static final int[] dx = {2, -2, 2, -2, 1, -1, 1, -1};

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int testCount = FastIO.nextInt();

        for (int t = 1; t <= testCount; t++) {
            FastIO.nextInt();
            Pos start = new Pos(FastIO.nextInt(), FastIO.nextInt());
            Pos end = new Pos(FastIO.nextInt(), FastIO.nextInt());

            bw.append("Case ");
            bw.append(String.valueOf(t));
            bw.append(": ");
            bw.append(canReachTheEnd(start, end) ? "YES" : "NO");
            bw.newLine();
        }

        bw.flush();
    }

    static boolean canReachTheEnd(Pos start, Pos end) {
        for (int dir = 0; dir < dy.length; dir++) {
            Pos moved = new Pos(start.y + dy[dir], start.x + dx[dir]);
            if (moved.equals(end)) {
                return true;
            }
        }
        return false;
    }
}
