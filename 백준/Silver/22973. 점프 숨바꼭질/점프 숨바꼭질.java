import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.Set;

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
    static final long MIN_POS = (long) -1e12;
    static final long MAX_POS = (long) 1e12;

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        long start = 0;
        long end = FastIO.nextLong();

        bw.append(String.valueOf(bfs(start, end)));
        bw.flush();
    }

    static int bfs(long start, long end) {
        if (start == end) {
            return 0;
        }

        int dist = 0;
        long move = 1;
        Queue<Long> q = new ArrayDeque<>();
        Set<Long> visited = new HashSet<>();

        visited.add(start);
        q.add(start);
        while (!q.isEmpty()) {
            int qSize = q.size();

            ++dist;
            while (qSize-- > 0) {
                long cur = q.poll();

                for (long next : Arrays.asList(cur + move, cur - move)) {
                    if (outOfRange(next) || visited.contains(next)) {
                        continue;
                    }

                    if (next == end) {
                        return dist;
                    }

                    visited.add(next);
                    q.add(next);
                }
            }
            move += move;
        }
        return -1;
    }

    static boolean outOfRange(long pos) {
        return pos < MIN_POS || pos > MAX_POS;
    }
}
