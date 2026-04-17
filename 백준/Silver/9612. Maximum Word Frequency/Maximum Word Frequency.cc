#include <stdio.h>
#include <string.h>
#include <algorithm>

const int MAX_SIZE = 21;

template <typename T>
class Comparable {
public:
    virtual inline bool operator<(const T &) const = 0; // 순수 가상 함수(pure virtual function)
};

class Elem : public Comparable<Elem> {
public:
    char str[MAX_SIZE];
    int cnt;

    Elem(void) : cnt(0) {
        str[0] = 0;
    }

    inline bool operator<(const Elem &other) const {
        if (cnt == other.cnt) {
            return cnt < other.cnt;
        }
        return strcmp(str, other.str) < 0;
    }
};

int findIndex(Elem *arr, int size, char *toFind) {
    static int newIndex = 0;
    int i = 0;

    while (i < size && strcmp(arr[i].str, toFind) != 0) {
        i++;
    }

    if (i == size) {
        strcpy(arr[newIndex].str, toFind);
        return newIndex++;
    }

    return i;
}

int main(void) {
    int size;
    char str[MAX_SIZE];
    fscanf(stdin, " %d", &size);

    Elem *arr = new Elem[size];
    for (int i = 0; i < size; i++) {
        fscanf(stdin, " %s", str);
        arr[findIndex(arr, size, str)].cnt++;
    }

    Elem *ans = std::max_element(arr, arr + size);
    fprintf(stdout, "%s %d\n", ans->str, ans->cnt);

    delete[] arr;
    return 0;
}
