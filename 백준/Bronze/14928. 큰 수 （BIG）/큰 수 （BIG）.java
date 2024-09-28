import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        final int DIVISOR = 20000303;
        int num = 0;
        String str = br.readLine();
        for (int i = 0; i < str.length(); ++i) {
            num = num * 10 + (str.charAt(i) - '0');
            num %= DIVISOR;
        }

        System.out.println(num);
    }
}
