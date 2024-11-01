import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static final int ALPHABET_COUNT = 26;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static String origin;
    static int luckyCount = 0;
    static int[] alphaCnt = new int[ALPHABET_COUNT];

    public static void main(String[] args) throws Exception {
        origin = br.readLine();
        for (int i = 0; i < origin.length(); i++) {
            ++alphaCnt[origin.charAt(i) - 'a'];
        }

        backTracking(-1, 0);

        bw.append(luckyCount+"\n");
        bw.flush();
    }

    static void backTracking(int prev, int depth) {
        if (depth == origin.length()) {
            luckyCount++;
            return;
        }

        for (int ch = 0; ch < ALPHABET_COUNT; ch++) {
            if (alphaCnt[ch] == 0 || ch == prev) {
                continue;
            }

            alphaCnt[ch]--;
            backTracking(ch, depth + 1);
            alphaCnt[ch]++;
        }
    }
}