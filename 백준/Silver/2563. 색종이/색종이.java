import java.util.*;
import java.lang.*;
import java.io.*;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static final int MAP_SIZE = 101;
    static final int PAPER_SIZE = 10;

    public static void main(String[] args) throws Exception {
        int paperCnt = Integer.parseInt(br.readLine());
        boolean[][] isOccupied = new boolean[MAP_SIZE][MAP_SIZE];

        while (paperCnt-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int startY = Integer.parseInt(st.nextToken());
            int startX = Integer.parseInt(st.nextToken());
            int endY = startY + PAPER_SIZE;
            int endX = startX + PAPER_SIZE;

            for (int y = startY; y < endY; y++) {
                for (int x = startX; x < endX; x++) {
                    isOccupied[y][x] = true;
                }
            }
        }

        int count = 0;
        for (int y = 0; y < MAP_SIZE; y++) {
            for (int x = 0; x < MAP_SIZE; x++) {
                if (isOccupied[y][x]) {
                    count++;
                }
            }
        }
        bw.append(count+"\n");
        bw.flush();
    }
}