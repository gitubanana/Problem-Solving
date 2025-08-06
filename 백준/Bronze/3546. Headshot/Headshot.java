import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static final char EMPTY = '0';
    static final char BULLET = '1';

    public static void main(String[] args) {
        String revolver = new Scanner(System.in).nextLine();
        int emptyCnt = 0;
        int rightEmptyCnt = 0;

        for (int i = 0; i < revolver.length(); i++) {
            switch (revolver.charAt(i)) {
                case EMPTY:
                    emptyCnt++;
                    break;
                case BULLET:
                    if (revolver.charAt((i + 1) % revolver.length()) == EMPTY)
                        rightEmptyCnt++;
                    break;
            }
        }

        int bulletCnt = revolver.length() - emptyCnt;
        if (bulletCnt == 0) {
            System.out.println("EQUAL");
            return;
        }

        double shootProbability = (double) emptyCnt / revolver.length();
        double rotateProbability = (double) rightEmptyCnt / bulletCnt;

        // ternary operator : right associative
        System.out.println(shootProbability > rotateProbability ? "SHOOT" : shootProbability < rotateProbability ? "ROTATE" : "EQUAL");
    }
}