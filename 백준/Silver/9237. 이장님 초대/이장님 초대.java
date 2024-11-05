import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int size = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        List<Integer> arr = new ArrayList<>(size);

        while (size-- > 0) {
            arr.add(Integer.parseInt(st.nextToken()));
        }

        long ans = 0;
        int curTime = 1;

        arr.sort(Comparator.reverseOrder());
        for (Integer daysToGrow : arr) {
            ans = Math.max(ans, curTime + daysToGrow);
            curTime++;
        }

        bw.append((ans + 1)+"\n");
        bw.flush();
    }
}