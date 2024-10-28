import java.util.*;
import java.lang.*;
import java.io.*;

class StolenPassports {
    private HashSet<String> passports = new HashSet<>();

    public void add(String passport) {
        passports.add(passport);
    }

    public boolean has(String passport) {
        return passports.contains(passport);
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int stolenCnt = Integer.parseInt(br.readLine());
        StolenPassports stolenPassports = new StolenPassports();

        while (stolenCnt-- > 0) {
            stolenPassports.add(br.readLine());
        }

        int ans = 0;
        int checkCnt = Integer.parseInt(br.readLine());

        while (checkCnt-- > 0) {
            if (stolenPassports.has(br.readLine())) {
                ans++;
            }
        }

        bw.append(ans+"\n");
        bw.flush();
    }
}