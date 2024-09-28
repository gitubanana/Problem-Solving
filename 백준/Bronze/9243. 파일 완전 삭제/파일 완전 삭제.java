import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        String a = br.readLine();
        String b = br.readLine();
        boolean isNot = (n & 1) == 0;

        for (int i = 0; i < a.length(); ++i) {
            if ((a.charAt(i) == b.charAt(i)) != isNot) {
                System.out.println("Deletion failed");
                return;
            }
        }

        System.out.println("Deletion succeeded");
    }
}
