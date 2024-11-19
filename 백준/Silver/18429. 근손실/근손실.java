import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int LEAST_ALIVE_AMOUNT = 500;
    static int lossAmount;
    static int okCount;
    static boolean[] visited;
    static List<Integer> addAmounts;

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int equipmentCount = Integer.parseInt(st.nextToken());

        lossAmount = Integer.parseInt(st.nextToken());
        addAmounts = new ArrayList<>(equipmentCount);

        st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            addAmounts.add(Integer.parseInt(st.nextToken()));
        }

        visited = new boolean[equipmentCount];
        backTracking(LEAST_ALIVE_AMOUNT, 0);
        bw.append(String.valueOf(okCount)).append("\n");
        bw.flush();
    }

    static void backTracking(int curAmount, int depth) {
        if (curAmount < LEAST_ALIVE_AMOUNT) {
            return;
        }

        if (depth == addAmounts.size()) {
            okCount++;
            return;
        }

        for (int i = 0; i < addAmounts.size(); i++) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            backTracking(curAmount + addAmounts.get(i) - lossAmount, depth + 1);
            visited[i] = false;
        }
    }
}
