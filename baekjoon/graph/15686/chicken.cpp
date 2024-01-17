#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <cstring>
#include <algorithm>

enum e_space
{
    EMPTY = '0',
    HOUSE,
    STORE
};

struct t_pos
{
    int y, x;
};

typedef std::priority_queue<int, std::vector<int>, std::greater<int> > t_pq;
typedef std::vector<t_pos> t_vec;
typedef std::list<int> t_list;

const int   MAX = 50;
const int   INF = 1e9;

char map[MAX][MAX + 1];
int dist[MAX * 2];
int size, store_cnt;
int ans = INF;
t_vec houses, stores;
t_list list;

int get_dist(t_pos &a, t_pos &b)
{
    return std::abs(a.y - b.y) + std::abs(a.x - b.x);
}

void    back_tracking(int i, int depth)
{
    if (depth == store_cnt)
    {
        for (int i = 0; i < houses.size(); ++i)
            dist[i] = INF;

        for (int &idx : list)
        {
            for (int i = 0; i < houses.size(); ++i)
            {
                dist[i] = std::min(dist[i], get_dist(houses[i], stores[idx]));
            }
        }

        int sum = 0;
        for (int i = 0; i < houses.size(); ++i)
            sum += dist[i];

        ans = std::min(ans, sum);
        return ;
    }

    while (i < stores.size())
    {
        list.push_back(i);
        back_tracking(i + 1, depth + 1);
        list.pop_back();
        ++i;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> store_cnt;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> map[y][x];
            switch (map[y][x])
            {
            case HOUSE:
                houses.push_back({y, x});
                break;
            case STORE:
                stores.push_back({y, x});
                break;
            }
        }
    }

    back_tracking(0, 0);

    std::cout << ans << '\n';
    return (0);
}
