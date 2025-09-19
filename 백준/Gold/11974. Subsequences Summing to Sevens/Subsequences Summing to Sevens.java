import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(br.readLine());
        long[] prefixSum = new long[size + 1];

        for (int i = 1; i <= size; i++) {
            int elem = Integer.parseInt(br.readLine());

            prefixSum[i] = prefixSum[i - 1] + elem;
        }

        int windowSize = size;
        for (; windowSize > 0; windowSize--) {
            for (int i = windowSize; i <= size; i++) {
                if ((prefixSum[i] - prefixSum[i - windowSize]) % 7 == 0) {
                    System.out.println(windowSize);
                    return;
                }
            }
        }

        System.out.println('0');
    }
}
