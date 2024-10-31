import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int highSize = Integer.parseInt(st.nextToken());
        int lowSize = Integer.parseInt(st.nextToken());
        ArrayList<Integer> highBales = new ArrayList<>(highSize);
        ArrayList<Integer> lowBales = new ArrayList<>(lowSize);

        for (int i = 0; i < highSize; i++) {
            highBales.add(Integer.parseInt(br.readLine()));
        }

        for (int i = 0; i < lowSize; i++) {
            lowBales.add(Integer.parseInt(br.readLine()));
        }

        highBales.sort(Comparator.reverseOrder());
        lowBales.sort(Comparator.reverseOrder());

        int high = 0;
        int low = 0;
        int ans = highBales.size();

        while (high < highSize && low < lowSize) {
            if (highBales.get(high) > lowBales.get(low)) {
                ans++;
                high++;
            }

            low++;
        }

        bw.append(ans+"\n");
        bw.flush();
    }
}