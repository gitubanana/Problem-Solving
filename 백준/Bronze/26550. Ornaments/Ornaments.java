import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCnt = sc.nextInt();
        StringBuilder result = new StringBuilder(testCnt * 4);

        for (int t = 0; t < testCnt; t++) {
            int n = sc.nextInt();
            long ans = 0;
            long layer = 0;

            for (int i = 1; i <= n; i++) {
                ans += layer += i; // 우결합
            }

            result.append(ans)
                .append('\n');
        }

        System.out.print(result); // println 주의
    }
}