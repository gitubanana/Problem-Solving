import java.util.*;
import java.lang.*;
import java.io.*;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static final int LAST_MONTH = 12;
    static final String DATE_FORMAT = "d/M/yyyy";

    public static void main(String[] args) throws Exception {
        int employeeCnt = Integer.parseInt(br.readLine());
        int[] countByMonth = new int[LAST_MONTH + 1];

        while (employeeCnt-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            st.nextToken();

            LocalDate birthDate = LocalDate.parse(
                    st.nextToken(),
                    DateTimeFormatter.ofPattern(DATE_FORMAT)
            );

            countByMonth[birthDate.getMonthValue()]++;
        }

        for (int month = 1; month <= LAST_MONTH; month++) {
            bw.append(month+" "+countByMonth[month]+"\n");
        }
        bw.flush();
    }
}