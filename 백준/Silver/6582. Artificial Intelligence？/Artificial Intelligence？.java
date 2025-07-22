import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

class Solver {
    private Map<String, Double> variables = new HashMap<>();

    private double calculateValue(String value) {
        int endIndex = value.length() - 1;
        double unit = 1;

        switch (value.charAt(endIndex)) {
            case 'm':
                unit = 1e-3;
                break;
            case 'k':
                unit = 1e3;
                break;
            case 'M':
                unit = 1e6;
                break;
            default:
                endIndex++;
                break;
        }

        return Double.parseDouble(value.substring(0, endIndex)) * unit;
    }

    public void save(String name, String value) {
        variables.put(name, calculateValue(value));
    }

    public String answer() {
        Double power = variables.get("P");
        Double voltage = variables.get("U");
        Double current = variables.get("I");

        if (voltage == null) {
            return "U=" + String.format("%.2f", power / current) + "V";
        }

        if (current == null) {
            return "I=" + String.format("%.2f", power / voltage) + "A";
        }

        return "P=" + String.format("%.2f", voltage * current) + "W";
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int testCnt = Integer.parseInt(br.readLine());
        String newLine = System.lineSeparator();

        for (int t = 1; t <= testCnt; t++) {
            Solver solver = new Solver();
            StringTokenizer st = new StringTokenizer(br.readLine(), "WVA \t\n\r\f");

            while (st.hasMoreTokens()) {
                String token = st.nextToken();
                int assignIndex = token.indexOf('=');
                if (assignIndex == -1) {
                    continue;
                }

                solver.save(
                        token.substring(0, assignIndex),
                        token.substring(assignIndex + 1)
                );
            }

            bw.append("Problem #").append(String.valueOf(t)).append(newLine);
            bw.append(solver.answer()).append(newLine);
            bw.append(newLine);
        }

        bw.flush();
    }
}
