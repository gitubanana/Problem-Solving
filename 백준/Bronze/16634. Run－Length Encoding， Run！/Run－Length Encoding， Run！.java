import java.util.Scanner;

// Run length encoding : HHellooo -> H2e1l2o3
// Run length decoding : H2e1l2o3 -> HHellooo
// singleton pattern (Creational Pattern)
class RunLength {
    private static final RunLength instance = new RunLength();

    private RunLength() {
    }

    public static RunLength getInstance() {
        return instance;
    }

    public String encode(String plainText) {
        StringBuilder compressedText = new StringBuilder();

        for (int i = 0; i < plainText.length(); i++) {
            char cur = plainText.charAt(i);
            int cnt = 1;

            for (i++; i < plainText.length(); i++, cnt++) {
                if (cur != plainText.charAt(i)) {
                    i--;
                    break;
                }
            }

            compressedText.append(cur).append(cnt);
        }
        return compressedText.toString();
    }

    public String decode(String compressedText) {
        StringBuilder plainText = new StringBuilder();

        for (int i = 0; i < compressedText.length(); i += 2) {
            char cur = compressedText.charAt(i);
            int cnt = compressedText.charAt(i + 1) - '0';

            plainText.append(String.valueOf(cur).repeat(cnt));
        }
        return plainText.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String cmd = scanner.next();
        String text = scanner.next();
        RunLength runLength = RunLength.getInstance();

        String ans;
        switch (cmd) {
            case "E": // encode
                ans = runLength.encode(text);
                break;
            default: // decode
                ans = runLength.decode(text);
                break;
        }

        System.out.println(ans);
    }
}
