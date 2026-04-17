import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class Main {
    static int[] countAlphabet() {
        int[] cnt = new int[26];
        char ch;
        
        try {
            while (Character.isAlphabetic(ch = (char)System.in.read())) {
                cnt[ch - 'a']++;
            }
        } catch (IOException e) {
            //
        }
        return cnt;
    }

    static void solveOddString() {
        int[] cnt = countAlphabet();
        int oddCounter = 0;
        int chCnt = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] == 0) {
                continue;
            }

            oddCounter |= ((cnt[i] & 1) << chCnt++);
        }

        String output = "0/1";
        if (oddCounter == 0) {
            output = "0";
        } else if (oddCounter == (1 << chCnt) - 1) {
            output = "1";
        }

        System.out.println(output);
    }

    public static void main(String[] args) {
        solveOddString();
    }
}