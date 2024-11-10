import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int testCnt = Integer.parseInt(br.readLine());

        while (testCnt-- > 0) {
            String line = br.readLine().trim();

            if (line.matches("\\d+")) {
                bw.append(parseNumber(line)+"\n");
            } else {
                bw.append("invalid input\n");
            }
        }

        bw.flush();
    }

    static String parseNumber(String line) {
        int lastZeroIndex = -1;

        for (int i = 0; i < line.length(); i++) {
            if (line.charAt(i) != '0') {
                break;
            }

            lastZeroIndex = i;
        }

        if (lastZeroIndex == line.length() - 1) {
            return "0";
        }

        return line.substring(lastZeroIndex + 1);
    }
}