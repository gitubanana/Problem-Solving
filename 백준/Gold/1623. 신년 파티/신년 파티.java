import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    static int[][] dp;
    static ArrayList<Integer>[] edges;
    static ArrayList<Integer> attendees = new ArrayList<>();
    static final int SKIPPED = 0;
    static final int SELECTED = 1;
    static final int ROOT = 1;

    static void dfs(int cur) {
        for (Integer next : edges[cur]) {
            dfs(next);

            dp[cur][SELECTED] += dp[next][SKIPPED];
            dp[cur][SKIPPED] += Math.max(
                    dp[next][SKIPPED],
                    dp[next][SELECTED]
            );
        }
    }

    static void findAttendee(int cur, boolean isAttendee) {
        if (isAttendee) {
            attendees.add(cur);
        }

        for (Integer next : edges[cur]) {
            if (isAttendee) {
                findAttendee(next, false);
                continue;
            }

            findAttendee(next, dp[next][SKIPPED] < dp[next][SELECTED]);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int vCnt = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        dp = new int[vCnt + 1][2];
        edges = new ArrayList[vCnt + 1];
        for (int v = 1; v <= vCnt; ++v) {
            dp[v][SELECTED] = Integer.parseInt(st.nextToken());
            edges[v] = new ArrayList<>();
        }

        st = new StringTokenizer(br.readLine());
        for (int child = 2; child <= vCnt; ++child) {
            int parent = Integer.parseInt(st.nextToken());

            edges[parent].add(child);
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        dfs(ROOT);
        bw.write(dp[ROOT][SELECTED] + " " + dp[ROOT][SKIPPED] + "\n");

        findAttendee(ROOT, true);
        attendees.sort(Comparator.naturalOrder());
        for (Integer v : attendees) {
            bw.write(v + " ");
        }
        bw.write("-1\n");

        attendees.clear();
        findAttendee(ROOT, false);
        attendees.sort(Comparator.naturalOrder());
        for (Integer v : attendees) {
            bw.write(v + " ");
        }
        bw.write("-1");

        bw.flush();
    }
}
