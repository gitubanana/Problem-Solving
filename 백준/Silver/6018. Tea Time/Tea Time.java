import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class UnionFind {
    private int[] parents;

    public UnionFind(int vCnt) {
        parents = new int[vCnt + 1];
        for (int v = 1; v <= vCnt; v++) {
            parents[v] = v;
        }
    }

    public int parentOf(int v) {
        if (parents[v] == v) {
            return v;
        }
        return parents[v] = parentOf(parents[v]);
    }

    public void union(int x, int y) {
        parents[parentOf(x)] = parentOf(y);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int vCnt = Integer.parseInt(st.nextToken());
        int eCnt = Integer.parseInt(st.nextToken());
        int qCnt = Integer.parseInt(st.nextToken());
        UnionFind uf = new UnionFind(vCnt);

        for (int e = 0; e < eCnt; e++) {
            st = new StringTokenizer(br.readLine());
            uf.union(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        }

        StringBuilder result = new StringBuilder(qCnt * 2);
        for (int q = 0; q < qCnt; q++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            result.append(
                    uf.parentOf(a) == uf.parentOf(b)
                            ? 'Y'
                            : 'N'
            ).append('\n');
        }

        System.out.println(result);
    }
}
