import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        char[][] ch = new char[][]{
                {'A', 'C', 'A', 'G'},
                {'C', 'G', 'T', 'A'},
                {'A', 'T', 'C', 'G'},
                {'G', 'A', 'G', 'T'}
        };
        String str = "AGCT";

        int length = Integer.parseInt(br.readLine());
        char[] result = br.readLine().toCharArray();
        while (length > 1) {
            result[length - 2] = ch[str.indexOf(result[length - 2])][str.indexOf(result[length - 1])];
            --length;
        }

        System.out.println(result[0]);
    }
}