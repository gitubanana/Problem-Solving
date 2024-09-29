import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;

class Pos {
    final static int dy[] = {1, 0, -1, 0};
    final static int dx[] = {0, 1, 0, -1};
    final static int dirSize = 4;

    int y, x;

    public Pos(int y, int x) {
        this.y = y;
        this.x = x;
    }

    public void Move(int dir) {
        this.y += dy[dir];
        this.x += dx[dir];
    }
}

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int dir = 0;
        Pos player = new Pos(0, 0);
        Pos camera = new Pos(-1, 0);
        int cmdCnt = Integer.parseInt(br.readLine());
        StringBuilder result = new StringBuilder();

        while (cmdCnt-- > 0) {
            switch (br.readLine()) {
                case "W":
                    player.Move(dir);
                    camera.Move(dir);
                    break;
                case "A":
                    player.Move((dir + 3) % Pos.dirSize);
                    camera.Move((dir + 3) % Pos.dirSize);
                    break;
                case "S":
                    player.Move((dir + 2) % Pos.dirSize);
                    camera.Move((dir + 2) % Pos.dirSize);
                    break;
                case "D":
                    player.Move((dir + 1) % Pos.dirSize);
                    camera.Move((dir + 1) % Pos.dirSize);
                    break;
                case "MR":
                    camera.Move(dir);
                    dir = (dir + 1) % Pos.dirSize;
                    camera.Move((dir + 2) % Pos.dirSize);
                    break;
                case "ML":
                    camera.Move(dir);
                    dir = (dir + 3) % Pos.dirSize;
                    camera.Move((dir + 2) % Pos.dirSize);
                    break;
            }

            result.append(player.x+" "+player.y+" "+camera.x+" "+camera.y+"\n");
        }

        System.out.print(result);
    }
}
