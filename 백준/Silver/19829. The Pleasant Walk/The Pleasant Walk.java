import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        br.readLine();
        StringTokenizer st = new StringTokenizer(br.readLine());
        int prev = 0;
        int curLength = 0;
        int maxLength = 1;

        while (st.hasMoreTokens()) {
            int cur = Integer.parseInt(st.nextToken());
            if (prev == cur) {
                curLength = 0;
            }

            maxLength = Math.max(maxLength, ++curLength);
            prev = cur;
        }

        bw.append(maxLength+"\n");
        bw.flush();
    }
}