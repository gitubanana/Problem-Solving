import java.util.*;
import java.lang.*;
import java.io.*;

class Dictionary {
    private HashMap<String, String> dict = new HashMap<>();

    public void add(String english, String minionese) {
        dict.put(english, minionese);
    }

    public String get(String english) {
        return dict.get(english);
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int wordCnt = Integer.parseInt(br.readLine());
        Dictionary dict = new Dictionary();

        while (wordCnt-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String english = st.nextToken(); st.nextToken();
            String minionese = st.nextToken();

            dict.add(english, minionese);
        }

        int testCnt = Integer.parseInt(br.readLine());

        while (testCnt-- > 0) {
            br.readLine();
            StringTokenizer st = new StringTokenizer(br.readLine());

            while (st.hasMoreTokens()) {
                bw.append(dict.get(st.nextToken()));
                bw.append(" ");
            }

            bw.append("\n");
        }

        bw.flush();
    }
}