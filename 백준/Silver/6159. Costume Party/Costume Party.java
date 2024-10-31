import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int size = Integer.parseInt(st.nextToken());
        int goal = Integer.parseInt(st.nextToken());
        ArrayList<Integer> arr = new ArrayList<>(size);

        while (size-- > 0) {
            arr.add(Integer.parseInt(br.readLine()));
        }

        int ans = 0;
        int left = 0;
        int right = arr.size() - 1;

        arr.sort(Comparator.naturalOrder());
        while (left < right) {
            int sum = arr.get(left) + arr.get(right);

            if (sum <= goal) {
                ans += right - left;
                ++left;
            } else {
                --right;
            }
        }

        bw.append(ans+"\n");
        bw.flush();
    }
}