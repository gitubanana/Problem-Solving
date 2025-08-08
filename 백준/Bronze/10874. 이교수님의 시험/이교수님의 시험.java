import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static boolean isCheating() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int pId = 1; st.hasMoreTokens(); pId++) {
            int answer = (pId - 1) % 5 + 1;
            int chosen = Integer.parseInt(st.nextToken());

            if (answer != chosen) {
                return false;
            }
        }
        return true;
    }
    
    public static void main(String[] args) throws IOException {
        int studentCnt = Integer.parseInt(br.readLine());

        for (int sId = 1; sId <= studentCnt; sId++) {
            if (isCheating()) {
                System.out.println(sId);
            }
        }
    }
}