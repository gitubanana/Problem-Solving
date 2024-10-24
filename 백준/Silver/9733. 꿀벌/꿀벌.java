import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static HashMap<String, Integer> workCnt = new HashMap<>();
    static ArrayList<String> works = new ArrayList<>(
            List.of("Re","Pt","Cc","Ea","Tb","Cm","Ex")
    );
    static BufferedReader br = new BufferedReader(
        new InputStreamReader(System.in)
    );
    static BufferedWriter bw = new BufferedWriter(
        new OutputStreamWriter(System.out)
    );
    static double total;

    static void work() throws Exception {
        for (String work : works) {
            workCnt.put(work, 0);
        }

        while (true) {
            String line = br.readLine();
            if (line == null) {
                break;
            }

            StringTokenizer st = new StringTokenizer(line);

            while (st.hasMoreTokens()) {
                String iDid = st.nextToken();

                ++total;
                if (workCnt.containsKey(iDid)) {
                    workCnt.put(iDid, workCnt.get(iDid) + 1);
                }
            }
        }
    }

    static void printAnswer() throws Exception {
        for (String work : works) {
            int cnt = workCnt.get(work);
            double ratio = cnt / total;

            bw.append(work+" "+cnt+" ");
            bw.append(String.format("%.2f", ratio)+"\n");
        }

        bw.append("Total "+(int)total+" 1.00\n");
        bw.flush();
    }

    public static void main(String[] args) throws Exception {
        work();
        printAnswer();
    }
}