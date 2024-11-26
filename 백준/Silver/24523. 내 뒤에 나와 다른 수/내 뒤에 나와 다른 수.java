import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static final int NONE = -1;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int size = Integer.parseInt(br.readLine());
        int[] ans = new int[size];
        Arrays.fill(ans, NONE);

        StringTokenizer st = new StringTokenizer(br.readLine());

        int prevIndex = 0;
        int prevNumber = Integer.parseInt(st.nextToken());
        for (int i = 1; i < size; i++) {
            int curNumber = Integer.parseInt(st.nextToken());
            if (prevNumber == curNumber) {
                continue;
            }

            for (; prevIndex < i; prevIndex++) {
                ans[prevIndex] = i + 1;
            }
            prevNumber = curNumber;
        }

        for (int i = 0; i < size; i++) {
            bw.append(String.valueOf(ans[i]));
            bw.append(' ');
        }
        bw.flush();
    }
}
