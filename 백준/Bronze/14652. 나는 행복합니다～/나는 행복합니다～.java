import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");

//        int ySize = Integer.parseInt(input[0]);
        int xSize = Integer.parseInt(input[1]);
        int number = Integer.parseInt(input[2]);

        int x = number % xSize;
        int y = (number - x) / xSize;
        System.out.println(y + " " + x);
    }
}
