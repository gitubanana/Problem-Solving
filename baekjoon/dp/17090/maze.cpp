#include <iostream>

enum e_status
{
    VISITED = 1,
    OUTSIDE
};

const int MAX = 500;
std::string str = "URDL";
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

int ySize, xSize;
int status[MAX][MAX];
char map[MAX][MAX + 1];

bool    dfs(int y, int x)
{
    if (!(0 <= y && y < ySize)
        || !(0 <= x && x < xSize)
        || status[y][x] == OUTSIDE)
        return (true);

    if (status[y][x] == VISITED)
        return (false);

    status[y][x] = VISITED;

    int dir = str.find(map[y][x]);
    if (dfs(y + dy[dir], x + dx[dir]))
    {
        status[y][x] = OUTSIDE;
        return (true);
    }
    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
    }

    int ans = 0;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            ans += dfs(y, x);
        }
    }
    std::cout << ans << '\n';
    return (0);
}
