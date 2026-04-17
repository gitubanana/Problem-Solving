import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(br.readLine());
        long ans = Long.MAX_VALUE;

        for (int i = 0; i < size; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long time = Long.parseLong(st.nextToken());
            int isOn = Integer.parseInt(st.nextToken());

            if (isOn == 0) {
                ans = Math.min(ans, time);
            }
        }

        System.out.println(ans == Long.MAX_VALUE ? -1 : ans);
    }
}
