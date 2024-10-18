import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String expression = br.readLine();
        if (expression.contains("x")) {
            try {
                String coefficient = expression.split("x")[0];
                if (coefficient.equals("-")) {
                    bw.append("-1");
                } else {
                    bw.append(coefficient.isEmpty() ? "1" : coefficient);
                }
            } catch (Exception e) {
                bw.append("1");
            }
        } else {
            bw.append("0");
        }

        bw.flush();
    }
}