import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static final int PURCHASE_GRAM = 1_000;

    public static void main(String[] args) throws Exception {
        char[] number = br.readLine().toCharArray();
        int length = number.length;
        long sum = 0;

        while (length-- > 0) {
            sum += toInteger(number);
            moveLastToFirst(number);
        }

        bw.append(sum+"\n");
        bw.flush();
    }

    static int toInteger(char[] number) {
        int ret = 0;

        for (int i = 0; i < number.length; i++) {
            ret = ret * 10 + (number[i] - '0');
        }
        return ret;
    }

    static void moveLastToFirst(char[] str) {
        char last = str[str.length - 1];

        for (int i = str.length - 1; i > 0; i--) {
            str[i] = str[i - 1];
        }
        str[0] = last;
    }
}