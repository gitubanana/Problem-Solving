import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int testCnt = Integer.parseInt(br.readLine());

        while (testCnt-- > 0) {
            br.readLine();
            int sum = 0;
            StringTokenizer st = new StringTokenizer(br.readLine());

            while (st.hasMoreTokens()) {
                sum += Integer.parseInt(st.nextToken());
            }

            bw.append(sum+"\n");
        }

        bw.flush();
    }
}