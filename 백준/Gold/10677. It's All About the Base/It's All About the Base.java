import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final int MIN_BASE = 10;
    static final int MAX_BASE = 15000;

    static long calculate(String num, int base) {
        long ret = 0;

        for (int i = 0; i < num.length(); i++) {
            ret = ret * base + (num.charAt(i) - '0');
        }
        return ret;
    }

    static String findBases(String a, String b) {
        int aBase = MIN_BASE;
        int bBase = MIN_BASE;

        while (aBase <= MAX_BASE && bBase <= MAX_BASE) {
            long aNum = calculate(a, aBase);
            long bNum = calculate(b, bBase);

            if (aNum == bNum) {
                return String.format("%d %d", aBase, bBase);
            }

            if (aNum > bNum) {
                bBase++;
            } else {
                aBase++;
            }
        }

        return "nope";
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder result = new StringBuilder();
        int testCnt = Integer.parseInt(br.readLine());

        for (int t = 0; t < testCnt; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String a = st.nextToken();
            String b = st.nextToken();

            result.append(findBases(a, b))
                    .append('\n');
        }

        System.out.println(result);
    }
}
