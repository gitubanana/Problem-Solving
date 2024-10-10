import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

class Line {
    String line;
    int idx;

    Line(String line) {
        this.line = line;
        this.idx = 0;
    }

    boolean idxInBound() {
        return this.idx < line.length();
    }

    char nextKey() {
        return line.charAt(idx);
    }

    int nextSameKeyCnt() {
        int cnt = 1;
        char ch = nextKey();

        while (++idx < line.length()) {
            if (ch != line.charAt(idx)) {
                break;
            }
            ++cnt;
        }

        return cnt;
    }
}

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Line origin = new Line(br.readLine());
        Line screen = new Line(br.readLine());
        HashSet<Character> stickyKeys = new HashSet<>();

        while (origin.idxInBound()) {
            char key = origin.nextKey();
            int oCnt = origin.nextSameKeyCnt();
            int sCnt = screen.nextSameKeyCnt();

            if (oCnt != sCnt) {
                stickyKeys.add(key);
            }
        }

        StringBuilder result = new StringBuilder();
        for (Character key : stickyKeys) {
            result.append(key);
        }

        System.out.println(result);
    }
}
