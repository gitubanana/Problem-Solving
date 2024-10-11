import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {
    static class Parenthesis {
        String str;

        public Parenthesis(String str) {
            this.str = str;
        }

        private boolean isPoppable(char start, char end) {
            return (start == '(' && end == ')')
                    || (start == ')' && end == '(');
        }

        public int getMaxDepth() {
            int maxDepth = 0;
            Stack<Character> stack = new Stack<>();

            for (int i = 0; i < str.length(); ++i) {
                char end = str.charAt(i);

                if (!stack.isEmpty()) {
                    char start = stack.pop();

                    if (isPoppable(start, end)) {
                        continue;
                    }

                    stack.push(start);
                }

                stack.push(end);
                maxDepth = Math.max(maxDepth, stack.size());
            }

            if (stack.isEmpty()) {
                return maxDepth;
            }

            return -1;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        br.readLine();
        System.out.println(new Parenthesis(br.readLine()).getMaxDepth());
    }
}
