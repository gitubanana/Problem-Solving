import java.util.*;
import java.lang.*;
import java.io.*;

class Team {
    private HashSet<String> players = new HashSet<>();

    public void add(String player) {
        players.add(player);
    }

    public boolean has(String player) {
        return players.contains(player);
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        Team A = new Team();
        Team B = new Team();

        br.readLine();

        // A Team
        StringTokenizer st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            A.add(st.nextToken());
        }

        // B Team
        st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            B.add(st.nextToken());
        }

        int aGoal = 0;
        int bGoal = 0;

        st = new StringTokenizer(br.readLine());
        while (st.hasMoreTokens()) {
            String goal = st.nextToken();

            if (A.has(goal)) {
                aGoal++;
            } else {
                bGoal++;
            }
        }

        if (aGoal > bGoal) {
            bw.append("A");
        } else if (aGoal < bGoal) {
            bw.append("B");
        } else {
            bw.append("TIE");
        }

        bw.flush();
    }
}