import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int sampleTestCnt = Integer.parseInt(st.nextToken());
        int systemTestCnt = Integer.parseInt(st.nextToken());
        boolean samplePassed = isPassed(sampleTestCnt);
        boolean systemPassed = isPassed(systemTestCnt);

        if (samplePassed && systemPassed) {
            bw.append("Accepted");
        } else if (!samplePassed) {
            bw.append("Wrong Answer");
        } else {
            bw.append("Why Wrong!!!");
        }
        bw.flush();
    }

    static boolean isPassed(int cnt) throws Exception {
        boolean passed = true;

        while (cnt-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            if (!st.nextToken().equals(st.nextToken())) {
                passed = false;
            }
        }
        return passed;
    }
}