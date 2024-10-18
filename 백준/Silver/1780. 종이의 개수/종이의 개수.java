import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static int[][] paper;
    static int[]cnt = new int[3];

    static void cutPaper(int y, int x, int size) {
        if (allTheSame(y, x, size)) {
            ++cnt[paper[y][x] + 1];
            return;
        }

        int nextSize = size / 3;
        for (int plusY = 0; plusY < size; plusY += nextSize) {
            for (int plusX = 0; plusX < size; plusX += nextSize) {
                cutPaper(y + plusY, x + plusX, nextSize);
            }
        }
    }

    static boolean allTheSame(int y, int x, int size) {
        int color = paper[y][x];

        for (int plusY = 0; plusY < size; ++plusY) {
            for (int plusX = 0; plusX < size; ++plusX) {
                if (color != paper[y + plusY][x + plusX]) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int size = Integer.parseInt(br.readLine());

        paper = new int[size][size];
        for (int y = 0; y < size; ++y) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            for (int x = 0; x < size; ++x) {
                paper[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        cutPaper(0, 0, size);

        for (int color = 0; color < cnt.length; ++color) {
            bw.append(cnt[color]+"\n");
        }
        bw.flush();
    }
}