import java.util.*;
import java.lang.*;
import java.io.*;

// The main method must be in a class named "Main".
class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int yCost = 0, mCost = 0;
        int callCnt = sc.nextInt();
        while (callCnt > 0)
        {
            int sec = sc.nextInt();

            yCost += (sec / 30 + 1) * 10;
            mCost += (sec / 60 + 1) * 15;
            --callCnt;
        }

        int minCost = Math.min(yCost, mCost);
        String answer = "";
        if (minCost == yCost)
        {
            answer += "Y ";
        }

        if (minCost == mCost)
        {
            answer += "M ";
        }

        answer += String.valueOf(minCost);
        System.out.println(answer);
    }
}