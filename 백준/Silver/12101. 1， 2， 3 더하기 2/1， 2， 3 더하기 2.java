import java.util.*;
import java.lang.*;
import java.io.*;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int ordinalCnt;
    static final List<String> numberList = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int makeNumber = Integer.parseInt(st.nextToken());
        ordinalCnt = Integer.parseInt(st.nextToken());

        backTracking(makeNumber);

        bw.append("-1");
        bw.flush();
    }

    static void backTracking(int curNumber) throws Exception {
        if (curNumber < 0) {
            return;
        }

        if (curNumber == 0) {
            ordinalCnt--;
            if (ordinalCnt == 0) {
                bw.append(String.join("+", numberList));
                bw.flush();
                System.exit(0);
            }
            return;
        }

        for (int i = 1; i <= 3; i++) {
            numberList.add(i+"");
            backTracking(curNumber - i);
            numberList.remove(numberList.size() - 1);
        }
    }
}