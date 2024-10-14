import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static class Tree {
        private ArrayList<Integer>[] edges;

        public Tree(int vCnt) {
            edges = new ArrayList[vCnt + 1];
            for (int v = 1; v <= vCnt; ++v) {
                edges[v] = new ArrayList<>();
            }
        }

        public ArrayList<Integer> getEdges(int v) {
            return edges[v];
        }

        public void addEdge(int from, int to) {
            getEdges(from).add(to);
        }

        public int getSize() {
            return edges.length;
        }
    }

    static class Ruler {
        private static final int SKIPPED = 0;
        private static final int SELECTED = 1;
        private static final int STATUS_CNT = 2;
        private static final int ROOT = 1;
        private static final int VIRTUAL_NODE = 0;

        private Tree tree;
        private int[][] dp;

        public Ruler(Tree tree) {
            this.tree = tree; // 따로 할당하진 않는다. (new 없음)
            this.dp = new int[tree.getSize()][STATUS_CNT];
        }

        private void dfs(int cur, int prev) {
            dp[cur][SELECTED] = 1;

            for (Integer next : tree.getEdges(cur)) {
                if (next == prev) {
                    continue;
                }

                dfs(next, cur);

                dp[cur][SKIPPED] += dp[next][SELECTED];
                dp[cur][SELECTED] += Math.min(
                        dp[next][SKIPPED],
                        dp[next][SELECTED]
                );
            }
        }

        public int getMinPoliceCnt() {
            if (tree.getSize() == 2) {
                return 1;
            }

            dfs(ROOT, VIRTUAL_NODE);
            return Math.min(dp[ROOT][SKIPPED], dp[ROOT][SELECTED]);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int vCnt = Integer.parseInt(br.readLine());
        Tree tree = new Tree(vCnt);

        for (int e = 1; e < vCnt; ++e) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());

            tree.addEdge(from, to);
            tree.addEdge(to, from);
        }

        Ruler minho = new Ruler(tree);

        System.out.println(minho.getMinPoliceCnt());
    }
}
