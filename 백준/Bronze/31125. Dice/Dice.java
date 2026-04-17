import java.util.*;
import java.lang.*;
import java.io.*;

// minimum : n + m
// maximum : n * f + m

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCnt = Integer.parseInt(br.readLine());

        for (int t = 0; t < testCnt; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int expected = Integer.parseInt(st.nextToken());
            int diceCnt = Integer.parseInt(st.nextToken());
            int faceCnt = Integer.parseInt(st.nextToken());
            int bias = Integer.parseInt(st.nextToken());
            int minimum = diceCnt + bias;
            int maximum = diceCnt * faceCnt + bias;

            System.out.println(
                (minimum <= expected && expected <= maximum)
                    ? "YES"
                    : "NO"
            );
        }
    }
}