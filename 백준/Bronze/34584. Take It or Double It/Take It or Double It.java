import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // try with resource (auto close)
        try (Scanner sc = new Scanner(System.in)) {
            int cost = sc.nextInt();
            int budget = sc.nextInt();

            System.out.println(cost * 2 > budget ? "take it" : "double it");
        } catch (InputMismatchException e) {
            System.out.println(e);
        }
    }
}
