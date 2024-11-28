import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Hourglass {
    private static final int FLASK_COUNT = 2;
    private static final int FIRST_LOWER_INDEX = 0;
    private static final int FIRST_UPPER_INDEX = 1;

    private int upperIndex = FIRST_UPPER_INDEX;
    private int lowerIndex = FIRST_LOWER_INDEX;
    private int[] sandAmounts = new int[FLASK_COUNT];

    public Hourglass(int lowerSandAmount) {
        sandAmounts[lowerIndex] = lowerSandAmount;
    }

    public void flip(int flipTime) {
        swapUpperAndLowerIndex();

        if (sandAmounts[upperIndex] < flipTime) {
            sandAmounts[lowerIndex] += sandAmounts[upperIndex];
            sandAmounts[upperIndex] = 0;
            return;
        }

        sandAmounts[lowerIndex] += flipTime;
        sandAmounts[upperIndex] -= flipTime;
    }

    private void swapUpperAndLowerIndex() {
        int savedUpperIndex = upperIndex;

        upperIndex = lowerIndex;
        lowerIndex = savedUpperIndex;
    }

    public int getUpperAmount() {
        return sandAmounts[upperIndex];
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int endTime = Integer.parseInt(st.nextToken());
        int sandAmount = Integer.parseInt(st.nextToken());
        int flipCount = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        int prev = Integer.parseInt(st.nextToken());
        Hourglass hourglass = new Hourglass(sandAmount);

        while (--flipCount > 0) {
            int cur = Integer.parseInt(st.nextToken());

            hourglass.flip(cur - prev);
            prev = cur;
        }

        hourglass.flip(endTime - prev);

        bw.append(String.valueOf(hourglass.getUpperAmount()));
        bw.flush();
    }
}
