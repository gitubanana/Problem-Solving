import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;


class ExpressionsByResult {
    public static final int NUMBER = 4;
    private static final int DEPTH_LIMIT = 3;

    private char[] operations = new char[DEPTH_LIMIT];
    private Map<Integer, String> expressionsByResult = new HashMap<>();

    public ExpressionsByResult() {
        backTracking(0, NUMBER, 0);
    }

    private void backTracking(int sum, int pre, int depth) {
        if (depth == DEPTH_LIMIT) {
            expressionsByResult.putIfAbsent(
                    sum + pre,
                    makeExpression()
            );
            return;
        }

        operations[depth] = '+';
        backTracking(sum + pre, NUMBER, depth + 1);

        operations[depth] = '-';
        backTracking(sum + pre, -NUMBER, depth + 1);

        operations[depth] = '*';
        backTracking(sum, pre * NUMBER, depth + 1);

        operations[depth] = '/';
        backTracking(sum, pre / NUMBER, depth + 1);
    }

    private String makeExpression() {
        return String.format(
                NUMBER + " %c " + NUMBER + " %c " + NUMBER + " %c " + NUMBER,
                operations[0],
                operations[1],
                operations[2]
        );
    }

    public boolean contains(int result) {
        return expressionsByResult.containsKey(result);
    }

    public String getExpression(int result) {
        return expressionsByResult.get(result);
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int testCount = Integer.parseInt(br.readLine());
        ExpressionsByResult expressionsByResult = new ExpressionsByResult();

        while (testCount-- > 0) {
            int result = Integer.parseInt(br.readLine());

            if (expressionsByResult.contains(result)) {
                bw.append(String.format(
                        "%s = %d",
                        expressionsByResult.getExpression(result),
                        result
                ));
            } else {
                bw.append("no solution");
            }
            bw.append(System.lineSeparator());
        }

        bw.flush();
    }
}
