import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;

class FastIO {
    static final InputStream IN = System.in;
    static final int EOF = -1;

    public static int nextInt() throws IOException {
        int ret = 0;
        int sign = 1;

        while (true) {
            int ascii = IN.read();
            if (ascii == EOF) {
                throw new IOException();
            }
            if (!Character.isWhitespace(ascii)) {
                if (ascii == '-') {
                    sign = -1;
                } else {
                    ret = ascii - '0';
                }
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
        return ret * sign;
    }

    public static long nextLong() throws IOException {
        long ret = 0;
        long sign = 1;

        while (true) {
            int ascii = IN.read();
            if (ascii == EOF) {
                throw new IOException();
            }
            if (!Character.isWhitespace(ascii)) {
                if (ascii == '-') {
                    sign = -1;
                } else {
                    ret = ascii - '0';
                }
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
        return ret * sign;
    }
}

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans;
    static int max;
    static int lemon;
    static int orange;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        max = FastIO.nextInt();
        lemon = FastIO.nextInt();
        orange = FastIO.nextInt();
        visited = new boolean[max + 1][2];

        backTracking(0, 0);
        bw.write(String.valueOf(ans));
        bw.flush();
    }

    static void backTracking(int cur, int drank) {
        if (cur > max || visited[cur][drank]) {
            return;
        }

        visited[cur][drank] = true;
        ans = Math.max(ans, cur);

        backTracking(cur + lemon, drank);
        backTracking(cur + orange, drank);
        if (drank == 0) {
            backTracking(cur / 2, 1);
        }
    }
}
