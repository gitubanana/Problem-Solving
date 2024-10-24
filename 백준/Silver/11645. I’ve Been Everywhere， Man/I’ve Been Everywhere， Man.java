import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(
        new InputStreamReader(System.in)
    );
    static BufferedWriter bw = new BufferedWriter(
        new OutputStreamWriter(System.out)
    );

    public static void main(String[] args) throws Exception {
        int testCnt = Integer.parseInt(br.readLine());

        while (testCnt-- > 0) {
            int tripCnt = Integer.parseInt(br.readLine());
            HashSet<String> cities = new HashSet<>();

            while (tripCnt-- > 0) {
                cities.add(br.readLine());
            }

            bw.append(cities.size()+"\n");
        }

        bw.flush();
    }
}