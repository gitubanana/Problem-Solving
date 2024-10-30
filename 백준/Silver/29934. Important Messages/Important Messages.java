import java.util.*;
import java.lang.*;
import java.io.*;

class Emails {
    private HashSet<String> emails = new HashSet<>();

    public void add(String app) {
        emails.add(app);
    }

    public boolean contains(String app) {
        return emails.contains(app);
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int listCnt = Integer.parseInt(br.readLine());
        Emails emails = new Emails();

        while (listCnt-- > 0) {
            emails.add(br.readLine());
        }

        int ans = 0;
        int checkCnt = Integer.parseInt(br.readLine());

        while (checkCnt-- > 0) {
            if (emails.contains(br.readLine())) {
                ++ans;
            }
        }

        bw.append(ans+"\n");
        bw.flush();
    }
}