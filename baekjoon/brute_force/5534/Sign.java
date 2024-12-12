import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int checkCount = Integer.parseInt(br.readLine());
        String name = br.readLine();
        int ans = 0;

        while (checkCount-- > 0) {
            if (canUse(br.readLine(), name)) {
                ans++;
            }
        }
        System.out.println(ans);
    }

    static boolean canUse(String toCheck, String name) {
        int step = 1;
        int end = name.length();

        while (end <= toCheck.length()) {
            if (canUseWith(toCheck, name, end, step)) {
                return true;
            }
            end += name.length() - 1;
            step++;
        }
        return false;
    }

    static boolean canUseWith(String toCheck, String name, int end, int step) {
        for (int start = 0; start + end <= toCheck.length(); start++) {
            if (isTheSame(toCheck, name, start, step)) {
                return true;
            }
        }
        return false;
    }

    static boolean isTheSame(String toCheck, String name, int toCheckIdx, int step) {
        for (int nameIdx = 0; nameIdx < name.length(); nameIdx++) {
            if (toCheck.charAt(toCheckIdx) != name.charAt(nameIdx)) {
                return false;
            }
            toCheckIdx += step;
        }
        return true;
    }
}
