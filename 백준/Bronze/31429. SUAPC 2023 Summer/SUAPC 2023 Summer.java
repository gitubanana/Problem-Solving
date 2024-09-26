import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.Buffer;
import java.util.StringTokenizer;


public class Main {
    public static void main(String[] args) throws Exception {
        int[] solvedCnt = {12, 11, 11, 10, 9, 9, 9, 8, 7, 6, 6};
        int[] minute = {1600, 894, 1327, 1311, 1004, 1178, 1357, 837, 1055, 556, 773};

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int place = Integer.parseInt(br.readLine()) - 1;

        System.out.printf("%d %d\n", solvedCnt[place], minute[place]);
    }
}
