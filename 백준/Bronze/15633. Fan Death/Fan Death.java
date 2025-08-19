import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int ans = 0;

        for (int div = 1; div * div <= n; div++) {
            int quotient = n / div;
            if (div * quotient != n) {
                continue;
            }

            ans += div;
            if (div != quotient) {
                ans += quotient;
            }
        }

        System.out.println(ans * 5 - 24);
    }
}