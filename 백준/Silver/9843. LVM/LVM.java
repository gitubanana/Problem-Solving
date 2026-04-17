import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

class CPU {
    private static final int INIT_VALUE = 0;

    private final List<String> instructions;
    private final Stack<Integer> stack = new Stack<>();
    private int pc; // program counter
    private int register;

    public CPU(List<String> instructions) {
        this.instructions = List.copyOf(instructions);
    }

    private boolean execute(String instruction) {
        String[] tokens = instruction.trim().split("\\s+");
        String opcode = tokens[0];
        int operand = (tokens.length > 1 ? Integer.parseInt(tokens[1]) : register);

        switch (opcode) {
            case "PUSH":
                stack.push(operand);
                break;
            case "STORE":
                register = stack.pop();
                break;
            case "LOAD":
                stack.push(register);
                break;
            case "PLUS":
                stack.push(stack.pop() + stack.pop());
                break;
            case "TIMES":
                stack.push(stack.pop() * stack.pop());
                break;
            case "IFZERO":
                if (stack.pop() == 0) {
                    pc = operand;
                }
                break;
            case "DONE":
                return true;
        }
        return false;
    }

    public int run() {
        stack.clear();
        pc = register = INIT_VALUE;

        while (true) {
            if (execute(instructions.get(pc++))) { // DONE
                return stack.pop();
            }
        }
        // not reachable
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        List<String> instructions = new ArrayList<>();

        br.readLine();
        while (true) {
            String instruction = br.readLine();
            if (instruction == null) {
                break;
            }

            instructions.add(instruction);
        }

        System.out.println(new CPU(instructions).run());
    }
}
