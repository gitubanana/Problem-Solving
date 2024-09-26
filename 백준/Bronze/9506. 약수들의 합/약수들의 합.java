import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;


public class Main {

    public static void printLine(int num) {
        int sum = 0;
        ArrayList<Integer> aliquots = new ArrayList<>();

        for (int aliquot = 1; aliquot * aliquot <= num; ++aliquot) {
            if (num % aliquot == 0) {
                int otherOne = num / aliquot;

                sum += aliquot;
                aliquots.add(aliquot);
                if (aliquot != otherOne) {
                    sum += otherOne;
                    aliquots.add(otherOne);
                }
            }
        }

        if (sum - num != num) {
            System.out.printf("%d is NOT perfect.\n", num);
        } else {
            aliquots.sort(Comparator.naturalOrder());
            aliquots.remove(aliquots.size() - 1);

            System.out.printf("%d = ", num);
            for (int i = 0; i < aliquots.size(); ++i) {
                System.out.print(aliquots.get(i));
                if (i != aliquots.size() - 1) {
                    System.out.print(" + ");
                }
            }
            System.out.println();
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
