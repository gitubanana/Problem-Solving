import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int n = Integer.parseInt(br.readLine());

        bw.append(fact(n)+"\n");
        bw.flush();
    }

    static long fact(int n) {
        long result = 1;

        for (int i = 2; i <= n; i++) {
            result *= i;
        }
        return result;
    }
}