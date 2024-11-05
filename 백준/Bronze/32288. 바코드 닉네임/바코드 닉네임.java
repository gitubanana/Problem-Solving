import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int size = Integer.parseInt(br.readLine());
        String name = br.readLine();

        for (int i = 0; i < size; i++) {
            switch (name.charAt(i)) {
                case 'I':
                    bw.append('i');
                    break;
                case 'l':
                    bw.append('L');
                    break;
            }
        }

        bw.flush();
    }
}