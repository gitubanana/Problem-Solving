import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final int MIN_BASE = 10;
    static final int MAX_BASE = 15000;
    static final int NOT_FOUND = -404;

    static long calculate(String num, int base) {
        long ret = 0;

        for (int i = 0; i < num.length(); i++) {
            ret = ret * base + (num.charAt(i) - '0');
        }
        return ret;
    }

    static int binarySearch(String num, long toFind) {
        int left = MIN_BASE;
        int right = MAX_BASE;

        while (left <= right) {
            int mid = (left + right) / 2;
            long cmp = calculate(num, mid);

            if (cmp == toFind) {
                return mid;
            }

            if (cmp > toFind) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return NOT_FOUND;
    }

    static String findBases(String a, String b) {
        for (int aBase = MIN_BASE; aBase <= MAX_BASE; aBase++) {
            int bBase = binarySearch(b, calculate(a, aBase));
            if (bBase != NOT_FOUND) {
                return String.format("%d %d", aBase, bBase);
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
