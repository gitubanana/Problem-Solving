import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int ans = 0;
    static int left, right, maxDiff;
    static List<Integer> arr = new ArrayList<>();

    static void backTracking(int cur, int min, int max, int depth) {
        if (depth == arr.size()) {
            if (min != max && max - min >= maxDiff
                    && left <= cur && cur <= right) {
                ans++;
            }
            return;
        }

        int elem = arr.get(depth);

        backTracking(cur, min, max, depth + 1);
        backTracking(cur + elem, Math.min(min, elem), Math.max(max, elem), depth + 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        st.nextToken();
        left = Integer.parseInt(st.nextToken());
        right = Integer.parseInt(st.nextToken());
        maxDiff = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            arr.add(Integer.parseInt(st.nextToken()));
        }

        backTracking(0, (int) 1e9, 0, 0);
        System.out.println(ans);
    }
}
