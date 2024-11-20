import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

class SlatConverter {
    private static final char BROKEN = '1';
    private static final int POSITION_COUNT = 2;
    private static final int COUNT_TO_MAKE_SWORD = 2;
    private static final int TOP_BOTTOM_INDEX = 1;
    private static final int LEFT_RIGHT_INDEX = 3;

    private int[] countByPosition = new int[POSITION_COUNT * 2];

    public void countNotBroken(String slats) {
        for (int i = 0; i < slats.length(); i++) {
            if (slats.charAt(i) == BROKEN) {
                continue;
            }

            countByPosition[i | 1]++;
        }
    }

    public int toSwordCount() {
        return Math.min(
                countByPosition[TOP_BOTTOM_INDEX],
                countByPosition[LEFT_RIGHT_INDEX]
                ) / COUNT_TO_MAKE_SWORD;
    }

    public int remainTopBottomCount() {
        return countByPosition[TOP_BOTTOM_INDEX] - (toSwordCount() * COUNT_TO_MAKE_SWORD);
    }

    public int remainLeftRightCount() {
        return countByPosition[LEFT_RIGHT_INDEX] - (toSwordCount() * COUNT_TO_MAKE_SWORD);
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int slatCount = Integer.parseInt(br.readLine());
        SlatConverter slatConverter = new SlatConverter();

        while (slatCount-- > 0) {
            slatConverter.countNotBroken(br.readLine());
        }

        bw.append(String.format(
                "%d %d %d",
                slatConverter.toSwordCount(),
                slatConverter.remainTopBottomCount(),
                slatConverter.remainLeftRightCount()
        ));
        bw.flush();
    }
}
