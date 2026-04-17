import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int ans = 0;

        for (; num != 1; ans++) {
            if ((num & 1) == 1) {
                num += (num << 1) + 1;
            } else {
                num >>= 1;
            }
        }

        System.out.println(ans);
    }
}