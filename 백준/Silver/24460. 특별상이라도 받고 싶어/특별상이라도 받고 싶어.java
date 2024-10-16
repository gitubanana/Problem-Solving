import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static int[][] seats;

    static int getSecondMin(int y, int x, int size) {
        if (size == 1) {
            return seats[y][x];
        }

        int halfSize = size / 2;
        int[] nextFour = new int[4];

        nextFour[0] = getSecondMin(y, x, halfSize);
        nextFour[1] = getSecondMin(y + halfSize, x, halfSize);
        nextFour[2] = getSecondMin(y, x + halfSize, halfSize);
        nextFour[3] = getSecondMin(y + halfSize, x + halfSize, halfSize);

        Arrays.sort(nextFour);
        return nextFour[1];
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(br.readLine());

        seats = new int[size][size];
        for (int y = 0; y < size; ++y) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int x = 0; x < size; ++x) {
                seats[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(getSecondMin(0, 0, size));
    }
}