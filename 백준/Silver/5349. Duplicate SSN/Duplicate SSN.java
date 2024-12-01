import java.util.*;

import java.lang.*;

import java.io.*;

class Main {

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws Exception {

        Set<String> ssns = new HashSet<>();

        Set<String> ans = new TreeSet<>();

        while (true) {

            String ssn = br.readLine();

            if (ssn == null) {

                break;

            }

            if (!ssns.add(ssn)) {

                ans.add(ssn);

            }

        }

        ans.forEach(s -> System.out.println(s));

    }

}