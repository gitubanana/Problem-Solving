import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.Inet4Address;
import java.util.ArrayList;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int switchCnt = Integer.parseInt(input[0]);
        int lampCnt = Integer.parseInt(input[1]);
        int[] lampOn = new int[lampCnt + 1];
        ArrayList<Integer>[] switches = new ArrayList[switchCnt];

        for (int s = 0; s < switchCnt; ++s) {
            String[] line = br.readLine().split(" ");

            switches[s] = new ArrayList<>();
            for (int i = 1; i < line.length; ++i) {
                Integer turnOn = Integer.parseInt(line[i]);

                switches[s].add(turnOn);
                ++lampOn[turnOn];
            }
        }

        int isOk = 0;
        for (int s = 0; s < switchCnt; ++s) {
            boolean allOn = true;
            for (Integer turnOff : switches[s]) {
                if (lampOn[turnOff] == 1) {
                    allOn = false;
                    break;
                }
            }

            if (allOn) {
                isOk = 1;
                break;
            }
        }

        System.out.println(isOk);
    }
}

