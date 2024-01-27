#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

struct t_three
{
    static const int SIZE = 3;

    int svcs[SIZE];
};

const int MAX_POINT = 61;

bool visited[MAX_POINT][MAX_POINT][MAX_POINT];
bool attackedPoint[t_three::SIZE];
std::queue<t_three> q;

inline void makeVisited(bool value, const t_three &cur)
{
    const int *svcs = cur.svcs;
    visited[svcs[0]][svcs[1]][svcs[2]] = value;
}

inline bool allDead(const t_three &toCheck)
{
    for (int i = 0; i < t_three::SIZE; ++i)
    {
        if (toCheck.svcs[i] > 0)
            return (false);
    }
    return (true);
}

bool back_tracking(t_three &cur, int depth)
{
    static const int attackPoint[] = {9, 3, 1};

    if (depth == t_three::SIZE)
    {
        std::sort(cur.svcs, cur.svcs + t_three::SIZE);

        int *svcs = cur.svcs;
        if (visited[svcs[0]][svcs[1]][svcs[2]])
            return (false);

        if (allDead(cur))
            return (true);

        makeVisited(true, cur);
        q.push(cur);
        return (false);
    }

    for (int pointIdx = 0; pointIdx < t_three::SIZE; ++pointIdx)
    {
        if (attackedPoint[pointIdx])
            continue ;

        t_three next = cur;

        if (next.svcs[depth] < attackPoint[pointIdx])
            next.svcs[depth] = 0;
        else
            next.svcs[depth] -= attackPoint[pointIdx];

        attackedPoint[pointIdx] = true;
        if (back_tracking(next, depth + 1))
            return (true);
        attackedPoint[pointIdx] = false;
    }
    return (false);
}

int bfs(const t_three &start)
{
    int attackCnt = 1;

    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            t_three &cur = q.front();

            if (back_tracking(cur, 0))
                return (attackCnt);
            q.pop();
        }
        ++attackCnt;
    }
    return (attackCnt);
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    t_three start;

    std::cin >> size;
    for (int i = 0; i < size; ++i)
        std::cin >> start.svcs[i];   
    for (int i = size; i < t_three::SIZE; ++i)
        start.svcs[i] = 0;

    std::sort(start.svcs, start.svcs + t_three::SIZE);
    std::cout << bfs(start) << '\n';
    return 0;
}
