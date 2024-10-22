import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final int MAX_NUMBER = 200;

    public static void main(String[] args) throws Exception {
        int cmp = Integer.parseInt(br.readLine());
        int prev = 0;

        boolean[] isNotPrime = new boolean[MAX_NUMBER];
        for (int cur = 2; cur < MAX_NUMBER; ++cur) {
            if (isNotPrime[cur]) {
                continue;
            }

            int bigger = prev * cur;
            if (bigger > cmp) {
                System.out.println(bigger);
                break;
            }

            for (int mul = cur * 2; mul < MAX_NUMBER; mul += cur) {
                isNotPrime[mul] = true;
            }
            prev = cur;
        }
    }
}