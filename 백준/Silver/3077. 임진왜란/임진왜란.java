import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static HashMap<String, Integer> historyOrder = new HashMap<>();
    static BufferedReader br = new BufferedReader(
        new InputStreamReader(System.in)
    );
    static BufferedWriter bw = new BufferedWriter(
        new OutputStreamWriter(System.out)
    );

    public static void main(String[] args) throws Exception {
        int size = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        for (int i = 0; i < size; i++) {
            historyOrder.put(st.nextToken(), i);
        }

        ArrayList<String> toCheck = new ArrayList<>(size);

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < size; ++i) {
            toCheck.add(st.nextToken());
        }

        int score = 0;
        int total = size * (size - 1) / 2;

        for (int i = 0; i < size - 1; i++) {
            String before = toCheck.get(i);

            for (int j = i + 1; j < size; j++) {
                String next = toCheck.get(j);
                if (historyOrder.get(before) > historyOrder.get(next)) {
                    continue;
                }

                ++score;
            }
        }

        bw.append(score+"/"+total+"\n");
        bw.flush();
    }
}