import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String number = br.readLine();
        boolean contains7 = number.contains("7");
        boolean divisibleBy7 = (Integer.parseInt(number) % 7 == 0);
        int answer = 0;

        if (contains7 & divisibleBy7) {
            answer = 3;
        } else if (contains7) {
            answer = 2;
        } else if (divisibleBy7) {
            answer = 1;
        }

        System.out.println(answer);
    }
}