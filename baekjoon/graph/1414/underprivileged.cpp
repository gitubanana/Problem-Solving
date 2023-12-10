#include <iostream>
#include <queue>

struct t_edge
{
    int from;
    int to;
    int weight;

    inline bool operator<(const t_edge &other) const {
        return weight > other.weight;
    }
};

typedef std::priority_queue<t_edge> t_pq;

const int   MAX = 50;

char edges[MAX + 1];
int  parents[MAX];
int  vCnt;
t_pq pq;

int getParent(int x)
{
    if (parents[x] == x)
        return x;
    return parents[x] = getParent(parents[x]);
}

void union_(int y, int x)
{
    int xParent = getParent(x);
    int yParent = getParent(y);

    if (xParent > yParent)
        parents[xParent] = yParent;
    else
        parents[yParent] = xParent;
}

inline bool isLower(int ch)
{
    return ('a' <= ch && ch <= 'z');
}

inline int getWeight(int ch)
{
    static const int minus[] = {'A' - 27, 'a' - 1};

    if (ch == '0')
        return 0;
    return ch - minus[isLower(ch)];
}

int minWeight(void)
{
    int ret = 0;

    for (int v = 0; v < vCnt; ++v)
        parents[v] = v;

    while (!pq.empty())
    {
        const t_edge &cur = pq.top();
        if (getParent(cur.from) != getParent(cur.to))
        {
            ret += cur.weight;
            union_(cur.from, cur.to);
        }
        pq.pop();
    }
    for (int v = 0; v < vCnt; ++v)
    {
        if (getParent(v) != 0)
            return -1;
    }
    return (ret);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int sum = 0;

    std::cin >> vCnt;
    for (int from = 0; from < vCnt; ++from)
    {
        std::cin >> edges;
        for (int to = 0; to < vCnt; ++to)
        {
            char &curCh = edges[to];
            int weight = getWeight(curCh);

            sum += weight;
            if (from == to || weight == 0)
                continue ;
            pq.push({from, to, weight});
        }
    }

    int min = minWeight();
    if (min == -1)
        std::cout << "-1" << '\n';
    else
        std::cout << sum - min << '\n';

    return (0);
}
