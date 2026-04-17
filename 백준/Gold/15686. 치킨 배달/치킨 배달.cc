#include <iostream>
#include <climits>
#include <vector>

enum e_space
{
    EMPTY = '0',
    PERSON,
    HOSPITAL
};

struct t_pos
{
    int y, x;
};

const int MAX_HOSPITAL = 13;
const int MAX_SIZE = 50;

int minDist = INT_MAX, depthLimit;
std::vector<t_pos> people;
std::vector<t_pos> hospitals;
std::vector<int> chosen;
int dists[MAX_SIZE * 2][MAX_HOSPITAL];

inline int getDist(const t_pos &a, const t_pos &b)
{
    return std::abs(a.y - b.y) + std::abs(a.x - b.x);
}

inline int getHospitalDist(void)
{
    int totalDist = 0;

    for (int pIdx = 0; pIdx < people.size(); ++pIdx)
    {
        int min = INT_MAX;

        for (const int &hIdx : chosen)
        {
            min = std::min(min, dists[pIdx][hIdx]);
        }

        totalDist += min;
    }

    return (totalDist);
}

void    backTracking(int start=0, int depth=0)
{
    if (depth == depthLimit)
    {
        minDist = std::min(minDist, getHospitalDist());
        return ;
    }

    for (int i = start; i < hospitals.size(); ++i)
    {
        chosen.push_back(i);
        backTracking(
            i + 1,
            depth + 1
        );
        chosen.pop_back();
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;

    std::cin >> size >> depthLimit;
    people.reserve(size * 2);
    hospitals.reserve(MAX_HOSPITAL);
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            char space;

            std::cin >> space;
            switch (space)
            {
                case PERSON:
                    people.push_back({y, x});
                    break ;
                case HOSPITAL:
                    hospitals.push_back({y, x});
                    break ;
            }
        }
    }

    for (int pIdx = 0; pIdx < people.size(); ++pIdx)
    {
        for (int hIdx = 0; hIdx < hospitals.size(); ++hIdx)
        {
            dists[pIdx][hIdx] = getDist(people[pIdx], hospitals[hIdx]);
        }
    }

    chosen.reserve(MAX_HOSPITAL);
    backTracking();
    std::cout << minDist << '\n';
    return 0;
}