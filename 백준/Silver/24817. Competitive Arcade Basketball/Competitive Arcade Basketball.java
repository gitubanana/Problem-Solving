import java.util.*;
import java.lang.*;
import java.io.*;

class Points {
    private HashMap<String, Integer> points = new HashMap<>();

    public void add(String user, int point) {
        points.put(user, points.getOrDefault(user, 0) + point);
    }

    public int get(String user) {
        return points.get(user);
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int participantCnt = Integer.parseInt(st.nextToken());
        int requiredPiont = Integer.parseInt(st.nextToken());
        int eventCnt = Integer.parseInt(st.nextToken());
        Points points = new Points();

        while (participantCnt-- > 0) {
            points.add(br.readLine(), 0);
        }

        boolean hasWinner = false;

        while (eventCnt-- > 0) {
            st = new StringTokenizer(br.readLine());
            String user = st.nextToken();
            int point = Integer.parseInt(st.nextToken());

            points.add(user, point);
            if (points.get(user) >= requiredPiont) {
                hasWinner = true;
                bw.append(user+" wins!\n");
                points.add(user, Integer.MIN_VALUE);
            }
        }

        if (!hasWinner) {
            bw.append("No winner!");
        }

        bw.flush();
    }
}