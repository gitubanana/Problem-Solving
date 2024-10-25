import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        String score = br.readLine();
        int halfLength = score.length() / 2;

        int leftScore = 0;
        for (int i = 0; i < halfLength; i++) {
            leftScore += score.charAt(i) - '0';
        }

        int rightScore = 0;
        for (int i = halfLength; i < score.length(); i++) {
            rightScore += score.charAt(i) - '0';
        }

        if (leftScore == rightScore) {
            bw.append("LUCKY");
        } else {
            bw.append("READY");
        }
        bw.flush();
    }
}