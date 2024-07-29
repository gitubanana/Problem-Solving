#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 1000;
const int MAX_SOLIDITY = 1e6;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize, wantMineral;
int solidity[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
std::vector<t_pos> startPos;

bool canGetWantMineral(int diggerSolidity)
{
    int get = 0;
    std::queue<t_pos> q;

    memset(visited, false, sizeof(visited));
    for (const t_pos &pos : startPos)
    {
        if (solidity[pos.y][pos.x] > diggerSolidity)
            continue ;

        ++get;
        visited[pos.y][pos.x] = true;
        q.push(pos);
    }
    if (get >= wantMineral)
        return (true);

    while (!q.empty())
    {
        const t_pos cur = q.front();
        q.pop();

        for (int dir = 0; dir < dirSize; ++dir)
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir]
            };

            if (!(0 <= next.y && next.y < ySize)
                || !(0 <= next.x && next.x < xSize)
                || solidity[next.y][next.x] > diggerSolidity
                || visited[next.y][next.x])
                continue ;

            ++get;
            if (get >= wantMineral)
                return (true);

            visited[next.y][next.x] = true;
            q.push(next);
        }
    }

    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize >> wantMineral;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> solidity[y][x];
        }
    }
    for (int x = 0; x < xSize; ++x)
    {
        startPos.push_back({0, x});
    }
    for (int y = 1; y < ySize; ++y)
    {
        startPos.push_back({y, 0});
        startPos.push_back({y, xSize - 1});
    }

    int ans = INT_MAX;
    int left = 1;
    int right = MAX_SOLIDITY;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (canGetWantMineral(mid))
        {
            ans = std::min(ans, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << ans << '\n';
    return (0);
}
