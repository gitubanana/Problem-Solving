import java.io.BufferedReader;
import java.io.FileReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String result = "0";
        String s = br.readLine();
        switch (s) {
            case "(1)":
                break;
            case ")1(":
                result = "2";
                break;
            default:
                result = "1";
                break;
        }

        System.out.println(result);
    }
}
