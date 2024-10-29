import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int testCnt = Integer.parseInt(br.readLine());

        for (int t = 1; t <= testCnt; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine()); st.nextToken();
            int goal = Integer.parseInt(st.nextToken());
            ArrayList<Integer> arr = new ArrayList<>();

            st = new StringTokenizer(br.readLine());
            while (st.hasMoreTokens()) {
                arr.add(Integer.parseInt(st.nextToken()));
            }

            bw.append("Case #"+t+": ");
            bw.append(twoPointer(arr, goal)+"\n");
        }

        bw.flush();
    }

    static int twoPointer(ArrayList<Integer> arr, int goal) {
        int left = 0;
        int right = arr.size() - 1;
        int sameCnt = 0;

        while (left < right) {
            int sum = arr.get(left) + arr.get(right);

            if (sum == goal) {
                ++sameCnt;
                ++left;
            } else if (sum > goal) {
                --right;
            } else {
                ++left;
            }
        }
        return sameCnt;
    }
}