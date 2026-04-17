import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double score = sc.nextInt() * 0.25 + sc.nextInt() * 0.25 + sc.nextInt() * 0.5;
        String grade = "F";

        if (score >= 90) {
            grade = "A";
        } else if (score >= 80) {
            grade = "B";
        } else if (score >= 70) {
            grade = "C";
        } else if (score >= 60) {
            grade = "D";
        }

        System.out.println(grade);
    }
}