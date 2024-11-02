import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int size = Integer.parseInt(br.readLine());

        while (size-- > 0) {
            String name = br.readLine();
            if (name.contains("S")) {
                bw.append(name);
                break;
            }
        }

        bw.flush();
    }
}