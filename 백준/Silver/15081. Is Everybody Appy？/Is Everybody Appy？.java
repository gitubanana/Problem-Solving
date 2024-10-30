import java.util.*;
import java.lang.*;
import java.io.*;

class UsedApp {
    private HashSet<String> usedApps = new HashSet<>();

    public void add(String app) {
        usedApps.add(app);
    }

    public boolean contains(String app) {
        return usedApps.contains(app);
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int listCnt = Integer.parseInt(br.readLine());
        UsedApp usedApps = new UsedApp();

        while (listCnt-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine()); st.nextToken();

            while (st.hasMoreTokens()) {
                String app = st.nextToken();

                if (!usedApps.contains(app)) {
                    usedApps.add(app);
                    bw.append(app);
                    break;
                }
            }
            bw.append(" ");
        }

        bw.flush();
    }
}