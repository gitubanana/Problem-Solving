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
}

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        int size = FastIO.nextInt();
        int qCnt = FastIO.nextInt();
        int prev = FastIO.nextInt();
        int[] prefixSum = new int[size];

        for (int i = 1; i < prefixSum.length; i++) {
            int cur = FastIO.nextInt();

            prefixSum[i] = prefixSum[i - 1] + Math.abs(cur - prev);
            prev = cur;
        }

        while (qCnt-- > 0) {
            int start = FastIO.nextInt();
            int end = FastIO.nextInt();

            if (end <= start) {
                bw.append("0");
            } else {
                bw.append(String.valueOf(prefixSum[end - 1] - prefixSum[start - 1]));
            }
            bw.newLine();
        }

        bw.flush();
    }
}
