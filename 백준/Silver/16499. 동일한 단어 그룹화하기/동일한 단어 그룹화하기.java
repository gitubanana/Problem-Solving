import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws Exception {
        HashSet<String> group = new HashSet<>();
        int size = Integer.parseInt(br.readLine());

        while (size-- > 0) {
            char[] sorted = br.readLine().toCharArray();
            Arrays.sort(sorted);

            group.add(new String(sorted));
        }

        System.out.println(group.size());
    }
}