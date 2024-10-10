import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static final int PEAK_MIN = 129;
    static final int PEAK_MAX = 138;

    static boolean isPeak(int alcohol) {
        return (PEAK_MIN <= alcohol && alcohol <= PEAK_MAX);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int arrSize = Integer.parseInt(st.nextToken());
        int windowSize = Integer.parseInt(st.nextToken());
        int[] beer = new int[arrSize];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < arrSize; ++i) {
            beer[i] = Integer.parseInt(st.nextToken());
        }

        int peakCnt = 0;
        int alcohol = 0;

        for (int i = 0; i < windowSize; ++i) {
            alcohol += beer[i];

            if (isPeak(alcohol)) {
                ++peakCnt;
            }
        }

        for (int i = windowSize; i < arrSize; ++i) {
            alcohol -= beer[i - windowSize];
            alcohol += beer[i];

            if (isPeak(alcohol)) {
                ++peakCnt;
            }
        }

        System.out.println(peakCnt);
    }
}