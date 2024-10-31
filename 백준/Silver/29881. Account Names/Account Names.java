import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        int size = Integer.parseInt(br.readLine());
        HashMap<String, String> lastNames = new HashMap<>();
        HashMap<String, String> accounts = new HashMap<>();

        for (int i = 0; i < size; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String firstName = st.nextToken();
            String lastName = st.nextToken();

            lastNames.put(firstName, lastName);
        }

        for (int i = 0; i < size; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String firstName = st.nextToken();
            String account = st.nextToken();

            accounts.put(firstName, account);
        }

        for (var entry : lastNames.entrySet()) {
            String firstName = entry.getKey();
            String lastName = entry.getKey();

            bw.append(lastName);
            bw.append(" ");
            bw.append(accounts.get(firstName));
            bw.append("\n");
        }

        bw.flush();
    }
}