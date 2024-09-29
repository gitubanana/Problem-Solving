import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        ArrayList<Integer> scores = new ArrayList<>();
        for (String num : br.readLine().split(" ")) {
            scores.add(Integer.parseInt(num));
        }

        int idx = scores.indexOf(20);
        int right = (idx + 1) % scores.size();
        int left = (idx - 1 + scores.size()) % scores.size();

        double alice = (scores.get(idx) + scores.get(right) + scores.get(left)) / 3.0;
        double bob = 10.5;

        String result = "Tie";

        if (alice > bob) {
            result = "Alice";
        } else if (alice < bob) {
            result = "Bob";
        }

        System.out.println(result);
    }
}
