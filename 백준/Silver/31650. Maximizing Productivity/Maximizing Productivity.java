import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

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
        int qCnt = FastIO.nextInt();
        int[] arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = FastIO.nextInt();
        }
        for (int i = 0; i < size; i++) {
            arr[i] -= FastIO.nextInt() + 1;
        }

        Arrays.sort(arr);
        while (qCnt-- > 0) {
            int wantCount = FastIO.nextInt();
            int toFind = FastIO.nextInt();

            if (wantCount <= size - lowerBound(arr, toFind)) {
                bw.write("YES");
            } else {
                bw.write("NO");
            }
            bw.newLine();
        }
        bw.flush();
    }

    static int lowerBound(int[] arr, int toFind) {
        int left = 0;
        int right = arr.length - 1;
        int pos = Integer.MAX_VALUE;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] >= toFind) {
                pos = Math.min(pos, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return pos;
    }
}
