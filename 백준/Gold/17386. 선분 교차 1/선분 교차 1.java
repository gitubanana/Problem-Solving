import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Pos {
    private final long x, y;

    public Pos(long x, long y) {
        this.x = x;
        this.y = y;
    }

    public long xDiff(Pos other) {
        return this.x - other.x;
    }

    public long yDiff(Pos other) {
        return this.y - other.y;
    }
}

class Vector {
    private final long x, y;

    public Vector(Pos a, Pos b) {
        this.x = b.xDiff(a);
        this.y = b.yDiff(a);
    }

    public long product(Vector other) {
        return (this.x * other.y) - (this.y * other.x);
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static Pos[] readLine() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        Pos[] line = new Pos[2];

        line[0] = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        line[1] = new Pos(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        return line;
    }

    static boolean oppositeSideOf(Pos[] line, Pos[] points) {
        Vector common = new Vector(line[0], line[1]);
        Vector a = new Vector(line[1], points[0]);
        Vector b = new Vector(line[1], points[1]);
        long ca = common.product(a);
        long cb = common.product(b);

        return (ca >= 0 && cb <= 0) || (ca <= 0 && cb >= 0);
    }

    public static void main(String[] args) throws IOException {
        Pos[] l1 = readLine();
        Pos[] l2 = readLine();

        System.out.println(
                oppositeSideOf(l1, l2) && oppositeSideOf(l2, l1)
                        ? "1"
                        : "0"
        );
    }
}
