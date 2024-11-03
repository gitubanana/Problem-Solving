import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int cmpNumber;
    static boolean[] visited;
    static List<Integer> numbers = new ArrayList<>();

    public static void main(String[] args) throws Exception {
        String line = br.readLine();

        cmpNumber = Integer.parseInt(line);
        for (int i = 0; i < line.length(); i++) {
            numbers.add(line.charAt(i) - '0');
        }

        visited = new boolean[line.length()];
        numbers.sort(Comparator.naturalOrder());
        backTracking(0, 0);

        bw.append("0");
        bw.flush();
    }

    static void backTracking(int curNumber, int depth) throws Exception {
        if (depth == numbers.size()) {
            if (curNumber <= cmpNumber) {
                return;
            }

            bw.append(curNumber+"\n");
            bw.flush();
            System.exit(0);
        }

        for (int i = 0; i < numbers.size(); i++) {
            if (visited[i]) {
                continue;
            }

            visited[i] = true;
            backTracking(curNumber * 10 + numbers.get(i), depth + 1);
            visited[i] = false;
        }
    }
}