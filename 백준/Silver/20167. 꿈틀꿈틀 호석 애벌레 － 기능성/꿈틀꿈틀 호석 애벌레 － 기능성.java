import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static int[] arr;
    static int limit;
    static int maxEnergy;

    static void backTracking(int index, int energy) {
        if (index == arr.length) {
            maxEnergy = Math.max(maxEnergy, energy);
            return;
        }

        // 선택 안 함
        backTracking(index + 1, energy);

        // 선택
        int content = 0;
        while (index < arr.length) {
            content += arr[index++];
            if (content >= limit) {
                energy += content - limit;
                break;
            }
        }
        backTracking(index, energy);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int size = Integer.parseInt(st.nextToken());

        limit = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        arr = new int[size];
        for (int i = 0; i < size; ++i) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        backTracking(0, 0);
        System.out.println(maxEnergy);
    }
}