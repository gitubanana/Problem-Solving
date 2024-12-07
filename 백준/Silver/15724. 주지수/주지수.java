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

    public static void main(String[] args) throws IOException {
        int ySize = FastIO.nextInt();
        int xSize = FastIO.nextInt();
        int[][] dp = new int[ySize + 1][xSize + 1];

        for (int y = 1; y <= ySize; y++) {
            for (int x = 1; x <= xSize; x++) {
                dp[y][x] = dp[y - 1][x] + dp[y][x - 1] - dp[y - 1][x - 1] + FastIO.nextInt();
            }
        }

        int qCnt = FastIO.nextInt();

        while (qCnt-- > 0) {
            int y1 = FastIO.nextInt() - 1;
            int x1 = FastIO.nextInt() - 1;
            int y2 = FastIO.nextInt();
            int x2 = FastIO.nextInt();

            bw.append(String.valueOf(
                    dp[y2][x2] - dp[y1][x2] - dp[y2][x1] + dp[y1][x1]
            ));
            bw.newLine();
        }
        bw.flush();
    }
}
