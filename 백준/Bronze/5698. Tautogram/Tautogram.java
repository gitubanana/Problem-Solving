import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        while (true) {
            String line = br.readLine();
            if (line.equals("*")) {
                break;
            }

            boolean isTautogram = true;
            String[] splited = line.split(" ");
            char first = Character.toUpperCase(splited[0].charAt(0));

            for (int i = 1; i < splited.length; i++) {
                if (first != Character.toUpperCase(splited[i].charAt(0))) {
                    isTautogram = false;
                    break;
                }
            }

            bw.append(isTautogram ? "Y" : "N");
            bw.append("\n");
        }

        bw.flush();
    }
}