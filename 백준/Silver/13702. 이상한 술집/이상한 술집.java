import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static int getDrinkableCnt(long[] beers, long amount) {
        int cnt = 0;

        for (int i = 0; i < beers.length; ++i) {
            cnt += beers[i] / amount;
        }
        return cnt;
    }

    static long getMaxDrinkableAmount(long[] beers, int friendCnt) {
        long maxAmount = 0;
        long left = 0;
        long right = Integer.MAX_VALUE;

        while (left <= right) {
            long mid = (left + right) / 2;

            if (getDrinkableCnt(beers, mid) >= friendCnt) {
                maxAmount = Math.max(maxAmount, mid);
                left = mid + 1;
                continue;
            }

            right = mid - 1;
        }
        return maxAmount;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int beerCnt = Integer.parseInt(st.nextToken());
        int friendCnt = Integer.parseInt(st.nextToken());
        long[] beers = new long[beerCnt];

        for (int i = 0; i < beerCnt; ++i) {
            beers[i] = Integer.parseInt(br.readLine());
        }

        bw.write(getMaxDrinkableAmount(beers, friendCnt) + "\n");
        bw.flush();
    }
}
