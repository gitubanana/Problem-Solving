import java.util.*;
import java.lang.*;
import java.io.*;

class Words {
    private HashMap<String, String> words = new HashMap<>();

    public void add(String word) {
        if (isNotAddable(word)) {
            return;
        }

        words.put(sortBetween(word), word);
    }

    public String get(String word) {
        if (isNotAddable(word)) {
            return word;
        }

        return words.get(sortBetween(word));
    }

    private static boolean isNotAddable(String word) {
        return word.length() <= 3;
    }

    private static String sortBetween(String word) {
        char[] sorted = word.toCharArray();

        Arrays.sort(sorted, 1, sorted.length - 1);
        return new String(sorted);
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int wordCnt = Integer.parseInt(br.readLine());
        Words words = new Words();

        while (wordCnt-- > 0) {
            words.add(br.readLine());
        }

        br.readLine();
        StringTokenizer st = new StringTokenizer(br.readLine());

        while (st.hasMoreTokens()) {
            String word = st.nextToken();

            bw.append(words.get(word));
            bw.append(" ");
        }

        bw.flush();
    }
}