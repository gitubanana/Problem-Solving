import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final int[] denominations = {1, 5, 10, 20, 50, 100};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int max = 0;
        int ansIdx = -1;

        for (int i = 0; st.hasMoreTokens(); i++) {
            int cmp = denominations[i] * Integer.parseInt(st.nextToken());
            if (max <= cmp) {
                max = cmp;
                ansIdx = i;
            }
        }

        System.out.println(denominations[ansIdx]);
    }
}
