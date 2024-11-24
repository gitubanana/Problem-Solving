import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static final int SIZE = 5;
    static final int WANT_APPLE_COUNT = 3;
    static final int WALL = -1;
    static final int EMPTY = 0;
    static final int APPLE = 1;
    static final int[] dy = {-1, 1, 0, 0};
    static final int[] dx = {0, 0, -1, 1};

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int minMoveCount = Integer.MAX_VALUE;
    static int[][] map = new int[SIZE][SIZE];

    public static void main(String[] args) throws Exception {
        for (int y = 0; y < SIZE; y++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int x = 0; x < SIZE; x++) {
                map[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        StringTokenizer st = new StringTokenizer(br.readLine());

        backTracking(
                Integer.parseInt(st.nextToken()),
                Integer.parseInt(st.nextToken()),
                0,
                0
        );
        bw.append(String.valueOf(minMoveCount == Integer.MAX_VALUE ? -1 : minMoveCount));
        bw.flush();
    }

    static void backTracking(int y, int x, int appleCount, int moveCount) {
        if (outOfRange(y, x)
                || map[y][x] == WALL
                || minMoveCount <= moveCount) {
            return;
        }

        if (map[y][x] == APPLE) {
            appleCount++;
        }

        if (appleCount == WANT_APPLE_COUNT) {
            minMoveCount = moveCount;
            return;
        }

        int origin = map[y][x];

        map[y][x] = WALL;
        for (int dir = 0; dir < dy.length; dir++) {
            int nextY = y + dy[dir];
            int nextX = x + dx[dir];

            backTracking(nextY, nextX, appleCount, moveCount + 1);
        }
        map[y][x] = origin;
    }

    static boolean outOfRange(int y, int x) {
        return !(0 <= y && y < SIZE)
                || !(0 <= x && x < SIZE);
    }
}
