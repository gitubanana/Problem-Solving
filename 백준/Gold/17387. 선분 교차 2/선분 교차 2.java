import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.StringTokenizer;

class Pos {
    public final int x, y;

    public Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public long xDiff(Pos other) {
        return this.x - other.x;
    }

    public long yDiff(Pos other) {
        return this.y - other.y;
    }

    public boolean isLessOrEqual(Pos other) {
        if (this.x == other.x) {
            return this.y <= other.y;
        }
        return this.x <= other.x;
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

    static boolean isTheSameLine(Pos[] la, Pos[] lb) {
        Vector common = new Vector(la[0], la[1]);
        Vector a = new Vector(la[1], lb[0]);
        Vector b = new Vector(la[1], lb[1]);
        long ca = common.product(a);
        long cb = common.product(b);

        return (ca == 0 && cb == 0);
    }

    static boolean isOverlappingInOneLine(Pos[] la, Pos[] lb) {
        Pos a = la[0];
        Pos b = la[1];
        Pos c = lb[0];
        Pos d = lb[1];
        Pos tmp;

        if (b.isLessOrEqual(a)) {
            tmp = a;
            a = b;
            b = tmp;
        }

        if (d.isLessOrEqual(c)) {
            tmp = c;
            c = d;
            d = tmp;
        }

        return c.isLessOrEqual(b) && a.isLessOrEqual(d);
    }

    static boolean isIntersecting(Pos[] la, Pos[] lb) {
        if (isTheSameLine(la, lb)) {
            return isOverlappingInOneLine(la, lb);
        }
        return oppositeSideOf(la, lb) && oppositeSideOf(lb, la);
    }

    public static void main(String[] args) throws IOException {
        Pos[] la = readLine();
        Pos[] lb = readLine();

        System.out.println(
                isIntersecting(la, lb)
                        ? "1"
                        : "0"
        );
    }
}
