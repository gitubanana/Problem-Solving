import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

class Pos implements Comparable<Pos> {
    int y, x;
    int weight;

    public Pos(int y, int x, int weight) {
        this.y = y;
        this.x = x;
        this.weight = weight;
    }

    @Override
    public int compareTo(Pos other) {
        return this.weight - other.weight;
    }
}

public class Main {
    final static int WALL = -1;
    final static int EMPTY = 0;
    final static int INF = (int)1e8;
    final static int MAX_SIZE = 1000;
    final static int[] dy = {-1, 1, 0, 0};
    final static int[] dx = {0, 0, -1, 1};
    final static int dirSize = dy.length;

    static int ySize, xSize;
    static int[][] map = new int[MAX_SIZE][MAX_SIZE];
    static int[][] dists = new int[MAX_SIZE][MAX_SIZE];

    public static int dijkstra() {
        if (map[0][0] == WALL) {
            return -1;
        }

        PriorityQueue<Pos> pq = new PriorityQueue<>();
        Pos start = new Pos(0, 0, map[0][0]);

        dists[start.y][start.x] = start.weight;
        pq.add(start);
        while (!pq.isEmpty()) {
            Pos cur = pq.poll();

            if (dists[cur.y][cur.x] != cur.weight) {
                continue;
            }

            for (int dir = 0; dir < dirSize; ++dir) {
                Pos next = new Pos(cur.y+dy[dir], cur.x+dx[dir], cur.weight);

                if (!(0 <= next.y && next.y < ySize)
                    || !(0 <= next.x && next.x < xSize)
                    || map[next.y][next.x] == WALL) {
                    continue;
                }

                next.weight += map[next.y][next.x];
                if (dists[next.y][next.x] <= next.weight) {
                    continue;
                }

                dists[next.y][next.x] = next.weight;
                pq.add(next);
            }
        }

        if (dists[ySize - 1][xSize - 1] != INF) {
            return dists[ySize - 1][xSize - 1];
        }
        return -1;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] firstLine = br.readLine().split(" ");

        ySize = Integer.parseInt(firstLine[0]);
        xSize = Integer.parseInt(firstLine[1]);
        for (int y = 0; y < ySize; ++y) {
            String[] line = br.readLine().split(" ");

            for (int x = 0; x < xSize; ++x) {
                dists[y][x] = INF;
                map[y][x] = Integer.parseInt(line[x]);
            }
        }

        System.out.println(dijkstra());
    }
}

