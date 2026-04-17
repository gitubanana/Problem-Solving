import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int width = Integer.parseInt(br.readLine());
        int height = Integer.parseInt(br.readLine());

        bw.append((width * height) + "\n");
        bw.flush();
    }
}