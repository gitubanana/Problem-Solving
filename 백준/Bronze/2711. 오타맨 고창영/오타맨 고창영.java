import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int testCnt = Integer.parseInt(br.readLine());

        while (testCnt-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int removeIndex = Integer.parseInt(st.nextToken()) - 1;
            String word = st.nextToken();

            bw.append(word.substring(0, removeIndex));
            bw.append(word.substring(removeIndex + 1));
            bw.append(System.lineSeparator());
        }

        bw.flush();
    }
}
