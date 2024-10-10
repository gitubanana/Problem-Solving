import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(br.readLine());
        int[] levels = new int[size];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < size; ++i) {
            levels[i] = Integer.parseInt(st.nextToken());
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int half = (size + 1) / 2 - 1;
        int step = 0;

        Arrays.sort(levels);
        for (int i = 0; i < size; ++i) {
            if ((i & 1) == 0) {
                bw.append(levels[half - step]+" ");
                ++step;
                continue;
            }

            bw.append(levels[half + step]+" ");
        }

        bw.flush();
    }
}
