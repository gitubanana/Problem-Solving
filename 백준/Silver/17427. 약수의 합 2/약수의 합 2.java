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
    static final int MAX_NUMBER = 1_000_000;

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] aliquotSum = new int[MAX_NUMBER + 1];

    public static void main(String[] args) throws IOException {
        initAliquotSum();
        int end = FastIO.nextInt();
        long ans = 1;

        for (int num = 2; num <= end; num++) {
            ans += aliquotSum[num] + num + 1;
        }

        bw.append(String.valueOf(ans));
        bw.flush();
    }

    static void initAliquotSum() {
        for (int mul = 2; mul <= MAX_NUMBER; mul++) {
            for (int num = mul * 2; num <= MAX_NUMBER; num += mul) {
                aliquotSum[num] += mul;
            }
        }
    }
}
