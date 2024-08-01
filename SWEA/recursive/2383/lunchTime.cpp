#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include <deque>

enum e_space
{
    EMPTY = 0,
    PERSON
};

struct t_pos
{
    int y, x;
};

struct t_dist
{
    int dist;
    int pIdx;

    inline bool operator<(const t_dist &other) const
    {
        return (this->dist < other.dist);
    }
};

const int MAX_SIZE = 10;
const int MAX_PEOPLE = 10;
const int STAIR_CNT = 2;
const int DOWN_LIMIT = 3;

int ans, size;
int map[MAX_SIZE][MAX_SIZE];
bool goOne[MAX_PEOPLE];
t_pos stairs[STAIR_CNT];
std::vector<t_dist> order[STAIR_CNT];
std::vector<t_pos> people;

inline int getDist(const t_pos &a, const t_pos &b)
{
    return std::abs(a.y - b.y) + std::abs(a.x - b.x);
}

void    makeOrder(void)
{
    for (int sIdx = 0; sIdx < STAIR_CNT; ++sIdx)
    {
        std::vector<t_dist> &curOrder = order[sIdx];

        curOrder.clear();
        for (int pIdx = 0; pIdx < people.size(); ++pIdx)
        {
            curOrder.push_back({
                getDist(stairs[sIdx], people[pIdx]),
                pIdx
            });
        }

        std::sort(curOrder.begin(), curOrder.end());
    }
}

int calculateTime(int sIdx, bool value)
{
    std::deque<int> line;

    for (const t_dist &person : order[sIdx])
    {
        if (goOne[person.pIdx] == value)
        {
            line.push_back(person.dist);
        }
    }

    if (line.empty())
        return (0);

    int curTime = line.front();
    int &stairLen = map[stairs[sIdx].y][stairs[sIdx].x];
    while (!line.empty())
    {
        int popCnt = 0;

        ++curTime;
        for (int i = 0; i < DOWN_LIMIT; ++i)
        {
            if (i >= line.size() || curTime - line[i] <= stairLen)
                break ;

            ++popCnt;
        }

        for (int i = 0; i < popCnt; ++i)
        {
            line.pop_front();
        }

        for (int i = DOWN_LIMIT - popCnt; i < DOWN_LIMIT; ++i)
        {
            if (i >= line.size() || curTime <= line[i])
                break ;

            line[i] = curTime - 1;
        }
    }

    return (curTime);
}

void    backTracking(int idx=0)
{
    if (idx == people.size())
    {
        ans = std::min(
            ans,
            std::max(calculateTime(0, true), calculateTime(1, false))
        );
        return ;
    }

    goOne[idx] = true;
    backTracking(idx + 1);
    goOne[idx] = false;

    backTracking(idx + 1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        int sIdx = 0;
        people.clear();

        std::cin >> size;
        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                int &space = map[y][x];

                std::cin >> space;
                switch (space)
                {
                case EMPTY:
                    break;
                case PERSON:
                    people.push_back({y, x});
                    break;
                default:
                    stairs[sIdx++] = {y, x};
                    break;
                }
            }
        }

        ans = INT_MAX;
        makeOrder();
        backTracking();
        std::cout << '#' << t << ' ' << ans << '\n';
    }
    return (0);
}
