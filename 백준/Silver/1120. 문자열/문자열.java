import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        String a = input[0];
        String b = input[1];

        int minDiff = Integer.MAX_VALUE;
        for (int i = 0; i <= b.length() - a.length(); ++i) {
            int curDiff = 0;
            for (int plus = 0; plus < a.length(); ++plus) {
                if (a.charAt(plus) != b.charAt(i + plus)) {
                    ++curDiff;
                }
            }

            minDiff = Math.min(minDiff, curDiff);
        }

        System.out.println(minDiff);
    }
}