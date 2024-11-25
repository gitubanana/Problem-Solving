import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
    static final int COW_COUNT = 12;
    static final int TEAM_COUNT = 4;
    static final int MEMBER_COUNT = 3;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] skills = new int[COW_COUNT];
    static int[] teamSkills = new int[TEAM_COUNT];
    static int[] teamMemberCount = new int[TEAM_COUNT];
    static int minDiff = Integer.MAX_VALUE;

    public static void main(String[] args) throws Exception {
        for (int i = 0; i < COW_COUNT; i++) {
            skills[i] = Integer.parseInt(br.readLine());
        }

        makeTeams(0);
        bw.append(String.valueOf(minDiff));
        bw.flush();
    }

    static void makeTeams(int cowIndex) {
        if (cowIndex == COW_COUNT) {
            int minSum = Arrays.stream(teamSkills).min().getAsInt();
            int maxSum = Arrays.stream(teamSkills).max().getAsInt();

            minDiff = Math.min(minDiff, maxSum - minSum);
            return;
        }

        for (int teamIndex = 0; teamIndex < TEAM_COUNT; teamIndex++) {
            if (teamMemberCount[teamIndex] == MEMBER_COUNT) {
                continue;
            }

            teamMemberCount[teamIndex]++;
            teamSkills[teamIndex] += skills[cowIndex];

            makeTeams(cowIndex + 1);

            teamMemberCount[teamIndex]--;
            teamSkills[teamIndex] -= skills[cowIndex];
        }
    }
}
