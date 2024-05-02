#include <iostream>
#include <queue>
#include <climits>
#include <cstring>

struct t_pos
{
    int y;
    int x;

    inline bool operator>(const t_pos &other) const
    {
        if (this->y == other.y)
            return (this->x < other.x);
        return (this->y < other.y);
    }

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

enum e_space
{
    EMPTY = 0,
    WALL
};

const int MAX = 21;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

t_pos taxi;
int size, fuel;
int customerCnt;
int map[MAX][MAX];
bool visited[MAX][MAX];
t_pos dest[MAX * MAX];
const int visitedSize = sizeof(visited);

inline std::istream &operator>>(std::istream &in, t_pos &input)
{
    in >> input.y >> input.x;
    return (in);
}

int findCustomer(void)
{
    int cusNum = INT_MAX;
    t_pos cusPos = {size + 1, size + 1};
    std::queue<t_pos> q;

    if (map[taxi.y][taxi.x] > WALL)
    {
        int cusNum = map[taxi.y][taxi.x];

        map[taxi.y][taxi.x] = EMPTY;
        return (cusNum);
    }

    visited[taxi.y][taxi.x] = true;
    q.push(taxi);
    while (!q.empty() && fuel && cusNum == INT_MAX)
    {
        --fuel;

        int qSize = q.size();
        while (qSize--)
        {
            t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

                if (!(1 <= next.y && next.y <= size)
                    || !(1 <= next.x && next.x <= size)
                    || map[next.y][next.x] == WALL
                    || visited[next.y][next.x])
                    continue ;

                visited[next.y][next.x] = true;
                if (map[next.y][next.x] > WALL
                    && next > cusPos)
                {
                    cusPos = next;
                    cusNum = map[next.y][next.x];
                    continue ;
                }

                q.push(next);
            }
        }
    }

    if (cusNum != INT_MAX)
    {
        map[cusPos.y][cusPos.x] = EMPTY;
        taxi = cusPos;
    }

    return (cusNum);
}

bool takeToDest(int customer)
{
    int dist = 0;
    std::queue<t_pos> q;

    visited[taxi.y][taxi.x] = true;
    q.push(taxi);
    while (!q.empty() && fuel)
    {
        ++dist;
        --fuel;

        int qSize = q.size();
        while (qSize--)
        {
            t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};

                if (!(1 <= next.y && next.y <= size)
                    || !(1 <= next.x && next.x <= size)
                    || map[next.y][next.x] == WALL
                    || visited[next.y][next.x])
                    continue ;

                if (next == dest[customer])
                {
                    fuel += 2 * dist;
                    taxi = next;
                    return (true);
                }

                visited[next.y][next.x] = true;
                q.push(next);
            }
        }
    }
    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start, end;

    std::cin >> size >> customerCnt >> fuel;
    for (int y = 1; y <= size; ++y)
    {
        for (int x = 1; x <= size; ++x)
            std::cin >> map[y][x];
    }
    std::cin >> taxi;
    for (int i = 0; i < customerCnt; ++i)
    {
        int customerNum = (i + 2);

        std::cin >> start >> dest[customerNum];
        map[start.y][start.x] = customerNum;
    }

    while (customerCnt && fuel)
    {
        memset(visited, 0, visitedSize);
        int customer = findCustomer();
        if (customer == INT_MAX)
            break ;

        memset(visited, 0, visitedSize);
        if (!takeToDest(customer))
            break ;

        --customerCnt;
    }

    std::cout << (customerCnt == 0 && fuel >= 0 ? fuel : -1) << '\n';
    return (0);
}
