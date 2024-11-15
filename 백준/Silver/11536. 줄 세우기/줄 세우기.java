import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static final int SAME = 0;

    public static void main(String[] args) throws Exception {
        int size = Integer.parseInt(br.readLine());
        List<String> names = new ArrayList<>(size);

        while (size-- > 0) {
            names.add(br.readLine());
        }

        if (isDecreasing(names)) {
            bw.append("DECREASING");
        } else if (isIncreasing(names)) {
            bw.append("INCREASING");
        } else {
            bw.append("NEITHER");
        }

        bw.flush();
    }

    static boolean isDecreasing(List<String> names) {
        for (int i = 1; i < names.size(); i++) {
            String prev = names.get(i - 1);
            String cur = names.get(i);

            if (prev.compareTo(cur) <= SAME) {
                return false;
            }
        }
        return true;
    }

    static boolean isIncreasing(List<String> names) {
        for (int i = 1; i < names.size(); i++) {
            String prev = names.get(i - 1);
            String cur = names.get(i);

            if (prev.compareTo(cur) >= SAME) {
                return false;
            }
        }
        return true;
    }
}