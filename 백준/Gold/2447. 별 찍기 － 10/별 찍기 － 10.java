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
    static final int ALL_SPACE = 4;
    static final char STAR = '*';
    static final char SPACE = ' ';

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static char[][] map;

    public static void main(String[] args) throws IOException {
        int size = FastIO.nextInt();

        map = new char[size][size];
        makeStar(0, 0, 0, size);

        for (int y = 0; y < size; y++) {
            bw.write(map[y]);
            bw.newLine();
        }
        bw.flush();
    }

    static void makeStar(int y, int x, int id, int size) {
        if (id == ALL_SPACE) {
            fillSpace(y, x, size);
            return;
        }

        if (size == 1) {
            map[y][x] = STAR;
            return;
        }

        int nextSize = size / 3;

        id = 0;
        for (int yPlus = 0; yPlus < size; yPlus += nextSize) {
            for (int xPlus = 0; xPlus < size; xPlus += nextSize) {
                makeStar(y + yPlus, x + xPlus, id++, nextSize);
            }
        }
    }

    static void fillSpace(int y, int x, int size) {
        for (int yPlus = 0; yPlus < size; yPlus++) {
            for (int xPlus = 0; xPlus < size; xPlus++) {
                map[y + yPlus][x + xPlus] = SPACE;
            }
        }
    }
}
