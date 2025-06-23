#include <stdio.h>
#include <vector>

class Elem {
public:
    int num;
    int cnt;
};

int goal;
bool none;
std::vector<Elem> arr;
std::vector<Elem> sumList;

void readArr(int size) {
    int prev = 0;

    arr.clear();
    for (int i = 0; i < size; i++) {
        int num;
    
        scanf(" %d", &num);
        if (num == prev) {
            arr.back().cnt++;
        } else {
            arr.push_back({num, 1});
            prev = num;
        }
    }
}

void printSumList(void) {
    printf("%d", sumList.front().num);
    sumList.front().cnt--;
    for (const Elem &cur : sumList) {
        for (int i = 0; i < cur.cnt; i++) {
            printf("+%d", cur.num);
        }
    }
    sumList.front().cnt++;
    printf("\n");
}

void backTracking(int sum=0, int depth=0) {
    if (sum > goal) {
        return;
    }

    if (depth == arr.size()) {
        if (sum == goal) {
            none = false;
            printSumList();
        }
        return;
    }

    const Elem &cur = arr[depth];
    
    sumList.push_back({cur.num, 0});
    for (int i = cur.cnt; i > 0; i--) {
        sumList.back().cnt = i;
        backTracking(sum + cur.num * i, depth + 1);
    }

    sumList.pop_back();
    backTracking(sum, depth + 1);
}

int main(void) {
    while (true) {
        int size;

        scanf(" %d %d", &goal, &size);
        if (goal == 0 && size == 0) {
            break;
        }

        readArr(size);

        printf("Sums of %d:\n", goal);
        none = true;
        backTracking();
        if (none) {
            printf("NONE\n");
        }
    }
    return 0;
}
