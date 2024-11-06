import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int size = Integer.parseInt(st.nextToken());
        int brandCnt = Integer.parseInt(st.nextToken());
        List<Integer> countByBrand = new ArrayList<>(brandCnt + 1);

        for (int i = 0; i < size; i++) {
            countByBrand.add(0);
        }

        st = new StringTokenizer(br.readLine());
        while (size-- > 0) {
            int brandId = Integer.parseInt(st.nextToken());

            countByBrand.set(brandId, countByBrand.get(brandId) + 1);
        }

        bw.append(Collections.max(countByBrand) + "\n");
        bw.flush();
    }
}