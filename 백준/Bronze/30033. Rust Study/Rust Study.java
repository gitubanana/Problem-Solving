import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] goals = new int[Integer.parseInt(br.readLine())];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < goals.length; i++) {
            goals[i] = Integer.parseInt(st.nextToken());
        }

        int goodjobDay = 0;

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < goals.length; i++) {
            if (goals[i] <= Integer.parseInt(st.nextToken())) {
                goodjobDay++;
            }
        }

        System.out.println(goodjobDay);
    }
}