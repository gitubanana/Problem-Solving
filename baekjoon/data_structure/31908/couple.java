import java.util.*;
import java.lang.*;
import java.io.*;
import java.util.stream.Collectors;

class CoupleMap {
    Map<String, List<String>> coupleMap = new HashMap<>();

    void add(String ring, String name) {
        List<String> people = coupleMap.getOrDefault(ring, new ArrayList<>());

        people.add(name);
        coupleMap.put(ring, people);
    }

    List<List<String>> toList() {
        return coupleMap.entrySet().stream()
            .filter(entry -> entry.getValue().size() == 2)
            .map(entry -> entry.getValue())
            .collect(Collectors.toList());
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    public static void main(String[] args) throws IOException {
        int size = Integer.parseInt(br.readLine());
        CoupleMap coupleMap = new CoupleMap();

        while (size-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            String name = st.nextToken();
            String ring = st.nextToken();
            if (ring.equals("-")) {
                continue;
            }

            coupleMap.add(ring, name);
        }

        List<List<String>> couples = coupleMap.toList();

        System.out.println(couples.size());
        couples.forEach(couple -> System.out.println(String.join(" ", couple)));
    }
}
