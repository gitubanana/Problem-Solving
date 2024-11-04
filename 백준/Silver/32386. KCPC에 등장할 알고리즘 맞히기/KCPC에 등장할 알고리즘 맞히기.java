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
        int problemCnt = Integer.parseInt(br.readLine());
        String maxTag = "";
        int maxTagCnt = 0;
        boolean onlyMax = false;
        Tags tags = new Tags();

        while (problemCnt-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());

            st.nextToken();
            st.nextToken();
            while (st.hasMoreTokens()) {
                String tag = st.nextToken();
                tags.add(tag);

                int tagCnt = tags.count(tag);
                if (maxTagCnt < tagCnt) {
                    maxTagCnt = tagCnt;
                    onlyMax = true;
                    maxTag = tag;
                } else if (maxTagCnt == tagCnt) {
                    onlyMax = false;
                }
            }
        }

        if (onlyMax) {
            bw.append(maxTag+"\n");
        } else {
            bw.append("-1");
        }

        bw.flush();
    }
}