import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

class Aliquots {
    boolean[] isAliquot;

    public Aliquots(int num) {
        isAliquot = new boolean[num + 1];
        for (int n = 1; n * n <= num; ++n) {
            if (num % n == 0) {
                isAliquot[n] = true;
                isAliquot[num / n] = true;
            }
        }
    }

    public int getClosest(int toFind) {
        int left = toFind - 1;
        int right = toFind + 1;

        while (true) {
            if (isAliquot[left]) {
                return left;
            }

            if (isAliquot[right]) {
                return right;
            }

            --left;
            ++right;
        }
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int wantTime = Integer.parseInt(input[1]);
        Aliquots aliquots = new Aliquots(wantTime);

        int result = 0;
        for (String num : br.readLine().split(" ")) {
            int period = Integer.parseInt(num);
            if (wantTime % period == 0) {
                continue;
            }

            if (period > wantTime) {
                result += period - wantTime;
            } else {
                result += Math.abs(period - aliquots.getClosest(period));
            }
        }

        System.out.println(result);
    }
}
