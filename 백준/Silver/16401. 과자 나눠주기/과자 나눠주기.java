import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static class Snacks {
        int[] lengths;

        Snacks(int size) throws Exception {
            StringTokenizer st = new StringTokenizer(br.readLine());

            this.lengths = new int[size];
            for (int i = 0; i < size; ++i) {
                this.lengths[i] = Integer.parseInt(st.nextToken());
            }

            Arrays.sort(this.lengths);
        }

        int giveCnt(int giveLength) {
            int cnt = 0;

            for (int i = lengths.length - 1; i >= 0; --i) {
                if (lengths[i] < giveLength) {
                    break;
                }

                cnt += lengths[i] / giveLength;
            }
            return cnt;
        }
    }
    
    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int nephewCnt = Integer.parseInt(st.nextToken());
        int snackCnt = Integer.parseInt(st.nextToken());
        Snacks snacks = new Snacks(snackCnt);

        int maxLength = 0;
        int left = 1;
        int right = 1000000000;
        while (left <= right) {
            int giveLength = (left + right) / 2;

            if (snacks.giveCnt(giveLength) >= nephewCnt) {
                maxLength = giveLength;
                left = giveLength + 1;
            } else {
                right = giveLength - 1;
            }
        }

        System.out.println(maxLength);
    }
}