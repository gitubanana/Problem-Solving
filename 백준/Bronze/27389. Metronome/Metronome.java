import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int endTime = Integer.parseInt(br.readLine());

        System.out.printf("%.2f", endTime / 4.0);
    }
}