import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int copyCnt = Integer.parseInt(br.readLine());

        while (copyCnt-- > 0) {
            int num = Integer.parseInt(br.readLine());

            bw.append(num+" "+num+"\n");
        }

        bw.flush();
    }
}