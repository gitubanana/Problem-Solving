import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String text = br.readLine();
        boolean[] banned = new boolean[26];
        int ans = 26;

        for (int i = 0; i < text.length(); i++) {
            int dist = ('i' - text.charAt(i) + 26) % 26;
            if (banned[dist]) {
                continue;
            }

            ans--;
            banned[dist] = true;
        }

        System.out.println(ans == 0 ? "impossible" : String.valueOf(ans));
    }
}