import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static final String VOWELS = "aeiouAEIOU";
    static final String TURMOIL = "yY";

    public static void main(String[] args) throws Exception {
        int testCnt = Integer.parseInt(br.readLine());

        for (int t = 1; t <= testCnt; t++) {
            bw.append("Case #");
            bw.append(t+": ");

            String name = br.readLine();
            bw.append(
                String.format(
                    "%s is ruled by %s.\n",
                    name,
                    findRuler(name)
                )
            );
        }
        bw.flush();
    }

    static String findRuler(String name) {
        String last = name.substring(name.length() - 1);

        if (TURMOIL.indexOf(last) != -1) {
            return "nobody";
        }

        if (VOWELS.indexOf(last) != -1) {
            return "a queen";
        }

        return "a king";
    }
}