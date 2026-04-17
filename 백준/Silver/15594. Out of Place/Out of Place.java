import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int size = Integer.parseInt(br.readLine());
        List<Integer> arr = new ArrayList<>(size);

        for (int i = 0; i < size; i++) {
            arr.add(Integer.parseInt(br.readLine()));
        }

        List<Integer> sorted = arr.stream().sorted().collect(Collectors.toList());
        if (arr.equals(sorted)) {
            System.out.println(0);
            return;
        }

        int ans = -1;
        for (int i = 0; i < size; i++) {
            if (!Objects.equals(sorted.get(i), arr.get(i))) {
                ans++;
            }
        }

        System.out.println(ans);
    }
}
