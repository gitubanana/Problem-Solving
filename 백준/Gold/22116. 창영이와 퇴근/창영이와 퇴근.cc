#include <iostream>
#include <cstring>

const int MAX_SIZE = 1000;
const int MAX_SLOPE = 1'000'000'000;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

inline bool inRange(int y, int x)
{
    return ((0 <= y && y < size)
            && (0 <= x && x < size));
}

bool dfs(int slope, int y=0, int x=0)
{
    static const int endY = size - 1;
    static const int endX = size - 1;

    if (y == endY && x == endX)
        return (true);

    const int &curHeight = map[y][x];

    visited[y][x] = true;
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!inRange(nextY, nextX)
            || visited[nextY][nextX]
            || std::abs(curHeight - map[nextY][nextX]) > slope)
            continue ;

        if (dfs(slope, nextY, nextX))
            return (true);
    }
    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    int left = 0;
    int right = MAX_SLOPE;
    int min = MAX_SLOPE;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        memset(visited, false, sizeof(visited));
        if (dfs(mid))
        {
            min = std::min(min, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << min << '\n';
    return (0);
}
