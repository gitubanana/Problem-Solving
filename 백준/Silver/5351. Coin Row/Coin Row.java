import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static List<Integer> coins = new ArrayList<>();
    static int maxMoney;

    public static void main(String[] args) throws Exception {
        int testCount = Integer.parseInt(br.readLine());

        while (testCount-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            coins.clear();
            while (st.hasMoreTokens()) {
                coins.add(Integer.parseInt(st.nextToken()));
            }

            maxMoney = Integer.MIN_VALUE;
            backTracking(0, true, 0);
            bw.append(String.valueOf(maxMoney));
            bw.append(System.lineSeparator());
        }

        bw.flush();
    }

    static void backTracking(int curIndex, boolean canSelect, int curMoney) {
        if (curIndex == coins.size()) {
            maxMoney = Math.max(maxMoney, curMoney);
            return;
        }

        backTracking(curIndex + 1, true, curMoney);
        if (canSelect) {
            backTracking(curIndex + 1, false, curMoney + coins.get(curIndex));
        }
    }
}
