import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static class Compression {
        int size;
        double ratio;

        char[][] image;

        public Compression(int size, int ratio) throws Exception {
            this.size = size;
            this.ratio = ratio / 100.0;
            this.image = new char[size][];

            for (int y = 0; y < size; ++y) {
                this.image[y] = br.readLine().toCharArray();
            }
        }

        public void compress() {
            compressImage(0, 0, this.size);
        }

        private void compressImage(int y, int x, int size) {
            double totalCnt = size * size;
            int[] cnt = countZeroAndOne(y, x, size);

            for (int bit = 0; bit <= 1; ++bit) {
                if (isCompressable(cnt[bit] / totalCnt)) {
                    fillBit(bit == 0?'0':'1', y, x, size);
                    return;
                }
            }

            int nextSize = size / 2;

            compressImage(y, x, nextSize);
            compressImage(y + nextSize, x, nextSize);
            compressImage(y, x + nextSize, nextSize);
            compressImage(y + nextSize, x + nextSize, nextSize);
        }

        private int[] countZeroAndOne(int y, int x, int size) {
            int[] cnt = new int[2];

            for (int yPlus = 0; yPlus < size; ++yPlus) {
                for (int xPlus = 0; xPlus < size; ++xPlus) {
                    ++cnt[image[y + yPlus][x + xPlus] - '0'];
                }
            }
            return cnt;
        }

        private boolean isCompressable(double ratio) {
            return ratio >= this.ratio;
        }

        private void fillBit(char bit, int y, int x, int size) {
            for (int yPlus = 0; yPlus < size; ++yPlus) {
                for (int xPlus = 0; xPlus < size; ++xPlus) {
                    image[y + yPlus][x + xPlus] = bit;
                }
            }
        }

        public void print() throws Exception {
            for (int y = 0; y < this.size; ++y) {
                bw.append(new String(this.image[y])+"\n");
            }
        }
    }

    public static void main(String[] args) throws Exception {
        int imageID = 1;

        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int size = Integer.parseInt(st.nextToken());
            if (size == 0) {
                break;
            }

            int ratio = Integer.parseInt(st.nextToken());
            Compression bitmap = new Compression(size, ratio);

            bw.append("Image "+imageID+":\n");
            bitmap.compress();
            bitmap.print();
            ++imageID;
        }

        bw.flush();
    }
}