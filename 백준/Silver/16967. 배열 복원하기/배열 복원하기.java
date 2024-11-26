import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int ySize = Integer.parseInt(st.nextToken());
        int xSize = Integer.parseInt(st.nextToken());
        int moveY = Integer.parseInt(st.nextToken());
        int moveX = Integer.parseInt(st.nextToken());
        int[][] map = new int[ySize][xSize];

        for (int y = 0; y < ySize; y++) {
            st = new StringTokenizer(br.readLine());
            for (int x = 0; x < xSize; x++) {
                map[y][x] = Integer.parseInt(st.nextToken());
            }
        }

        for (int y = moveY; y < ySize; y++) {
            for (int x = moveX; x < xSize; x++) {
                map[y][x] -= map[y - moveY][x - moveX];
            }
        }

        for (int y = 0; y < ySize; y++) {
            for (int x = 0; x < xSize; x++) {
                bw.append(String.valueOf(map[y][x]));
                bw.append(' ');
            }
            bw.append(System.lineSeparator());
        }
        bw.flush();
    }
}
