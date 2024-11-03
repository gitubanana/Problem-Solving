import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int maxSnow;
    static int endTime;
    static List<Integer> snows = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int snowCnt = Integer.parseInt(st.nextToken());
        endTime = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        while (snowCnt-- > 0) {
            snows.add(Integer.parseInt(st.nextToken()));
        }

        backTracking(1, 0, 1);
        backTracking(0, 1, 1);

        bw.append(maxSnow+"\n");
        bw.flush();
    }

    static void backTracking(int curSnow, int curPos, int curTime) {
        if (curPos >= snows.size() || curTime > endTime) {
            return;
        }

        curSnow += snows.get(curPos);
        maxSnow = Math.max(maxSnow, curSnow);

        backTracking(curSnow, curPos + 1, curTime + 1);
        backTracking(curSnow / 2, curPos + 2, curTime + 1);
    }
}