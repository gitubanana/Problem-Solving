import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println(
            br.lines()
                .filter(
                    line -> line.equals("gum gum for jay jay")
                )
                .count()
        );
    }
}