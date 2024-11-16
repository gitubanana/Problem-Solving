import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashMap;
import java.util.Map;

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        Map<String, String> nameByAbbr = new HashMap<String, String>() {{
                put("NLCS", "North London Collegiate School");
                put("BHA", "Branksome Hall Asia");
                put("KIS", "Korea International School");
                put("SJA", "St. Johnsbury Academy");
        }};

        bw.append(nameByAbbr.get(br.readLine()));
        bw.flush();
    }
}
