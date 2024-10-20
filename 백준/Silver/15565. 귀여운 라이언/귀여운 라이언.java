import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int LION = 1;

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int size = Integer.parseInt(st.nextToken());
        int lionCnt = Integer.parseInt(st.nextToken());
        int[] dolls = new int[size];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < size; ++i) {
            dolls[i] = Integer.parseInt(st.nextToken());
        }

        int lionMinSize = Integer.MAX_VALUE;
        int[] cntByType = new int[3];
        int left = 0;
        int right = 0;

        while (left <= right) {
            if (cntByType[LION] >= lionCnt) {
                lionMinSize = Math.min(lionMinSize, right - left);
                --cntByType[dolls[left]];
                ++left;
                continue;
            }

            if (right == size) {
                break;
            }

            ++cntByType[dolls[right]];
            ++right;
        }

        System.out.println(lionMinSize == Integer.MAX_VALUE ? -1 : lionMinSize);
    }
}