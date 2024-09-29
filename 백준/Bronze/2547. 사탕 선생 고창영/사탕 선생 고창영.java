import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int testCnt = Integer.parseInt(br.readLine());
        StringBuilder result = new StringBuilder();
        while (testCnt-- > 0) {
            br.readLine();

            int sum = 0;
            int cnt = Integer.parseInt(br.readLine());
            for (int s = 0; s < cnt; ++s) {
                String num = br.readLine();
                int cur = 0;
                for (int i = 0; i < num.length(); ++i) {
                    cur = cur * 10 + (num.charAt(i) - '0');
                    cur %= cnt;
                }

                sum += cur;
                sum %= cnt;
            }

            if (sum == 0) {
                result.append("YES\n");
            } else {
                result.append("NO\n");
            }
        }

        System.out.print(result);
    }
}