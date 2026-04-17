import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder result = new StringBuilder();
        int testCnt = Integer.parseInt(br.readLine());

        for (int t = 1; t <= testCnt; t++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int vCnt = Integer.parseInt(st.nextToken());
            int eCnt = Integer.parseInt(st.nextToken());
            Set<Integer>[] edges = new Set[vCnt + 1];

            for (int v = 1; v <= vCnt; v++) {
                edges[v] = new TreeSet<>();
            }
            for (int e = 0; e < eCnt; e++) {
                st = new StringTokenizer(br.readLine());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                edges[a].add(b);
                edges[b].add(a);
            }

            int culprit = Integer.parseInt(br.readLine());

            result.append("Data Set ")
                    .append(t)
                    .append(":\n")
                    .append(edges[culprit].stream().map(String::valueOf).collect(Collectors.joining(" ")))
                    .append("\n\n");
        }

        System.out.println(result);
    }
}
