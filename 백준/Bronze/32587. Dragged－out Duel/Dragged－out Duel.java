import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static final String weapons = "RPS";
    static final String winnable = "SRP";

    static boolean wonTheGame(char mine, char opponent) {
        int i = 0;

        for (; i < weapons.length(); i++) {
            if (mine == weapons.charAt(i)) {
                break;
            }
        }
        return winnable.charAt(i) == opponent;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int result = 0;

        br.readLine();
        String mine = br.readLine();
        String opponents = br.readLine();
        for (int i = 0; i < mine.length(); i++) {
            if (wonTheGame(mine.charAt(i), opponents.charAt(i))) {
                result++;
            } else if (wonTheGame(opponents.charAt(i), mine.charAt(i))) {
                result--;
            }
        }

        System.out.println(result > 0 ? "victory" : "defeat");
    }
}