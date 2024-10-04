import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder result = new StringBuilder();

        while (true) {
            int num = Integer.parseInt(br.readLine());
            if (num == 0) {
                break;
            }

            while (num >= 10) {
                int next = 0;

                while (num > 0) {
                    next += num % 10;
                    num /= 10;
                }

                num = next;
            }

            result.append(num+"\n");
        }

        System.out.print(result);
    }
}
