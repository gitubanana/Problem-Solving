import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static Set<Integer> set = new HashSet<>();
    static List<Integer> numbers = Arrays.asList(1, 5, 10, 50);

    public static void main(String[] args) throws Exception {
        int numberCount = Integer.parseInt(br.readLine());

        backTracking(0, 0, numberCount);
        bw.append(String.valueOf(set.size()));
        bw.flush();
    }

    static void backTracking(int startIndex, int curNumber, int remainCount) {
        if (remainCount == 0) {
            set.add(curNumber);
            return;
        }

        for (int i = startIndex; i < numbers.size(); i++) {
            backTracking(i, curNumber + numbers.get(i), remainCount - 1);
        }
    }
}
