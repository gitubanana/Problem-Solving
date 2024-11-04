import java.util.*;
import java.lang.*;
import java.io.*;

class Tags {
    private Map<String, Integer> countByTag = new HashMap<>();

    public void add(String tag) {
        countByTag.put(tag, count(tag) + 1);
    }

    public int count(String tag) {
        return countByTag.getOrDefault(tag, 0);
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int size = Integer.parseInt(st.nextToken());
        int maxWeight = Integer.parseInt(st.nextToken());

        st =  new StringTokenizer(br.readLine());
        List<Integer> weights = new ArrayList<>(size);
        while (st.hasMoreTokens()) {
            weights.add(Integer.parseInt(st.nextToken()));
        }

        int ans = 0;
        int left = 0;
        int right = size - 1;
        
        weights.sort(Comparator.naturalOrder());
        while (left < right) {
            int sum = weights.get(left) + weights.get(right);

            if (sum <= maxWeight) {
                ans++;
                left++;
            }

            right--;
        }

        bw.append(ans+"\n");
        bw.flush();
    }
}