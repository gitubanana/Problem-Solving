import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        while (true) {
            String line = br.readLine();
            if (line == null) {
                break;
            }

            StringTokenizer st = new StringTokenizer(line);
            List<Integer> list = new ArrayList<>();

            while (st.hasMoreTokens()) {
                list.add(Integer.parseInt(st.nextToken()));
            }

            for (int i = 0; i < list.size(); i++) {
                int prev = (i == 0 ? 1 : list.get(i - 1));
                int next = (i == list.size() - 1 ? 1 : list.get(i + 1));

                bw.append((prev * list.get(i) * next)+" ");
            }

            bw.append("\n");
        }

        bw.flush();
    }
}