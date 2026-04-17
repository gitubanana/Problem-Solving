#include <iostream>

using namespace std;

int dance(int L, int R) {
    if (L >= R) {
        return 0;
    }

    if (L + 1 == R) {
        return L * R;
    }

    int M = (L + R) / 2;

    return dance(L, M) + dance(M+1, R);
}

int main() {
    int size;

    cin >> size;
    cout << dance(1, size);
    return 0;
}