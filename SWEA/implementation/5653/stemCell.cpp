#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <map>

struct t_pos
{
    int y, x;

    inline bool operator<(const t_pos &other) const
    {
        if (this->y == other.y)
            return (this->x < other.x);
        return (this->y < other.y);
    }
};

struct t_cell
{
    int timeToActivate;
    int activationTime;
};

const int MAX_TIME = 300;

int endTime;
std::map<t_pos, t_cell> map_;
std::set<t_pos> activate[MAX_TIME + 1];
int alive[MAX_TIME + 1];

void    simulation()
{
    typedef typename std::map<t_pos, t_cell>::iterator t_iter;
    static const int dy[] = {-1, 1, 0, 0};
    static const int dx[] = {0, 0, -1, 1};
    static const int dirSize = sizeof(dy) / sizeof(dy[0]);

    int time_ = 0;

    do
    {
        for (const t_pos &cur : activate[time_])
        {
            t_cell &curCell = map_[cur];

            ++alive[curCell.activationTime + curCell.timeToActivate - 1];
            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {cur.y + dy[dir], cur.x + dx[dir]};
                t_iter it = map_.find(next);

                if (it == map_.end())
                {
                    int activationTime = time_ + curCell.timeToActivate + 1;

                    map_.insert({next, {curCell.timeToActivate, activationTime}});
                    activate[activationTime].insert(next);
                }
                else if (it->second.timeToActivate < curCell.timeToActivate)
                {
                    t_cell &nextCell = it->second;

                    if (nextCell.activationTime - nextCell.timeToActivate - 1 != time_)
                        continue ;

                    activate[nextCell.activationTime].erase(next);
                    nextCell.timeToActivate = curCell.timeToActivate;
                    nextCell.activationTime = time_ + nextCell.timeToActivate + 1;
                    activate[nextCell.activationTime].insert(next);
                }
            }
        }

        ++time_;
    } while (time_ < endTime);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    int timeToActivate;
    int ySize, xSize;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        std::cin >> ySize >> xSize >> endTime;

        t_pos pos = {0, 0};
        for (; pos.y < ySize; ++pos.y)
        {
            for (pos.x = 0; pos.x < xSize; ++pos.x)
            {
                std::cin >> timeToActivate;
                if (timeToActivate == 0)
                    continue ;

                map_[pos] = {timeToActivate, timeToActivate};
                activate[timeToActivate].insert(pos);
            }
        }

        simulation();

        int cnt = 0;

        map_.clear();
        for (int i = 1; i <= MAX_TIME; ++i)
        {
            if (i >= endTime)
            {
                if (activate[i].size() > 0 || alive[i] > 0)
                {
                    cnt += activate[i].size() + alive[i];
                }
            }

            activate[i].clear();
        }
        memset(alive, 0, sizeof(alive));
        std::cout << "#" << t << ' ' << cnt << '\n';
    }
    return (0);
}
