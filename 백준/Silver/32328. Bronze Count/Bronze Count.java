import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    final static int MAX_SCORE = 75;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int[] cnt = new int[MAX_SCORE + 1];
        int n = Integer.parseInt(br.readLine());
        while (n-- > 0) {
            int score = Integer.parseInt(br.readLine());

            ++cnt[score];
        }

        int wantRank = 3;
        for (int cur = MAX_SCORE; cur >= 0; --cur) {
            if (cnt[cur] == 0) {
                continue;
            }

            if (--wantRank == 0) {
                System.out.println(cur+" "+cnt[cur]);
                break;
            }
        }
    }
}
