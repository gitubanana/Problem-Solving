import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        while (true) {
            int toFind = Integer.parseInt(br.readLine());
            if (toFind == 0) {
                break;
            }

            int left = 1;
            int right = 50;
            while (left <= right) {
                int mid = (left + right) / 2;

                bw.append(mid+" ");
                if (mid == toFind) {
                    break;
                }

                if (mid < toFind) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }

            bw.append("\n");
        }

        bw.flush();
    }
}