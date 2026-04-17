import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static char[][] image;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(br.readLine());

        image = new char[size][size];
        for (int y = 0; y < size; y++) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int x = 0; x < size; x++) {
                image[y][x] = st.nextToken().charAt(0);
            }
        }

        System.out.println(countBitsInQuadTree(0, 0, size));
    }

    static boolean isAllTheSame(int startY, int startX, int size) {
        char cmp = image[startY][startX];
        int endY = startY + size;
        int endX = startX + size;

        for (int y = startY; y < endY; y++) {
            for (int x = startX; x < endX; x++) {
                if (cmp != image[y][x]) {
                    return false;
                }
            }
        }
        return true;
    }

    static int countBitsInQuadTree(int y, int x, int size) {
        if (size == 1 || isAllTheSame(y, x, size)) {
            return 2;
        }

        int halfSize = size >> 1;
        int halfY = y + halfSize;
        int halfX = x + halfSize;

        return 1 + countBitsInQuadTree(y, x, halfSize)
                + countBitsInQuadTree(y, halfX, halfSize)
                + countBitsInQuadTree(halfY, x, halfSize)
                + countBitsInQuadTree(halfY, halfX, halfSize);
    }
}
