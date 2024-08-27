#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 500;

int dp[MAX_SIZE][MAX_SIZE];

int solution(vector<vector<int>> arr) {

    dp[0][0] = arr[0][0];
    for (int y = 0; y < arr.size() - 1; ++y)
    {
        for (int x = 0; x < arr[y].size(); ++x)
        {
            dp[y + 1][x] = std::max(
                dp[y + 1][x],
                dp[y][x] + arr[y + 1][x]
            );

            dp[y + 1][x + 1] = std::max(
                dp[y + 1][x + 1],
                dp[y][x] + arr[y + 1][x + 1]
            );
        }
    }

    return *std::max_element(
        dp[arr.size() - 1],
        dp[arr.size() - 1] + arr.back().size()
    );
}