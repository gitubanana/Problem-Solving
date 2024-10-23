import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        double area = Double.parseDouble(br.readLine());
        double radius = Math.sqrt(area / Math.PI);

        System.out.println(2 * Math.PI * radius);
    }
}