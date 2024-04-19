#include <iostream>
#include <queue>
#include <cmath>

struct t_star
{
    double x;
    double y;
};

struct t_edge
{
    int from;
    double weight;

    inline bool operator<(const t_edge &other) const
    {
        return (this->weight > other.weight);
    }
};

const int V_MAX = 100;

int vCnt;
double ans;
t_star stars[V_MAX];
bool visited[V_MAX];

inline std::istream &operator>>(std::istream &in, t_star &input)
{
    in >> input.x >> input.y;
    return (in);
}

inline double getDist(t_star &from, t_star &to)
{
    return std::sqrt(std::pow(std::abs(from.x - to.x), 2)
            + std::pow(std::abs(from.y - to.y), 2));
}

void    prim(int start=0)
{
    int madeVcnt = 0;
    std::priority_queue<t_edge> pq;

    pq.push({start, 0});
    while (!pq.empty())
    {
        const t_edge cur = pq.top();
        pq.pop();

        if (!visited[cur.from])
        {
            ++madeVcnt;
            ans += cur.weight;
            visited[cur.from] = true;
            if (madeVcnt == vCnt)
                return ;

            for (int v = 0; v < vCnt; ++v)
            {
                if (!visited[v])
                    pq.push({v, getDist(stars[cur.from], stars[v])});
            }
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> vCnt;
    for (int v = 0; v < vCnt; ++v)
    {
        std::cin >> stars[v];
    }

    prim();
    std::cout << ans << '\n';
    return (0);
}
