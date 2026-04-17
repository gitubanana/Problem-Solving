import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder result = new StringBuilder();

        while (true) {
            String msg = br.readLine();
            if (msg == null) {
                break;
            }

            int start = 0;
            do {
                int end = start + 2;

                result.append((char)Integer.parseInt(msg.substring(start, end), 16));
                start = end;
            } while (start < msg.length());

            result.append('\n');
        }

        System.out.println(result);
    }
}