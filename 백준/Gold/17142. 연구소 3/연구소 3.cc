#include <iostream>
#include <cstring>
#include <climits>
#include <vector>
#include <queue>

enum e_space
{
    VIRUS = '0',
    WALL,
    HOSPITAL
};

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 50;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int minTime = INT_MAX;
int size, vaccineCnt, virusCnt;
char map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];
std::vector<t_pos> hospitals;
std::vector<int> selected;

int bfs(void)
{
    std::queue<t_pos> q;

    memset(visited, false, sizeof(visited));
    for (const int &idx : selected)
    {
        const t_pos &pos = hospitals[idx];

        visited[pos.y][pos.x] = true;
        q.push(pos);
    }

    int curTime = 0;
    int remainVirus = virusCnt;
    while (!q.empty() && remainVirus)
    {
        int qSize = q.size();

        while (qSize--)
        {
            const t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir]
                };

                if (!(0 <= next.y && next.y < size)
                    || !(0 <= next.x && next.x < size)
                    || map[next.y][next.x] == WALL
                    || visited[next.y][next.x])
                    continue ;

                remainVirus -= (map[next.y][next.x] == VIRUS);
                visited[next.y][next.x] = true;
                q.push(next);
            }
        }

        ++curTime;
    }

    return (remainVirus ? INT_MAX : curTime);
}

void    backTracking(int idx=0, int cnt=0)
{
    if (cnt == vaccineCnt)
    {
        minTime = std::min(minTime, bfs());
        return ;
    }

    if (idx == hospitals.size())
    {
        return ;
    }

    selected.push_back(idx);
    backTracking(idx + 1, cnt + 1);
    selected.pop_back();

    backTracking(idx + 1, cnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> vaccineCnt;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            char &space = map[y][x];

            std::cin >> space;
            switch (space)
            {
                case VIRUS:
                    ++virusCnt;
                    break ;
                case HOSPITAL:
                    hospitals.push_back({y, x});
                    break ;
            }
        }
    }

    backTracking();
    std::cout << (minTime == INT_MAX ? -1 : minTime) << '\n';
    return 0;
}
