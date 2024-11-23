import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;

class Bulb {
    private static final char ON = '1';

    private final boolean firstOn;
    private final boolean lastOn;

    public Bulb(String str) {
        firstOn = (str.charAt(0) == ON);
        lastOn = (str.charAt(str.length() - 1) == ON);
    }

    public int changeCountWhenLinkedTo(Bulb other) {
        if (this.lastOn != other.firstOn) {
            return 1;
        }
        return 0;
    }

    public static int calculateChangeCount(String str) {
        int changeCount = 0;

        for (int i = 1; i < str.length(); i++) {
            if (str.charAt(i - 1) != str.charAt(i)) {
                changeCount++;
            }
        }
        return changeCount;
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static List<Bulb> bulbs;
    static boolean[] visited;
    static int minChangeCountInLink = Integer.MAX_VALUE;

    public static void main(String[] args) throws Exception {
        int bulbCount = Integer.parseInt(br.readLine());
        int changeCountWithoutLink = 0;

        visited = new boolean[bulbCount];
        bulbs = new ArrayList<>(bulbCount);
        while (bulbCount-- > 0) {
            String str = br.readLine();

            bulbs.add(new Bulb(str));
            changeCountWithoutLink += Bulb.calculateChangeCount(str);
        }

        for (int i = 0; i < bulbs.size(); i++) {
            backTracking(
                    i,
                    0,
                    1
            );
        }

        bw.append(String.valueOf(changeCountWithoutLink + minChangeCountInLink));
        bw.flush();
    }

    static void backTracking(int curIndex, int curCount, int depth) {
        if (minChangeCountInLink <= curCount) {
            return;
        }

        if (depth == bulbs.size()) {
            minChangeCountInLink = curCount;
            return;
        }

        Bulb curBulb = bulbs.get(curIndex);

        visited[curIndex] = true;
        for (int i = 0; i < bulbs.size(); i++) {
            if (visited[i]) {
                continue;
            }

            backTracking(
                    i,
                    curCount + curBulb.changeCountWhenLinkedTo(bulbs.get(i)),
                    depth + 1
            );
        }
        visited[curIndex] = false;
    }
}
