import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);

        System.out.println(
            sc.nextInt() + sc.nextInt() == sc.nextInt()
            ? "correct!"
            : "wrong!"
        );
    }
}