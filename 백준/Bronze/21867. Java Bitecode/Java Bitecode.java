import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Inet4Address;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        br.readLine();
        StringBuilder result = new StringBuilder();
        String code = br.readLine();
        String toBite = "JAV";

        for (int i = 0; i < code.length(); ++i) {
            if (toBite.indexOf(code.charAt(i)) == -1) {
                result.append(code.charAt(i));
            }
        }

        if (result.isEmpty()) {
            System.out.println("nojava");
        } else {
            System.out.println(result);
        }
    }
}

