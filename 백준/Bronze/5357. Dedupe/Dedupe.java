import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int testCnt = Integer.parseInt(br.readLine());

        while (testCnt-- > 0) {
            String line = br.readLine();

            for (int i = 0; i < line.length(); i++) {
                char ch = line.charAt(i);

                bw.append(ch);
                while (true) {
                    int next = i + 1;
                    if (next == line.length()
                       || ch != line.charAt(next)) {
                        break;
                    }

                    i++;
                }
            }
            bw.append("\n");
        }

        bw.flush();
    }
}