#include <algorithm>
#include <iostream>
#include <vector>

int binarySearch(std::vector<int> &arr, int pos) {
    int left = 0;
    int right = arr.size();
    int min = (1LL << 31) - 1;

    do {
        int mid = (left + right) / 2;

        min = std::min(min, std::abs(arr[mid] - pos));
        if (arr[mid] == pos) {
            return 0;
        } else if (arr[mid] > pos) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }

    } while (left <= right);
    return min;
}

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int size, findCnt;
    std::vector<int> arr;

    std::cin >> size >> findCnt;
    for (int i = 0; i < size; i++) {
        int pos;

        std::cin >> pos;
        arr.push_back(pos);
    }
    std::sort(arr.begin(), arr.end());

    int ans = (1LL << 31) - 1;
    for (int i = 0; i < findCnt; i++) {
        int pos;

        std::cin >> pos;
        ans = std::min(ans, binarySearch(arr, pos));
        if (ans == 0) {
            break;
        }
    }

    std::cout << ans;
    return 0;
}