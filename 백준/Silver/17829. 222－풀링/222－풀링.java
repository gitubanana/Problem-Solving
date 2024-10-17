import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static int[][] pixel;

    static int getSecondMin(int y, int x, int size) {
        if (size == 1) {
            return pixel[y][x];
        }

        int halfSize = size / 2;
        int[] rank = {
            getSecondMin(y, x, halfSize),
            getSecondMin(y + halfSize, x, halfSize),
            getSecondMin(y, x + halfSize, halfSize),
            getSecondMin(y + halfSize, x + halfSize, halfSize)
        };

        Arrays.sort(rank);
        return rank[2];
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(br.readLine());

        pixel = new int[size][size];
        for (int y = 0; y < size; ++y) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int x = 0; x < size; ++x) {
                pixel[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(getSecondMin(0, 0, size));
    }
}