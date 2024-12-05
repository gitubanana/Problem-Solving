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
    static final int MAX_NUMBER = 118;

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static boolean[] isNotPrime = new boolean[MAX_NUMBER + 1];

    public static void main(String[] args) throws IOException {
        int testCount = FastIO.nextInt();

        initIsNotPrime();
        while (testCount-- > 0) {
            int goal = FastIO.nextInt();

            bw.append(canBeMadeWithTwoPrime(goal) ? "Yes" : "No");
            bw.newLine();
        }

        bw.flush();
    }

    static void initIsNotPrime() {
        for (int mul = 2; mul <= MAX_NUMBER; mul++) {
            if (isNotPrime[mul]) {
                continue;
            }

            for (int num = mul + mul; num <= MAX_NUMBER; num += mul) {
                isNotPrime[num] = true;
            }
        }
    }

    static boolean canBeMadeWithTwoPrime(final int goal) {
        final int half = goal / 2;

        for (int num = 2; num <= half; num++) {
            if (!isNotPrime[num] && !isNotPrime[goal - num]) {
                return true;
            }
        }
        return false;
    }
}
