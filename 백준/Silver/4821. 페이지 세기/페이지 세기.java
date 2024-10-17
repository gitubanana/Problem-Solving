import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static void doAllCmd() throws Exception {
        while (true) {
            int pageCnt = Integer.parseInt(br.readLine());
            if (pageCnt == 0) {
                break;
            }

            boolean[] isPrinted = new boolean[pageCnt + 1];

            for (String printRange : br.readLine().split(",")) {
                String[] pages = printRange.split("-");
                int start = Integer.parseInt(pages[0]);
                if (pages.length != 2) {
                    if (start <= pageCnt) {
                        isPrinted[start] = true;
                    }
                    continue;
                }

                int end = Integer.parseInt(pages[1]);

                for (int page = start; page <= end; ++page) {
                    if (page > pageCnt) {
                        break;
                    }

                    isPrinted[page] = true;
                }
            }

            int printedCnt = 0;
            for (int page = 1; page <= pageCnt; ++page) {
                if (isPrinted[page]) {
                    ++printedCnt;
                }
            }

            bw.write(printedCnt+"\n");
        }
    }

    public static void main(String[] args) throws Exception {
        doAllCmd();
        bw.flush();
    }
}