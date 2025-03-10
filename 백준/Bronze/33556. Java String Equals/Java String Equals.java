import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws IOException, Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String A = br.readLine();
        String B = br.readLine();

        if (A.equals("null")) {
            System.out.println("NullPointerException");
            System.out.println("NullPointerException");
            return;
        }

        if (B.equals("null")) {
            B = null;
        }

        System.out.println(A.equals(B));
        System.out.println(A.equalsIgnoreCase(B));
    }
}