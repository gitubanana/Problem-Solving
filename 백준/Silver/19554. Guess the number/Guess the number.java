import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int left = 1;
        int right = sc.nextInt();

        while (true) {
            int mid = (left + right) / 2;

            System.out.printf("? %d\n", mid);
            System.out.flush();

            switch (sc.nextInt()) {
                case 1: // less
                    right = mid - 1;
                    break;
                case -1: // greater
                    left = mid + 1;
                    break;
                case 0: // equal
                    System.out.printf("= %d", mid);
                    System.out.flush();
                    return;
            }
        }
    }
}
