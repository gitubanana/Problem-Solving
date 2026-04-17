#include <iostream>

#include <queue>

#include <climits>

enum e_space

{

    WALL = '0',

    EMPTY

};

struct t_pos

{

    int y, x;

    int breakCnt;

};

const int dy[] = {1, -1, 0, 0};

const int dx[] = {0, 0, 1, -1};

const int dirSize = sizeof(dy) / sizeof(dy[0]);

const int MAX_SIZE = 50;

int size;

char map[MAX_SIZE][MAX_SIZE + 1];

bool visited[MAX_SIZE][MAX_SIZE][MAX_SIZE * MAX_SIZE];

inline bool &getVisited(const t_pos &p)

{

    return visited[p.y][p.x][p.breakCnt];

}

int bfs()

{

    int minBreak = INT_MAX;

    std::queue<t_pos> q;

    visited[0][0][0] = true;

    q.push({0, 0, 0});

    while (!q.empty())

    {

        t_pos cur = q.front();

        q.pop();

        if (minBreak <= cur.breakCnt)

        {

            continue;

        }

        for (int dir = 0; dir < dirSize; ++dir)

        {

            t_pos next = {

                cur.y + dy[dir],

                cur.x + dx[dir],

                cur.breakCnt

            };

            if (!(0 <= next.y && next.y < size)

                || !(0 <= next.x && next.x < size)

                || getVisited(next))

                continue;

            getVisited(next) = true;

            if (next.y == size - 1

                && next.x == size - 1)

            {

                minBreak = std::min(

                    minBreak,

                    next.breakCnt

                );

            }

            else

            {

                next.breakCnt += (map[next.y][next.x] == WALL);

                q.push(next);

            }

        }

    }

    return minBreak;

}

int main()

{

    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;

    for (int y = 0; y < size; ++y)

    {

        std::cin >> map[y];

    }

    std::cout << bfs() << '\n';

    return 0;

}

