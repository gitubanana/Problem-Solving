import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int playerCnt = Integer.parseInt(br.readLine());
        int[][] cards = new int[playerCnt][3];
        int[][] cardCnt = new int[3][101];

        for (int i = 0; i < playerCnt; ++i) {
            int t = 0;
            for (String num : br.readLine().split(" ")) {
                cards[i][t] = Integer.parseInt(num);
                ++cardCnt[t][cards[i][t]];
                ++t;
            }
        }

        int[] scores = new int[playerCnt];
        for (int t = 0; t < 3; ++t) {
            for (int i = 0; i < playerCnt; ++i) {
                int curCard = cards[i][t];

                if (cardCnt[t][curCard] == 1) {
                    scores[i] += curCard;
                }
            }
        }

        StringBuilder result = new StringBuilder();
        for (int i = 0; i < playerCnt; ++i) {
            result.append(scores[i]+"\n");
        }

        System.out.print(result);
    }
}