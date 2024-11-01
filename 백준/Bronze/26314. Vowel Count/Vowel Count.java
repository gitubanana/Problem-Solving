import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static final String vowels = "aeiou";

    public static void main(String[] args) throws Exception {
        int testCnt = Integer.parseInt(br.readLine());

        while (testCnt-- > 0) {
            String name = br.readLine();

            bw.append(name);
            bw.append("\n");
            bw.append(canMeet(name)+"\n");
        }

        bw.flush();
    }

    static int canMeet(String name) {
        int vowelCnt = 0;

        for (int i = 0; i < name.length(); i++) {
            if (vowels.contains(name.charAt(i)+"")) {
                vowelCnt++;
            }
        }

        if (vowelCnt > name.length() - vowelCnt) {
            return 1;
        }
        return 0;
    }
}