#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> arr) {

    for (int y = arr.size() - 1; y >= 1; --y)
    {
        for (int x = 0; x < arr[y].size() - 1; ++x)
        {
            arr[y - 1][x] += std::max(
                arr[y][x],
                arr[y][x + 1]
            );
        }
    }

    return arr[0][0];
}