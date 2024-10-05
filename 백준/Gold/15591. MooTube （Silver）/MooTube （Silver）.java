import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

class Edge {
    int v;
    int w;

    public Edge(int v, int w) {
        this.v = v;
        this.w = w;
    }
}

class UpperBound {
    int[] arr;

    public UpperBound(int[] arr) {
        this.arr = arr;
    }

    public int getLargerCnt(int findValue) {
        int left = 0;
        int right = arr.length - 1;
        int closestLargeIdx = arr.length;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] >= findValue) {
                closestLargeIdx = mid;
                right = mid - 1;
                continue;
            }

            left = mid + 1;
        }

        return arr.length - closestLargeIdx;
    }
}

public class Main {
    static ArrayList<Edge>[] edges;
    static int[][] minWeight;
    static int from;

    static void dfs(int cur, int prev, int curMinWeight) {
        minWeight[from][cur] = curMinWeight;
        for (Edge next : edges[cur]) {
            if (next.v == prev) {
                continue;
            }

            dfs(next.v, cur, Math.min(curMinWeight, next.w));
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int vCnt = Integer.parseInt(st.nextToken());
        int qCnt = Integer.parseInt(st.nextToken());

        edges = new ArrayList[vCnt + 1];
        for (int v = 1; v <= vCnt; ++v) {
            edges[v] = new ArrayList<>();
        }
        for (int e = 1; e < vCnt; ++e) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());

            edges[a].add(new Edge(b, w));
            edges[b].add(new Edge(a, w));
        }

        minWeight = new int[vCnt + 1][vCnt + 1];
        for (from = 1; from <= vCnt; ++from) {
            dfs(from, 0, Integer.MAX_VALUE);
            Arrays.sort(minWeight[from]);
        }

        StringBuilder result = new StringBuilder();
        while (qCnt-- > 0) {
            st = new StringTokenizer(br.readLine());
            int wantWeight = Integer.parseInt(st.nextToken());
            int from = Integer.parseInt(st.nextToken());
            UpperBound ub = new UpperBound(minWeight[from]);

            result.append((ub.getLargerCnt(wantWeight) - 1)+"\n");
        }

        System.out.print(result);
    }
}