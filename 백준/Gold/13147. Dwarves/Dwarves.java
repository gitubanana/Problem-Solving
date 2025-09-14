import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.StringTokenizer;

class IdMapper {
    private final Map<String, Integer> idByStr = new HashMap<>();

    int getOrMakeIdOf(String name) {
        return idByStr.computeIfAbsent(name, k -> idByStr.size());
    }

    int size() {
        return idByStr.size();
    }
}

public class Main {
    static final char A_IS_GREATER = '>';
    static final int MAX_SIZE = (int) 2e5;

    static boolean bfs(int vCnt, int[] indegree, List<Integer>[] edges) {
        int visitedCnt = 0;
        Queue<Integer> q = new ArrayDeque<>();

        for (int v = 0; v < vCnt; v++) {
            if (indegree[v] == 0) {
                visitedCnt++;
                q.add(v);
            }
        }

        while (!q.isEmpty()) {
            Integer cur = q.poll();

            for (Integer next : edges[cur]) {
                if (--indegree[next] != 0) {
                    continue;
                }

                visitedCnt++;
                q.add(next);
            }
        }
        return visitedCnt == vCnt;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int eCnt = Integer.parseInt(br.readLine());
        IdMapper idMapper = new IdMapper();
        List<Integer>[] edges = new List[MAX_SIZE];
        int[] indegree = new int[MAX_SIZE];

        for (int i = eCnt * 2 - 1; i >= 0; i--) {
            edges[i] = new ArrayList<>();
        }
        for (int e = 0; e < eCnt; e++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = idMapper.getOrMakeIdOf(st.nextToken());
            char cmp = st.nextToken().charAt(0);
            int b = idMapper.getOrMakeIdOf(st.nextToken());

            if (cmp == A_IS_GREATER) {
                edges[a].add(b);
                indegree[b]++;
            } else {
                edges[b].add(a);
                indegree[a]++;
            }
        }

        System.out.println(
                bfs(idMapper.size(), indegree, edges)
                        ? "possible"
                        : "impossible"
        );
    }
}
