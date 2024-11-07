import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int time = Integer.parseInt(st.nextToken());
        boolean withDrink = Integer.parseInt(st.nextToken()) == 1 ? true : false;

        if (withDrink || !isLunchTime(time)) {
            bw.append("280");
        } else {
            bw.append("320");
        }
        bw.flush();
    }

    static boolean isLunchTime(int time) {
        return (12 <= time && time <= 16);
    }
}