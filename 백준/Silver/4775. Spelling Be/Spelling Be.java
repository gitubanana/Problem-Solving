import java.util.*;
import java.lang.*;
import java.io.*;

class Dictionary {
    private Set<String> words = new HashSet<>();

    public void add(String word) {
        words.add(word);
    }

    public boolean contains(String word) {
        return words.contains(word);
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int wordCnt = Integer.parseInt(br.readLine());
        Dictionary dict = new Dictionary();

        while (wordCnt-- > 0) {
            dict.add(br.readLine());
        }

        int emailCnt = Integer.parseInt(br.readLine());

        for (int id = 1; id <= emailCnt; id++) {
            List<String> typos = findTypos(dict);

            bw.append(
                String.format(
                    "Email %d is%s spelled correctly.\n",
                    id,
                    typos.size() == 0 ? "" : " not"
                )
            );

            for (String typo : typos) {
                bw.append(typo);
                bw.append("\n");
            }
        }

        bw.append("End of Output\n");
        bw.flush();
    }

    static List<String> findTypos(Dictionary dict) throws Exception {
        List<String> typos = new ArrayList<>();

        while (true) {
            String toCheck = br.readLine();
            if (toCheck.equals("-1")) {
                break;
            }

            if (!dict.contains(toCheck)) {
                typos.add(toCheck);
            }
        }
        return typos;
    }
}