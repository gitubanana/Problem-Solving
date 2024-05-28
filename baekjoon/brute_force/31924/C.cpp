#include <iostream>

const int MAX_SIZE = 100;
const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);
const char msg[] = "MOBIS";
const int msgSize = sizeof(msg) - 1;

int ans, size;
bool visited[MAX_SIZE][MAX_SIZE];
int canMakeIdx[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];

void    checkMobis(int y, int x)
{
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int i = 1;
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];
        while (i < msgSize)
        {
            if (!(0 <= nextY && nextY < size)
                || !(0 <= nextX && nextX < size)
                || map[nextY][nextX] != msg[i])
                break ;

            nextY += dy[dir];
            nextX += dx[dir];
            ++i;
        }

        ans += (i == msgSize);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        std::cin >> map[y];
    }

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            if (map[y][x] == msg[0])
            {
                checkMobis(y, x);
            }
        }
    }
    std::cout << ans << '\n';
    return (0);
}
