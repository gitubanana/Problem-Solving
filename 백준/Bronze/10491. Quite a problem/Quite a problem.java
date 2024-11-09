import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        while (true) {
            String line = br.readLine();
            if (line == null) {
                break;
            }

            boolean hasProblem = false;

            for (String word : line.split(" ")) {
                if (word.toUpperCase().contains("PROBLEM")) {
                    hasProblem = true;
                    break;
                }
            }

            bw.append(hasProblem ? "yes" : "no");
            bw.append("\n");
        }
        bw.flush();
    }
}