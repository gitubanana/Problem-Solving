import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static void writeChNtimes(char ch, int n) throws Exception {
        while (n-- > 0) {
            bw.write(ch);
        }
    }

    static void writeCantor(int n) throws Exception {
        if (n == 1) {
            writeChNtimes('-', 1);
            return;
        }

        int nextN = n / 3;

        writeCantor(nextN);
        writeChNtimes(' ', nextN);
        writeCantor(nextN);
    }

    static void doAllCmd() throws Exception {
        while (true) {
            int n = Integer.parseInt(br.readLine());

            writeCantor((int) Math.pow(3, n));
            bw.write("\n");
        }
    }

    public static void main(String[] args) throws Exception {
        try {
            doAllCmd();
        } catch (Exception e) {
            // 예외 받기만 한다.
        } finally {
            bw.flush();
        }
    }
}
