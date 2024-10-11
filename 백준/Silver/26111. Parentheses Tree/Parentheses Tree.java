import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    static class Tree {
        static final char NEW_CHILD = '(';
        static final char END_CHILD = ')';

        String tree;

        public Tree(String tree) {
            this.tree = tree;
        }

        private boolean isLeaf(int idx) {
            return tree.charAt(idx) == NEW_CHILD
                    && tree.charAt(idx + 1) == END_CHILD;
        }

        public long getDistanceSumToLeaves() {
            long sum = 0;
            Stack<Character> stack = new Stack<>();

            for (int i = 0; i < tree.length(); ++i) {
                if (isLeaf(i)) {
                    sum += stack.size();
                    ++i;
                    continue;
                }

                switch (tree.charAt(i)) {
                    case NEW_CHILD :
                        stack.push(NEW_CHILD);
                        break;
                    case END_CHILD :
                        stack.pop();
                        break;
                }
            }
            return sum;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println(new Tree(br.readLine()).getDistanceSumToLeaves());
    }
}
