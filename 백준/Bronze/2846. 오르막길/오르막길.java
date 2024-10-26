import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws Exception {
        int size = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int prev = Integer.parseInt(st.nextToken());
        int start = prev;
        int ans = 0;

        while (--size > 0) {
            int cur = Integer.parseInt(st.nextToken());

            if (prev >= cur) {
                ans = Math.max(ans, prev - start);
                start = cur;
            }

            prev = cur;
        }

        ans = Math.max(ans, prev - start);
        System.out.println(ans);
    }
}