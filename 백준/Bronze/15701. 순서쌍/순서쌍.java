import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    static int getPairCnt(int n) {
        int pairCnt = 0;

        for (int a = 1; a * a <= n; ++a) {
            if (n % a != 0) {
                continue;
            }

            int b = n / a;
            if (a == b) {
                ++pairCnt;
                continue;
            }

            pairCnt += 2;
        }
        return pairCnt;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());

        bw.write(getPairCnt(n)+"\n");
        bw.flush();
    }
}
