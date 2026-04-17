import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String num = br.readLine();

        for (int i = 0; i < num.length(); i++) {
            if (i != 0 && (num.length() - i) % 3 == 0) {
                bw.append(',');
            }

            bw.append(num.charAt(i));
        }

        bw.flush();
    }
}
