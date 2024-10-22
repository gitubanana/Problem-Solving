import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final int TAKE_A_SEAT = 1;
    static final int GET_OFF = 2;
    static final int MOVE_FORWARD = 3;
    static final int MOVE_BACKWARD = 4;

    static class Train {
        private static final int SEAT_CNT = 20;
        private static final int ALL_ONE = (1 << SEAT_CNT) - 1;

        int seat;

        public void takeAseat(int pos) {
            seat |= (1 << pos);
        }

        public void getOff(int pos) {
            seat &= (ALL_ONE ^ (1 << pos));
        }

        public void moveForward() {
            seat <<= 1;
            align();
        }

        public void moveBackward() {
            seat >>= 1;
            align();
        }

        private void align() {
            seat &= ALL_ONE;
        }
    }

    public static void main(String[] args) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int trainCnt = Integer.parseInt(st.nextToken());
        int cmdCnt = Integer.parseInt(st.nextToken());

        Train[] trains = new Train[trainCnt + 1];
        for (int i = 1; i < trains.length; ++i) {
            trains[i] = new Train();
        }
        while (cmdCnt-- > 0) {
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());
            int index = Integer.parseInt(st.nextToken());

            switch (cmd) {
                case TAKE_A_SEAT:
                    int pos1 = Integer.parseInt(st.nextToken()) - 1;
                    trains[index].takeAseat(pos1);
                    break;
                case GET_OFF:
                    int pos2 = Integer.parseInt(st.nextToken()) - 1;
                    trains[index].getOff(pos2);
                    break;
                case MOVE_FORWARD:
                    trains[index].moveForward();
                    break;
                case MOVE_BACKWARD:
                    trains[index].moveBackward();
                    break;
            }
        }

        HashSet<Integer> passedTrain = new HashSet<>();

        for (int i = 1; i < trains.length; ++i) {
            passedTrain.add(trains[i].seat);
        }

        System.out.println(passedTrain.size());
    }
}