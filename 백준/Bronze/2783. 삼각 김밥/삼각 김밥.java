import java.util.*;
import java.lang.*;
import java.io.*;

class GimbapPrice {
    private final double pricePerGram;

    public GimbapPrice(int gram, int price) {
        this.pricePerGram = (double) gram / price;
    }

    public double getPriceOf(int purchaseGram) {
        return purchaseGram * pricePerGram;
    }
}

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static final int PURCHASE_GRAM = 1_000;

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        GimbapPrice seven25 = new GimbapPrice(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
        int storeCnt = Integer.parseInt(br.readLine());
        double minPrice = seven25.getPriceOf(PURCHASE_GRAM);

        while (storeCnt-- > 0) {
            st = new StringTokenizer(br.readLine());
            GimbapPrice other = new GimbapPrice(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));

            minPrice = Math.min(minPrice, other.getPriceOf(PURCHASE_GRAM));
        }

        bw.append(String.format("%.2f", minPrice));
        bw.flush();
    }
}