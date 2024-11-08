import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;

        while (true) {
            String line = br.readLine();
            if (line == null) {
                break;
            }

            StringTokenizer st = new StringTokenizer(line);
            st.nextToken();

            while (st.hasMoreTokens()) {
                int cmp = Integer.parseInt(st.nextToken());

                max = Math.max(max, cmp);
                min = Math.min(min, cmp);
            }
        }

        bw.append(min+" "+max);
        bw.flush();
    }
}