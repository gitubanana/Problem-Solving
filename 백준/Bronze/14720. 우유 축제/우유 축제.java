import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int milk = 0;
        int shouldEat = 0;

        br.readLine();
        for (String type : br.readLine().split(" ")) {
            if (Integer.parseInt(type) == shouldEat) {
                ++milk;
                shouldEat = (shouldEat + 1) % 3;
            }
        }

        System.out.println(milk);
    }
}