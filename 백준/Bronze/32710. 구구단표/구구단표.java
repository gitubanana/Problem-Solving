import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int number = Integer.parseInt(br.readLine());

        bw.append(isInGooGooDan(number) ? "1" : "0");
        bw.flush();
    }

    static boolean isInGooGooDan(int number) {
        if (number == 1) {
            return true;
        }

        for (int dan = 2; dan <= 9; dan++) {
            if (number % dan == 0 && number / dan <= 9) {
                return true;
            }
        }

        return false;
    }
}
