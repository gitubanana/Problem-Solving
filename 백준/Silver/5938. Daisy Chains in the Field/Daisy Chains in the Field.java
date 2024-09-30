import java.util.*;

import java.lang.*;

import java.io.*;

class UnionFind {

    int[] parents;

    UnionFind(int vCnt) {

        parents = new int[vCnt + 1];

        for (int i = 1; i < parents.length; ++i) {

            parents[i] = i;

        }

    }

    int getParent(int x) {

        if (x == parents[x]) {

            return x;

        }

        return parents[x] = getParent(parents[x]);

    }

    void union(int y, int x) {

        int yParent = getParent(y);

        int xParent = getParent(x);

        if (yParent > xParent) {

            parents[yParent] = xParent;

        } else {

            parents[xParent] = yParent;

        }

    }

}

class Main {

    public static void main(String[] args) throws Exception {

        BufferedReader br

            = new BufferedReader(new InputStreamReader(System.in));

        String[] line = br.readLine().split(" ");

        int vCnt = Integer.parseInt(line[0]);

        int eCnt = Integer.parseInt(line[1]);

        UnionFind uf = new UnionFind(vCnt);

        while (eCnt-- > 0) {

            String[] input = br.readLine().split(" ");

            int a = Integer.parseInt(input[0]);

            int b = Integer.parseInt(input[1]);

            uf.union(a, b);

        }

        StringBuilder result = new StringBuilder();

        for (int v = 1; v <= vCnt; ++v) {

            if (uf.getParent(v) != 1) {

                result.append(v+"\n");

            }

        }

        if (result.length() == 0) {

            result.append("0\n");

        }

        System.out.print(result);

    }

}