import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

interface Comp {
    boolean isRight(int a, int b);
}

public class Main {
    static boolean isSorted(int[] arr, Comp comp) {
        for (int i = 1; i < arr.length; i++) {
            if (comp.isRight(arr[i - 1], arr[i])) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCnt = Integer.parseInt(br.readLine());
        StringBuilder result = new StringBuilder();

        result.append("Gnomes:\n");
        for (int t = 0; t < testCnt; t++) {
            int[] arr = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

            result.append(isSorted(arr, (a, b) -> a > b)
                            | isSorted(arr, (a, b) -> a < b)
                            ? "Ordered"
                            : "Unordered")
                    .append('\n');
        }

        System.out.println(result);
    }
}
