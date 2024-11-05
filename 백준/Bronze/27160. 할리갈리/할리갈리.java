import java.util.*;
import java.lang.*;
import java.io.*;

class HalliGalli {
    private static final int PUSH_BELL_CONDITION = 5;

    private HashMap<String, Integer> countByFruit = new HashMap<>();

    public void add(String fruit, int count) {
        countByFruit.put(fruit, getFruitCount(fruit) + count);
    }

    public int getFruitCount(String fruit) {
        return countByFruit.getOrDefault(fruit, 0);
    }

    public boolean isTimeToPushBell() {
        for (Integer count : countByFruit.values()) {
            if (count == PUSH_BELL_CONDITION) {
                return true;
            }
        }
        return false;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int cardCnt = Integer.parseInt(br.readLine());
        HalliGalli halligalli = new HalliGalli();

        while (cardCnt-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String fruit = st.nextToken();
            int count = Integer.parseInt(st.nextToken());

            halligalli.add(fruit, count);
        }

        if (halligalli.isTimeToPushBell()) {
            bw.append("YES");
        } else {
            bw.append("NO");
        }

        bw.flush();
    }
}