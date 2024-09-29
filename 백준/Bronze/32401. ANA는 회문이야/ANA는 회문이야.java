import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int length = Integer.parseInt(br.readLine());
        String str = br.readLine();

        int result = 0;
        int A = 0;
        for (; A < length; ++A) {
            if (str.charAt(A) == 'A') {
                break;
            }
        }

        int nCnt = 0;
        for (int i = A + 1; i < length; ++i) {
            switch (str.charAt(i)) {
                case 'N':
                    ++nCnt;
                    break;
                case 'A':
                    if (nCnt == 1) {
                        ++result;
                    }
                    nCnt = 0;
                    break;
            }
        }

        System.out.println(result);
    }
}
