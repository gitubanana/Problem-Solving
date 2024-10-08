import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    enum Status {
        NONE("none"),
        UNSURE("unsure"),
        HAPPY("happy"),
        SAD("sad");

        final private String s;

        private Status(String s) {
            this.s = s;
        }

        public String getMsg() {
            return this.s;
        }
    }

    static private String result = Status.UNSURE.getMsg();

    static String getResult() {
        return result;
    }

    static int getStrCnt(String hay, String needle) {
        int cnt = 0;
        int start = hay.indexOf(needle);

        while (start != -1) {
            ++cnt;
            start = hay.indexOf(needle, start + needle.length());
        }

        return cnt;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();

        int happyCnt = getStrCnt(line, ":-)");
        int sadCnt = getStrCnt(line, ":-(");

        if (happyCnt == 0 && sadCnt == 0) {
            result = Status.NONE.getMsg();
        } else if (happyCnt > sadCnt) {
            result = Status.HAPPY.getMsg();
        } else if (happyCnt < sadCnt) {
            result = Status.SAD.getMsg();
        }

        System.out.println(result);
    }
}
