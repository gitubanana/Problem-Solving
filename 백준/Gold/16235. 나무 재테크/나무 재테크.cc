#include <iostream>
#include <algorithm>
#include <deque>

const int MAX_SIZE = 10;
const int INIT_FEEDING = 5;
const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
int feeding[MAX_SIZE][MAX_SIZE];
int plusFeed[MAX_SIZE][MAX_SIZE];
std::deque<int> virusAges[MAX_SIZE][MAX_SIZE];

void    makeVirusOlder(void)
{
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            int &curFeeding = feeding[y][x];
            std::deque<int> &ages = virusAges[y][x];

            int feed = 0;
            for (; feed < ages.size(); ++feed)
            {
                int &feedAge = ages[feed];

                if (curFeeding - feedAge < 0)
                    break ;

                curFeeding -= feedAge;
                ++feedAge;
            }

            for (int die = ages.size() - 1; die >= feed; --die)
            {
                int &dieAge = ages[die];

                curFeeding += dieAge / 2;
                ages.pop_back();
            }
        }
    }
}

void    breedVirus(void)
{
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::deque<int> &ages = virusAges[y][x];

            for (const int &age : ages)
            {
                if (age % 5 != 0)
                    continue ;

                for (int dir = 0; dir < dirSize; ++dir)
                {
                    int nextY = y + dy[dir];
                    int nextX = x + dx[dir];

                    if (!(0 <= nextY && nextY < size)
                        || !(0 <= nextX && nextX < size))
                        continue ;

                    virusAges[nextY][nextX].push_front(1);
                }
            }
        }
    }
}

int getVirusCnt(void)
{
    int cnt = 0;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            cnt += virusAges[y][x].size();
        }
    }
    return (cnt);
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int virusCnt, cycleCnt;

    std::cin >> size >> virusCnt >> cycleCnt;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            feeding[y][x] = INIT_FEEDING;
            std::cin >> plusFeed[y][x];
        }
    }
    while (virusCnt--)
    {
        int y, x, age;

        std::cin >> y >> x >> age;
        virusAges[y - 1][x - 1].push_back(age);
    }

    while (cycleCnt--)
    {
        makeVirusOlder();
        breedVirus();
        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                feeding[y][x] += plusFeed[y][x];
            }
        }
    }

    std::cout << getVirusCnt() << '\n';
    return 0;
}
