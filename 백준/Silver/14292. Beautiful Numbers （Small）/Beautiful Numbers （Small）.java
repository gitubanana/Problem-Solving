import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static int getMaxBeautifulBase(int number) {
        for (int base = 2; base < number; ++base) {
            if (isBeautiful(number, base)) {
                return base;
            }
        }

        return -1;
    }

    static boolean isBeautiful(int number, int base) {
        while (number > 0) {
            if (number % base != 1) {
                return false;
            }

            number /= base;
        }

        return true;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int testCnt = Integer.parseInt(br.readLine());

        for (int t = 1; t <= testCnt; ++t) {
            int number = Integer.parseInt(br.readLine());

            bw.append("Case #"+t+": ");
            bw.append(getMaxBeautifulBase(number)+"\n");
        }
        bw.flush();
    }
}