import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int pillCnt = Integer.parseInt(br.readLine());
        HashMap<Integer, Integer> pillByEffect = new HashMap<>();

        while (pillCnt-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int effect = Integer.parseInt(st.nextToken());
            int pill = Integer.parseInt(st.nextToken());

            pillByEffect.put(effect, pill);
        }

        int testCnt = Integer.parseInt(br.readLine());

        while (testCnt-- > 0) {
            boolean isDead = false;
            StringTokenizer st = new StringTokenizer(br.readLine());
            ArrayList<String> remedy = new ArrayList<>();

            st.nextToken();
            while (st.hasMoreTokens()) {
                Integer symptom = Integer.parseInt(st.nextToken());
                Integer pill = pillByEffect.get(symptom);

                if (pill == null) {
                    isDead = true;
                    break;
                }

                remedy.add(pill.toString());
            }

            if (isDead) {
                bw.append("YOU DIED");
            } else {
                bw.append(String.join(" ", remedy));
            }

            bw.append("\n");
        }

        bw.flush();
    }
}