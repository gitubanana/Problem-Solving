import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int testCnt = Integer.parseInt(br.readLine());

        for (int t = 1; t <= testCnt; t++) {
            bw.append("Case #");
            bw.append(t+": ");

            String[] splitedStrings = br.readLine().split("\\s");

            for (int i = splitedStrings.length - 1; i >= 0; i--) {
                bw.append(splitedStrings[i]);
                bw.append(" ");
            }
            bw.append("\n");
        }

        bw.flush();
    }
}