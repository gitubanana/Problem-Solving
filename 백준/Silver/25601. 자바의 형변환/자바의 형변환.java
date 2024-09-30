import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
    static HashMap<String, Integer> strToInt = new HashMap<>();
    static int[] parents;
    static int id = 1;

    static int getOrMakeId(String str) {
        if (strToInt.containsKey(str)) {
            return strToInt.get(str);
        }

        strToInt.put(str, id);
        return id++;
    }

    static int isChild(int cur, int parent) {
        while (true) {
            cur = parents[cur];
            if (cur == 0) {
                return 0;
            }

            if (cur == parent) {
                return 1;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int vCnt = Integer.parseInt(br.readLine());

        parents = new int[vCnt + 1];
        for (int e = 1; e < vCnt; ++e) {
            String[] line = br.readLine().split(" ");
            int child = getOrMakeId(line[0]);
            int parent = getOrMakeId(line[1]);

            parents[child] = parent;
        }

        String[] line = br.readLine().split(" ");
        int a = getOrMakeId(line[0]);
        int b = getOrMakeId(line[1]);

        System.out.println(isChild(a, b) | isChild(b, a));
    }
}

