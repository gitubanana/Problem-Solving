#include <iostream>
#include <climits>

const int MAX_SIZE = 10 + 1;

int max = INT_MIN;
int depthLimit;
int ySize, xSize;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

void    backTracking(int y=1, int x=1, int cur=0, int depth=0)
{
    if (depth == depthLimit)
    {
        max = std::max(max, cur);
        return ;
    }

    while (true)
    {
        if (x > xSize)
        {
            x = 1;
            ++y;
            if (y > ySize)
                break ;
        }

        if (!visited[y - 1][x])
        {
            visited[y][x] = true;
            backTracking(y, x + 2, cur + map[y][x], depth + 1);
            visited[y][x] = false;
        }

        ++x;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize >> depthLimit;
    for (int y = 1; y <= ySize; ++y)
    {
        for (int x = 1; x <= xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    backTracking();
    std::cout << max << '\n';
    return (0);
}
