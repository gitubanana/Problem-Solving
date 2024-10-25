import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        br.readLine();
        StringTokenizer st = new StringTokenizer(br.readLine());
        HashSet<String> cheese = new HashSet<>();

        while (st.hasMoreTokens()) {
            String topping = st.nextToken();
            if (topping.endsWith("Cheese")) {
                cheese.add(topping);
            }
        }

        if (cheese.size() >= 4) {
            bw.append("yummy\n");
        } else {
            bw.append("sad\n");
        }
        bw.flush();
    }
}