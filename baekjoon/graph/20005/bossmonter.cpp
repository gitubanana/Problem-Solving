#include <iostream>
#include <queue>

enum e_space
{
    EMPTY = '.',
    WALL = 'X',
    BOSS = 'B'
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 1000;
const int MAX_PLAYER = 26;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize, playerCnt, bossHP;
int dps[MAX_PLAYER];
char map[MAX_SIZE][MAX_SIZE + 1];
bool visited[MAX_SIZE][MAX_SIZE];
std::queue<t_pos> q;

int    simulation(void)
{
    std::vector<int> hittingPlayer;

    while (bossHP > 0)
    {
        int qSize = q.size();
        while (qSize--)
        {
            t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir]
                };

                if (!(0 <= next.y && next.y < ySize)
                    || !(0 <= next.x && next.x < xSize)
                    || map[next.y][next.x] == WALL
                    || visited[next.y][next.x])
                    continue ;

                char &nextSpace = map[next.y][next.x];
                if (std::islower(nextSpace))
                {
                    hittingPlayer.push_back(nextSpace - 'a');
                }

                visited[next.y][next.x] = true;
                q.push(next);
            }
        }

        for (const int &idx : hittingPlayer)
        {
            bossHP -= dps[idx];
        }
    }

    return (hittingPlayer.size());
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize >> playerCnt;
    for (int y = 0; y < ySize; ++y)
    {
        std::cin >> map[y];
        if (q.size())
            continue ;

        for (int x = 0; x < xSize; ++x)
        {
            char &space = map[y][x];

            if (space == BOSS)
            {
                visited[y][x] = true;
                q.push({y, x});
                break ;
            }
        }
    }
    for (int i = 0; i < playerCnt; ++i)
    {
        char ch;

        std::cin >> ch >> dps[ch - 'a'];
    }
    std::cin >> bossHP;

    std::cout << simulation() << '\n';
    return (0);
}
