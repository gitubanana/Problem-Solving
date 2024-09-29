import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashSet;

public class Main {

    public static int parseAlpha(String str) {
        int ret = 0;
        for (int i = 0; i < str.length(); ++i) {
            ret = ret * 26 + (str.charAt(i) - 'A');
        }
        return ret;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder result = new StringBuilder();
        int testCnt = Integer.parseInt(br.readLine());
        while (testCnt-- > 0) {
            String[] parts = br.readLine().split("-");
            int one = parseAlpha(parts[0]);
            int two = Integer.parseInt(parts[1]);

            if (Math.abs(one - two) <= 100) {
                result.append("nice\n");
            } else {
                result.append("not nice\n");
            }
        }

        System.out.print(result);
    }
}