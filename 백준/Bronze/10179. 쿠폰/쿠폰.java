import java.util.*;

import java.lang.*;

import java.io.*;

class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringBuilder result = new StringBuilder();

        int testCnt = Integer.parseInt(br.readLine());

        while (testCnt-- > 0) {

            double price = Double.parseDouble(br.readLine());

            result.append(String.format("$%.2f\n", price*0.8));

        }

        System.out.print(result); 

    }

}