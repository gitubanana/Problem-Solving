import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        StringBuilder code = new StringBuilder(br.readLine());

        while (true) {
            String line = br.readLine();
            if (line == null) {
                break;
            }

            code.append("\n");
            code.append(line);
        }

        String all = code.toString();

        while (all.contains("BUG")) {
            all = all.replaceAll("BUG", "");
        }

        bw.append(all);
        bw.flush();
    }
}