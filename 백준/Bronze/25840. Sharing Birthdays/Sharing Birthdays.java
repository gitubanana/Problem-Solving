import java.util.*;

import java.lang.*;

import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        Set<String> set = new HashSet<>();

        while (n-- > 0) {

            set.add(br.readLine());

        }

        System.out.println(set.size());

    }

}