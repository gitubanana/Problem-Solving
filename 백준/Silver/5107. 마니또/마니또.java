import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static HashMap<String, String> manito;
    static HashMap<String, Integer> visited;
    static int id;

    public static void main(String[] args) throws Exception {
        for (int t = 1; true; t++) {
            int vCnt = Integer.parseInt(br.readLine());
            if (vCnt == 0) {
                break;
            }

            int chainCnt = 0;

            id = 0;
            setManito(vCnt);
            visited = new HashMap<>();
            for (String from : manito.keySet()) {
                if (visited.containsKey(from)) {
                    continue;
                }

                ++id;
                if (findChain(from)) {
                    chainCnt++;
                }
            }

            bw.append(t+" "+chainCnt+"\n");
        }

        bw.flush();
    }

    static void setManito(int vCnt) throws Exception {
        manito = new HashMap<>();
        while (vCnt-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String from = st.nextToken();
            String to = st.nextToken();

            manito.put(from, to);
        }
    }

    static boolean findChain(String cur) {
        if (visited.containsKey(cur)) {
            return visited.get(cur) == id;
        }

        visited.put(cur, id);
        return findChain(manito.get(cur));
    }
}