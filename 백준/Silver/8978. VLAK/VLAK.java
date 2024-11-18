import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;

class Car {
    private static final int ALPHABET_COUNT = 26;

    private int seatedCount;
    private int remainSeatCount;
    private final int[] countByAlphabet = new int[ALPHABET_COUNT];

    public Car(int remainSeatCount) {
        this.remainSeatCount = remainSeatCount;
    }

    public void boardedBy(String name) {
        seatedCount++;
        remainSeatCount--;
        countByAlphabet[toIndex(name)]++;
    }

    private int toIndex(String name) {
        return name.charAt(0) - 'a';
    }

    public boolean isNotFull() {
        return remainSeatCount > 0;
    }

    public int getRemainSeatCount() {
        return remainSeatCount;
    }

    public int getSeatedCount() {
        return seatedCount;
    }

    public int getSeatCountStartsWith(String name) {
        return countByAlphabet[toIndex(name)];
    }
}

class Cars {
    private final List<Car> cars;

    public Cars(List<Car> cars) {
        this.cars = cars;
    }

    public void makeSeatFor(String name) {
        final int minSeatCountWithName = cars.stream()
                .filter(Car::isNotFull)
                .mapToInt(car -> car.getSeatCountStartsWith(name))
                .min()
                .getAsInt();
        List<Car> carsWithMinNameCount = cars.stream()
                .filter(Car::isNotFull)
                .filter(car -> car.getSeatCountStartsWith(name) == minSeatCountWithName)
                .collect(Collectors.toList());

        final int minSeatedCount = carsWithMinNameCount.stream()
                .mapToInt(Car::getSeatedCount)
                .min()
                .getAsInt();
        List<Car> carsWithMinSeatedCount = carsWithMinNameCount.stream()
                .filter(car -> car.getSeatedCount() == minSeatedCount)
                .collect(Collectors.toList());

        carsWithMinSeatedCount.get(0).boardedBy(name);
    }

    public List<Integer> toSeatedCountList() {
        return cars.stream()
                .map(Car::getSeatedCount)
                .collect(Collectors.toList());
    }
}

public class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int carCount = Integer.parseInt(st.nextToken());
        int remainSeatCount = Integer.parseInt(st.nextToken());
        int boardCount = Integer.parseInt(br.readLine());
        List<Car> carList = new ArrayList<>(carCount);

        while (carCount-- > 0) {
            carList.add(new Car(remainSeatCount));
        }

        Cars cars = new Cars(carList);

        while (boardCount-- > 0) {
            cars.makeSeatFor(br.readLine());
        }

        for (Integer seatedCount : cars.toSeatedCountList()) {
            bw.append(seatedCount + " ");
        }
        bw.flush();
    }
}
