import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static class Tree {
        static final int ROOT = 0;
        static final int DIVISOR = 998_244_353;

        ArrayList<Integer>[] edges;
        int[] dp;
        int[] jumpDist;

        public Tree(int vCnt) throws Exception {
            this.edges = new ArrayList[vCnt + 1];
            for (int v = 0; v <= vCnt; ++v) {
                this.edges[v] = new ArrayList<>();
            }

            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int child = 1; child <= vCnt; ++child) {
                int parent = Integer.parseInt(st.nextToken());

                this.edges[parent].add(child);
            }

            st = new StringTokenizer(br.readLine());
            this.jumpDist = new int[vCnt + 1];
            this.jumpDist[ROOT] = 1;
            for (int v = 1; v <= vCnt; ++v) {
                this.jumpDist[v] = Integer.parseInt(st.nextToken());
            }

            this.dp = new int[vCnt + 1];
            for (int v = 0; v <= vCnt; ++v) {
                this.dp[v] = -1;
            }
        }

        public int getJumpCnt() {
            return dfs(ROOT);
        }

        private int dfs(int cur) {
            if (dp[cur] != -1) {
                return dp[cur];
            }

            if (edges[cur].isEmpty()) {
                return 1;
            }

            dp[cur] = 0;
            Queue<Integer> q = new LinkedList<>();

            q.add(cur);
            while (jumpDist[cur]-- > 0) {
                int qSize = q.size();

                while (qSize-- > 0) {
                    int now = q.poll();

                    for (Integer next : edges[now]) {
                        dp[cur] += dfs(next);
                        dp[cur] %= DIVISOR;
                        q.add(next);
                    }
                }
            }

            return dp[cur];
        }
    }

    public static void main(String[] args) throws Exception {
        int vCnt = Integer.parseInt(br.readLine());
        Tree tree = new Tree(vCnt);

        System.out.println(tree.getJumpCnt());
    }
}