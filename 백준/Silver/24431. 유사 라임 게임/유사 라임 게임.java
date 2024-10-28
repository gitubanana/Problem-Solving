import java.util.*;
import java.lang.*;
import java.io.*;

class Rhyme {
    private HashSet<String> rhymes = new HashSet<>();

    public void add(String word) {
        rhymes.add(word);
    }

    public boolean has(String word) {
        return rhymes.contains(word);
    }

    public void remove(String word) {
        rhymes.remove(word);
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int testCnt = Integer.parseInt(br.readLine());

        while (testCnt-- > 0) {
            StringTokenizer numbers = new StringTokenizer(br.readLine()); numbers.nextToken();
            StringTokenizer words = new StringTokenizer(br.readLine()); 
            int wordLength = Integer.parseInt(numbers.nextToken());;
            int cmpLength = Integer.parseInt(numbers.nextToken());
            int index = wordLength - cmpLength;
            int rhymeCnt = 0;
            Rhyme rhymes = new Rhyme();

            while (words.hasMoreTokens()) {
                String word = words.nextToken().substring(index);

                if (rhymes.has(word)) {
                    ++rhymeCnt;
                    rhymes.remove(word);
                } else {
                    rhymes.add(word);
                }
            }

            bw.append(rhymeCnt+"\n");
        }

        bw.flush();
    }
}