import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Pos {
    private final int x, y;

    public Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int xDiff(Pos other) {
        return this.x - other.x;
    }

    public int yDiff(Pos other) {
        return this.y - other.y;
    }
}

class Vector {
    private final int x, y;

    public Vector(Pos a, Pos b) {
        this.x = b.xDiff(a);
        this.y = b.yDiff(a);
    }

    public int product(Vector other) {
        return (this.x * other.y) - (this.y * other.x);
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static Pos readPos() throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        return new Pos(
                Integer.parseInt(st.nextToken()),
                Integer.parseInt(st.nextToken())
        );
    }

    public static void main(String[] args) throws IOException {
        Pos a = readPos();
        Pos b = readPos();
        Pos c = readPos();
        Vector ab = new Vector(a, b);
        Vector bc = new Vector(b, c);

        String ans = "0"; // linear
        int product = ab.product(bc);
        if (product > 0) { // CCW(Counter Clock Wise)
            ans = "1";
        } else if (product < 0) { // CW(Clock Wise)
            ans = "-1";
        }

        System.out.println(ans);
    }
}
