import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        for (int t = 1; true; t++) {
            int cityCnt = Integer.parseInt(br.readLine());
            if (cityCnt == 0) {
                break;
            }

            HashSet<String> set = new HashSet<>();
            while (cityCnt-- > 0) {
                set.add(br.readLine());
            }

            bw.append("Week "+t+" "+set.size()+"\n");
        }
        bw.flush();
    }
}