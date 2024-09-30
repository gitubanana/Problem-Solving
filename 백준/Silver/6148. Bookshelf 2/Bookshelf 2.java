import java.util.*;

import java.lang.*;

import java.io.*;

class Main {

    static int minDiff = Integer.MAX_VALUE;

    static int shelfHeight;

    static int[] heights;

    static void dfs(int cur, int sum) {

        if (cur == heights.length) {

            int cmpDiff = sum - shelfHeight;

            if (cmpDiff >= 0) {

                minDiff = Math.min(minDiff, cmpDiff);

            }

            return;

        }

        dfs(cur + 1, sum);

        dfs(cur + 1, sum + heights[cur]);

    }

    public static void main(String[] args) throws Exception {

        BufferedReader br

            = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");

        int cowCnt = Integer.parseInt(input[0]);

        shelfHeight = Integer.parseInt(input[1]);

        heights = new int[cowCnt];

        while (cowCnt-- > 0) {

            heights[cowCnt] = Integer.parseInt(br.readLine());

        }

        dfs(0, 0);

        System.out.println(minDiff);

    }

}