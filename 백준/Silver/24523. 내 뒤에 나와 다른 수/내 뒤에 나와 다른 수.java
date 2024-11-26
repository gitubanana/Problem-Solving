import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {
    static final int NONE = -1;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int size = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[size];

        for (int i = 0; i < size; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int[] ans = new int[size];
        Stack<Integer> stack = new Stack<>();

        for (int i = size - 1; i >= 0; i--) {
            int curNum = arr[i];

            while (!stack.isEmpty()) {
                int cmpIndex = stack.peek();
                if (curNum != arr[cmpIndex]) {
                    break;
                }

                stack.pop();
            }

            ans[i] = (stack.isEmpty() ? NONE : stack.peek() + 1);
            stack.push(i);
        }

        for (int i = 0; i < size; i++) {
            bw.append(String.valueOf(ans[i]));
            bw.append(' ');
        }
        bw.flush();
    }
}
