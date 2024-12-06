import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

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
        int size = FastIO.nextInt();
        int callTime = FastIO.nextInt();
        Map<Integer, Integer> countByJump = new HashMap<>();

        while (callTime-- > 0) {
            int jump = FastIO.nextInt();

            countByJump.put(jump, countByJump.getOrDefault(jump, 0) + 1);
        }

        int qCnt = FastIO.nextInt();
        long[] prefixSum = makePrefixSum(size, countByJump);

        while (qCnt-- > 0) {
            int left = FastIO.nextInt() + 1;
            int right = FastIO.nextInt() + 1;

            bw.append(String.valueOf(prefixSum[right] - prefixSum[left - 1]));
            bw.newLine();
        }

        bw.flush();
    }

    static long[] makePrefixSum(int size, Map<Integer, Integer> countByJump) {
        long[] prefixSum = new long[size + 1];

        for (Entry<Integer, Integer> entry : countByJump.entrySet()) {
            int jump = entry.getKey();
            int count = entry.getValue();

            for (int i = 1; i < prefixSum.length; i += jump) {
                prefixSum[i] += count;
            }
        }

        for (int i = 1; i < prefixSum.length; i++) {
            prefixSum[i] += prefixSum[i - 1];
        }
        return prefixSum;
    }
}
