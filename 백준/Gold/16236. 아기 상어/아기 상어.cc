#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>

enum e_space
{
    EMPTY = '0',
    ME = '9'
};

struct t_pos
{
    int y, x;

    inline bool operator<(const t_pos &other) const
    {
        if (this->y == other.y)
        {
            return (this->x < other.x);
        }

        return (this->y < other.y);
    }
};

const int MAX_SIZE = 20;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
t_pos me;
char myLevel = '2';
char map[MAX_SIZE][MAX_SIZE + 1];
bool visited[MAX_SIZE][MAX_SIZE];

int bfs(void)
{
    int move = 1;
    t_pos toEat = {INT_MAX, INT_MAX};
    std::queue<t_pos> q;

    memset(visited, false, sizeof(visited));
    visited[me.y][me.x] = true;
    q.push(me);
    while (!q.empty())
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
                    || visited[next.y][next.x])
                    continue ;

                visited[next.y][next.x] = true;
        
                char &cmpLevel = map[next.y][next.x];
                if (cmpLevel > myLevel)
                    continue ;

                if (cmpLevel != EMPTY
                    && cmpLevel < myLevel)
                {
                    toEat = std::min(toEat, next);
                    continue ;
                }

                q.push(next);
            }
        }

        if (toEat.y != INT_MAX)
        {
            me = toEat;
            map[toEat.y][toEat.x] = EMPTY;
            return (move);
        }

        ++move;
    }

    return (-1);
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            char &space = map[y][x];

            std::cin >> space;
            if (space == ME)
            {
                me = {y, x};
                space = EMPTY;
            }
        }
    }

    int ans = 0;
    char eatCnt = '0';
    while (true)
    {
        int moveCnt = bfs();
        if (moveCnt == -1)
            break ;

        ans += moveCnt;
        ++eatCnt;
        if (myLevel == eatCnt)
        {
            ++myLevel;
            eatCnt = '0';
        }
    }

    std::cout << ans << '\n';
    return 0;
}
