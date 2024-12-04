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
    static final int MAX_NUMBER = 10_000_000;

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] divisorCounts = new int[MAX_NUMBER + 1];

    public static void main(String[] args) throws IOException {
        int qCnt = FastIO.nextInt();

        initDivisorCounts();
        while (qCnt-- > 0) {
            int start = FastIO.nextInt();
            int end = FastIO.nextInt();

            bw.append(String.valueOf(findBiggestDivisorCount(start, end)));
            bw.newLine();
        }

        bw.flush();
    }

    static void initDivisorCounts() {
        for (int divisor = 2; divisor <= MAX_NUMBER; divisor++) {
            for (int num = divisor; num <= MAX_NUMBER; num += divisor) {
                divisorCounts[num]++;
            }
        }
    }

    static int findBiggestDivisorCount(int start, int end) {
        int maxCount = 0;

        for (int num = start; num <= end; num++) {
            maxCount = Math.max(maxCount, divisorCounts[num]);
        }
        return maxCount + 1;
    }
}
