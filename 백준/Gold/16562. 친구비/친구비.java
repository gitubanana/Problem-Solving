import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class UnionFind {
    private final int[] parents;

    public UnionFind(int vCnt) {
        parents = new int[vCnt + 1];
        for (int v = 1; v <= vCnt; v++) {
            parents[v] = v;
        }
    }

    public int parentOf(int v) {
        if (v == parents[v]) {
            return v;
        }
        return parents[v] = parentOf(parents[v]);
    }

    public void union(int x, int y, boolean xIsPrior) {
        int xParent = parentOf(x);
        int yParent = parentOf(y);

        if (xIsPrior) {
            parents[yParent] = xParent;
        } else {
            parents[xParent] = yParent;
        }
    }
}

public class Main {
    static final int ME = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int vCnt = Integer.parseInt(st.nextToken());
        int eCnt = Integer.parseInt(st.nextToken());
        int budget = Integer.parseInt(st.nextToken());
        int[] costs = new int[vCnt + 1];

        st = new StringTokenizer(br.readLine());
        for (int v = 1; v <= vCnt; v++) {
            costs[v] = Integer.parseInt(st.nextToken());
        }

        UnionFind uf = new UnionFind(vCnt);
        for (int e = 0; e < eCnt; e++) {
            st = new StringTokenizer(br.readLine());
            int a = uf.parentOf(Integer.parseInt(st.nextToken()));
            int b = uf.parentOf(Integer.parseInt(st.nextToken()));

            uf.union(a, b, (costs[a] < costs[b]));
        }

        int totalCost = 0;
        for (int v = 1; v <= vCnt; v++) {
            int cheapFriend = uf.parentOf(v);
            if (ME == cheapFriend) { // 이미 친구임
                continue;
            }

            totalCost += costs[cheapFriend];
            if (totalCost > budget) {
                System.out.println("Oh no");
                return;
            }

            uf.union(ME, cheapFriend, true);
        }

        System.out.println(totalCost);
    }
}
