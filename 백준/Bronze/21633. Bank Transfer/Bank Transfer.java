import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int moneyToTransfer = Integer.parseInt(br.readLine());
        double commission = calculateCommission(moneyToTransfer);

        bw.append(String.format(
                "%.2f",
                commission
        ));
        bw.flush();
    }

    static double calculateCommission(int moneyToTransfer) {
        final int BASE_FEE = 25;
        final double COMMISSION_PERCENTAGE = 0.01;
        final double MIN_FEE = 100;
        final double MAX_FEE = 2000;

        double commission = BASE_FEE + moneyToTransfer * COMMISSION_PERCENTAGE;

        if (commission > MAX_FEE) {
            return MAX_FEE;
        }

        if (commission < MIN_FEE) {
            return MIN_FEE;
        }

        return commission;
    }
}
