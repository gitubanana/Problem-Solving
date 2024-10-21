import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static class Tree {
        static final int WHITE = 0;
        static final int BLACK = 1;
        static final int COLOR_CNT = 2;
        static final int ROOT = 0;
        static final int NONE = -1;

        ArrayList<Integer>[] edges;
        long[][] cost;

        public Tree(int vCnt) throws Exception {
            this.edges = new ArrayList[vCnt];
            for (int v = 0; v < vCnt; ++v) {
                this.edges[v] = new ArrayList<>();
            }

            for (int e = 1; e < vCnt; ++e) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());

                edges[from].add(to);
                edges[to].add(from);
            }

            cost = new long[vCnt][COLOR_CNT];
            for (int v = 0; v < vCnt; ++v) {
                StringTokenizer st = new StringTokenizer(br.readLine());

                cost[v][WHITE] = Integer.parseInt(st.nextToken());
                cost[v][BLACK] = Integer.parseInt(st.nextToken());
            }
        }

        public long getMinColorCost() {
            dfs(ROOT, NONE);
            return Math.min(cost[ROOT][WHITE], cost[ROOT][BLACK]);
        }

        private void dfs(int cur, int prev) {
            for (Integer next : edges[cur]) {
                if (next == prev) {
                    continue;
                }

                dfs(next, cur);

                cost[cur][BLACK] += cost[next][WHITE];
                cost[cur][WHITE] += Math.min(
                    cost[next][WHITE],
                    cost[next][BLACK]
                );
            }
        }
    }

    public static void main(String[] args) throws Exception {
        int vCnt = Integer.parseInt(br.readLine());
        Tree tree = new Tree(vCnt);

        System.out.println(tree.getMinColorCost());
    }
}