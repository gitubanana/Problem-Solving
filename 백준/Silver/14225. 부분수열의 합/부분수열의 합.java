import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    static int[] arr;
    static boolean[] made;

    static void backTracking(int sum, int depth) {
        if (depth == arr.length) {
            made[sum] = true;
            return;
        }

        backTracking(sum, depth + 1);
        backTracking(sum + arr[depth], depth + 1);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        br.readLine();
        arr = Arrays.stream(br.readLine().split(" "))
                .mapToInt(Integer::parseInt)
                .toArray();
        made = new boolean[Arrays.stream(arr).sum() + 1];

        backTracking(0, 0);

        int ans = 1;
        for (; ans < made.length; ans++) {
            if (!made[ans]) {
                break;
            }
        }

        System.out.println(ans);
    }
}
