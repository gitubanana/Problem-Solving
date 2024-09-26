import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;


public class Main {

    public static void printLine(int num) {
        int sum = 1;
        final int halfNum = num / 2;
        StringBuilder result = new StringBuilder(num+" = 1");

        for (int n = 2; n <= halfNum; ++n) {
            if (num % n == 0) {
                sum += n;
                result.append(" + "+n);
            }
        }

        if (sum != num) {
            System.out.println(num+" is NOT perfect.");
        } else {
            System.out.println(result);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        while (true) {
            int num = Integer.parseInt(br.readLine());
            if (num == -1) {
                break;
            }

            printLine(num);
        }

    }
}
