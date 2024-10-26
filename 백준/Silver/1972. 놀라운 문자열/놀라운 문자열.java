import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static final String MESSAGE_FORMAT = "%s is %ssurprising.%n";
    static final String STOP = "*";

    public static void main(String[] args) throws Exception {
        while (true) {
            String line = br.readLine();
            if (line.equals(STOP)) {
                break;
            }

            bw.append(String.format(
                MESSAGE_FORMAT,
                line,
                isSurprising(line) ? "" : "NOT "
            ));
        }

        bw.flush();
    }

    static boolean isSurprising(String line) {
        for (int step = 1; step < line.length(); step++) {
            if (isDuplicated(line, step)) {
                return false;
            }
        }
        return true;
    }

    static boolean isDuplicated(String line, int step) {
        int first = 0;
        HashSet<String> set = new HashSet<>();

        while (true) {
            int second = first + step;
            if (second >= line.length()) {
                break;
            }

            String check = String.valueOf(line.charAt(first)) + String.valueOf(line.charAt(second));
            if (set.contains(check)) {
                return true;
            }

            set.add(check);
            ++first;
        }
        return false;
    }
}