import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static List<Integer> arr;
    static Set<Integer> set = new TreeSet<>();

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int size = Integer.parseInt(st.nextToken());
        int remainCount = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        arr = new ArrayList<>(size);
        while (st.hasMoreTokens()) {
            arr.add(Integer.parseInt(st.nextToken()));
        }

        backTracking(0, 0, remainCount);
        if (set.isEmpty()) {
            bw.append("-1");
        } else {
            for (Integer num : set) {
                bw.append(num+" ");
            }
        }

        bw.flush();
    }

    static void backTracking(int startIndex, int curSum, int remainCount) {
        if (remainCount == 0) {
            if (isPrime(curSum)) {
                set.add(curSum);
            }
            return;
        }

        for (int i = startIndex; i < arr.size(); i++) {
            backTracking(i + 1, curSum + arr.get(i), remainCount - 1);
        }
    }

    static boolean isPrime(int num) {
        if (num == 1) {
            return false;
        }
    
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
}
