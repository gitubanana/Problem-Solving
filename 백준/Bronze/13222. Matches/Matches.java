import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int testCnt = Integer.parseInt(st.nextToken());
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        int maxLength = (int)(Math.pow(w, 2) + Math.pow(h, 2));
        StringBuilder result = new StringBuilder();

        for (int t = 0; t < testCnt; t++) {
            int length = (int)Math.pow(Integer.parseInt(br.readLine()), 2);

            result.append(
                length <= maxLength
                ? "YES"
                : "NO"
            ).append('\n');
        }

        System.out.println(result);
    }
}