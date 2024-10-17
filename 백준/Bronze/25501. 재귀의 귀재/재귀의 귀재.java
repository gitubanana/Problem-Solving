import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int checkCnt = Integer.parseInt(br.readLine());

        while (checkCnt-- > 0) {
            String toCheck = br.readLine();
            int halfSize = toCheck.length() / 2;
            int callCnt = 0;

            for (int i = 0; i < halfSize; ++i) {
                if (toCheck.charAt(i) != toCheck.charAt(toCheck.length() - i - 1)) {
                    break;
                }

                ++callCnt;
            }

            int isPalindrome = 0;
            if (callCnt == halfSize) {
                isPalindrome = 1;
            }
            ++callCnt;

            bw.write(isPalindrome+" "+callCnt+"\n");
        }

        bw.flush();
    }
}