import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
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
    static final int REMOVED = 0;

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ans;
    static int[] arr;
    static int wantScore;
    static boolean[] used;
    static List<Integer> removedIndexes = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        int size = FastIO.nextInt();

        wantScore = FastIO.nextInt();
        arr = new int[size];
        used = new boolean[size + 1];
        for (int i = 0; i < size; i++) {
            int num = FastIO.nextInt();
            if (num == REMOVED) {
                removedIndexes.add(i);
                continue;
            }

            arr[i] = num;
            used[num] = true;
        }

        backTracking(0);
        bw.write(String.valueOf(ans));
        bw.flush();
    }

    static void backTracking(int depth) {
        if (depth == removedIndexes.size()) {
            if (wantScore == calculateScore()) {
                ans++;
            }
            return;
        }

        int index = removedIndexes.get(depth);

        for (int num = 1; num < used.length; num++) {
            if (used[num]) {
                continue;
            }

            used[num] = true;
            arr[index] = num;
            backTracking(depth + 1);
            used[num] = false;
        }
    }

    static int calculateScore() {
        int score = 0;

        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] < arr[j]) {
                    score++;
                }
            }
        }
        return score;
    }
}
