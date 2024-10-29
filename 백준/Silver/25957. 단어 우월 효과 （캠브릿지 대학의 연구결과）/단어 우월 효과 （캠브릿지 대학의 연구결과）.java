import java.util.*;
import java.lang.*;
import java.io.*;

class Words {
    private static final int MAX_WORD_LENGTH = 9;

    private HashMap<String, HashMap<String, String>> words = new HashMap<>();

    public void add(String word) {
        if (isNotAddable(word)) {
            return;
        }

        String firstAndEnd = makeFirstAndEnd(word);

        if (words.containsKey(firstAndEnd)) {
            words.get(firstAndEnd).put(sortBetween(word), word);
            return;
        }

        HashMap<String, String> hashMap = new HashMap<>();

        hashMap.put(sortBetween(word), word);
        words.put(firstAndEnd, hashMap);
    }

    public String get(String word) {
        if (isNotAddable(word)) {
            return word;
        }

        return words.get(makeFirstAndEnd(word)).get(sortBetween(word));
    }

    private static boolean isNotAddable(String word) {
        return word.length() <= 3;
    }

    private static String makeFirstAndEnd(String word) {
        return String.valueOf(word.charAt(0))
                + String.valueOf(word.charAt(word.length() - 1));
    }

    private static String sortBetween(String word) {
        char[] sorted = word.substring(1, word.length() - 1).toCharArray();

        Arrays.sort(sorted);
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