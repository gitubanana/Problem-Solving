import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int peopleLimit = Integer.parseInt(st.nextToken());
        int eventCnt = Integer.parseInt(st.nextToken());
        int curPeople = 0;
        int deniedCnt = 0;

        while (eventCnt-- > 0) {
            st = new StringTokenizer(br.readLine());
            String event = st.nextToken();
            int peopleCnt = Integer.parseInt(st.nextToken());

            switch (event) {
                case "leave":
                    curPeople -= peopleCnt;
                    break;
                case "enter":
                    if (curPeople + peopleCnt > peopleLimit) {
                        ++deniedCnt;
                    } else {
                        curPeople += peopleCnt;
                    }
                    break;
            }
        }

        bw.append(deniedCnt+"\n");
        bw.flush();
    }
}