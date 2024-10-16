import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int setSize = Integer.parseInt(st.nextToken());
        int usedCnt = Integer.parseInt(st.nextToken());
        HashSet<String> keywords = new HashSet<>();

        while (setSize-- > 0) {
            keywords.add(br.readLine());
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        while (usedCnt-- > 0) {
            for (String used : br.readLine().split(",")) {
                keywords.remove(used);
            }

            bw.write(keywords.size()+"\n");
        }

        bw.flush();
    }
}