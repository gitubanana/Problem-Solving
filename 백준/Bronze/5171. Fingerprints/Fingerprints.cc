#include <stdio.h>
#include <vector>

const int SIZE = 5;

struct FingerPrint {
    char map[SIZE][SIZE + 1];

    FingerPrint(void) {
        for (int y = 0; y < SIZE; y++) {
            fscanf(stdin, " %s", map[y]);
        }
    }

    int countDiff(FingerPrint &o) const {
        int cnt = 0;

        for (int y = 0; y < SIZE; y++) {
            for (int x = 0; x < SIZE; x++) {
                cnt += (map[y][x] != o.map[y][x]);
            }
        }
        return cnt;
    }
};

struct DataBase {
    std::vector<FingerPrint> database;

    DataBase(int size) : database(size) { }

    std::vector<int> findSuspects(FingerPrint toFind) {
        std::vector<int> suspects;
        int minDiff = (unsigned int)1 << 31 - 1;

        for (int i = 0; i < database.size(); i++) {
            int cmpDiff = toFind.countDiff(database[i]);
            if (minDiff < cmpDiff) {
                continue;
            }

            if (minDiff > cmpDiff) {
                suspects.clear();
                minDiff = cmpDiff;
            }

            suspects.push_back(i + 1);
        }
        return suspects;
    }
};

int main(void) {
    int dataCnt;
    int crimeCnt;
    fscanf(stdin, " %d %d", &dataCnt, &crimeCnt);

    DataBase database(dataCnt);
    for (int t = 1; t <= crimeCnt; t++) {
        FingerPrint toFind;

        fprintf(stdout, "Data Set %d:\n", t);
        for (const int &suspect : database.findSuspects(toFind)) {
            fprintf(stdout, "%d ", suspect);
        }
        fprintf(stdout, "\n\n");
    }
    return 0;
}
