import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int emojiCnt = Integer.parseInt(br.readLine());
        int shouldUseCnt = 0;

        while (emojiCnt-- > 0) {
            int day = Integer.parseInt(br.readLine().split("-")[1]);

            if (day <= 90) {
                shouldUseCnt++;
            }
        }

        bw.append(shouldUseCnt+"\n");
        bw.flush();
    }
}