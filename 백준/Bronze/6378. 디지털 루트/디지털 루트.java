import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder result = new StringBuilder();

        while (true) {
            String num = br.readLine();
            if (num.equals("0")) {
                break;
            }

            while (num.length() > 1) {
                int next = 0;
                for (int i = 0; i < num.length(); i++) {
                    next += num.charAt(i) - '0';
                }

                num = String.valueOf(next);
            }

            result.append(num).append('\n');
        }

        System.out.println(result);
    }
}
