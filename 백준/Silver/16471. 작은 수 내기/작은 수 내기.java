import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static class Cards {
        private int[] cards;
        private int pointer;

        Cards(int size) throws Exception {
            StringTokenizer st = new StringTokenizer(br.readLine());

            this.pointer = 0;
            this.cards = new int[size];
            for (int i = 0; i < size; ++i) {
                this.cards[i] = Integer.parseInt(st.nextToken());
            }
            Arrays.sort(cards);
        }

        boolean winAgainst(Cards opponent) {
            return this.cards[this.pointer] < opponent.cards[opponent.pointer];
        }

        void movePointer() {
            ++this.pointer;
        }
    }

    public static void main(String[] args) throws Exception {
        int size = Integer.parseInt(br.readLine());
        int myScore = 0;
        Cards mine = new Cards(size);
        Cards yours = new Cards(size);

        try {
            while (true) {
                if (mine.winAgainst(yours)) {
                    ++myScore;
                    mine.movePointer();
                }

                yours.movePointer();
            }
        } catch (Exception e) {
            // do nothing
        }

        int winScore = (size + 1) / 2;
        if (myScore >= winScore) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}