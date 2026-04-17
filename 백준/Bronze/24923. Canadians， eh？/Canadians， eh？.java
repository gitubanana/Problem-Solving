import java.util.*;

import java.lang.*;

import java.io.*;

class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String sentence = sc.nextLine();

        System.out.println(

            sentence.substring(sentence.length() - 3).equals("eh?")

            ? "Canadian!"

            : "Imposter!"

        );

    }

}