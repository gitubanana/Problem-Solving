#include <iostream>
#include <climits>

const int MAX = 20;

int size, min = INT_MAX, limit;
int map[MAX][MAX];
int visited[MAX];

void back_tracking(int start, int depth)
{
    if (depth == limit)
    {
        int diff = 0;

        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                if (y == x)
                    continue ;

                if (visited[y] && visited[x])
                    diff += map[y][x];
                else if (!visited[y] && !visited[x])
                    diff -= map[y][x];
            }
        }

        min = std::min(min, std::abs(diff));
    }

    for (int i = start; i < size; ++i)
    {
        if (visited[i])
            continue ;

        visited[i] = true;
        back_tracking(i, depth + 1);
        visited[i] = false;
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
            std::cin >> map[y][x];
    }

    limit = size / 2;
    back_tracking(0, 0);

    std::cout << min << '\n';
    return 0;
}
