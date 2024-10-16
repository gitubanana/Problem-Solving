import java.util.*;
import java.lang.*;
import java.io.*;

class Main {

    static boolean isDigit(Character ch) {
        return '0' <= ch && ch <= '9';
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        br.readLine();

        long sum = 0;
        String word = br.readLine();

        for (int i = 0; i < word.length(); ++i) {
            if (!isDigit(word.charAt(i))) {
                continue;
            }

            long toAdd = 0;
            while (i < word.length()) {
                if (!isDigit(word.charAt(i))) {
                    break;
                }

                toAdd = toAdd * 10 + (word.charAt(i) - '0');
                ++i;
            }

            sum += toAdd;
        }

        System.out.println(sum);
    }
}