#include <iostream>

const int MAX_SIZE = 1 << 10;

int size;
int arr[MAX_SIZE];

void moveElements(int start, int offset) {
    int size = offset;

    for (int i = 0; i < size; i++) {
        std::swap(arr[start+i], arr[start+i+offset]);
    }
}

int move(int left=0, int right=size-1) {
    if (left >= right) {
        return 0;
    }

    int totalSize = right - left + 1;
    int halfSize = totalSize >> 1; // 산술 연산자 > 시프트 연산자
    int moved = move(left, left+halfSize-1) + move(left+halfSize, right);

    if (arr[left] > arr[left+halfSize]) {
        moved += halfSize * totalSize;
        moveElements(left, halfSize);
    }
    return moved;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    size = 1 << size;
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    std::cout << move() << '\n';
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << '\n';
    }
    return 0;
}