import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static double comb(int n, int r) {
        r = Math.min(r, n - r);

        double permutation = 1;
        double factorial = 1;

        for (int i = 0; i < r; ++i) {
            permutation *= (n - i);
            factorial *= (i + 1);
        }

        return permutation / factorial;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()) - 1;
        int r = Integer.parseInt(st.nextToken()) - 1;

        bw.write((int)comb(n, r)+"\n");
        bw.flush();
    }
}
