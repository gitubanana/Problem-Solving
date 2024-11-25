import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
    static final int COW_COUNT = 12;
    static final int TEAM_COUNT = 4;

    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] skills = new int[COW_COUNT];
    static int[] teamSkills = new int[TEAM_COUNT];
    static boolean[] visited = new boolean[COW_COUNT];
    static int minDiff = Integer.MAX_VALUE;

    public static void main(String[] args) throws Exception {
        for (int i = 0; i < COW_COUNT; i++) {
            skills[i] = Integer.parseInt(br.readLine());
        }

        makeTeams(0);
        bw.append(String.valueOf(minDiff));
        bw.flush();
    }

    static void makeTeams(int teamCount) {
        if (teamCount == TEAM_COUNT) {
            int minSum = Arrays.stream(teamSkills).min().getAsInt();
            int maxSum = Arrays.stream(teamSkills).max().getAsInt();

            minDiff = Math.min(minDiff, maxSum - minSum);
            return;
        }

        for (int one = 0; one < COW_COUNT - 2; one++) {
            if (visited[one]) {
                continue;
            }

            visited[one] = true;
            for (int two = one + 1; two < COW_COUNT - 1; two++) {
                if (visited[two]) {
                    continue;
                }

                visited[two] = true;
                for (int three = two + 1; three < COW_COUNT; three++) {
                    if (visited[three]) {
                        continue;
                    }

                    visited[three] = true;
                    teamSkills[teamCount] = skills[one] + skills[two] + skills[three];
                    makeTeams(teamCount + 1);
                    visited[three] = false;
                }
                visited[two] = false;
            }
            visited[one] = false;
        }
    }
}
