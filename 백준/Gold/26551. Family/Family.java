import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
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

    public void union(int x, int y) {
        parents[parentOf(x)] = parentOf(y);
    }
}

class IdMap {
    private final Map<String, Integer> idByName = new HashMap<>();

    public int getOrPut(String name) {
        return idByName.computeIfAbsent(name, k -> idByName.size() + 1);
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int eCnt = Integer.parseInt(br.readLine());
        UnionFind uf = new UnionFind(eCnt * 2);
        IdMap idMap = new IdMap();

        for (int e = 0; e < eCnt; e++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = idMap.getOrPut(st.nextToken()); st.nextToken();
            int b = idMap.getOrPut(st.nextToken());

            uf.union(a, b);
        }

        int qCnt = Integer.parseInt(br.readLine());
        StringBuilder result = new StringBuilder();
        for (int q = 0; q < qCnt; q++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = idMap.getOrPut(st.nextToken());
            int b = idMap.getOrPut(st.nextToken());

            result.append(
                    uf.parentOf(a) == uf.parentOf(b)
                    ? "Related"
                    : "Not Related"
            ).append('\n');
        }

        System.out.println(result.toString());
    }
}
