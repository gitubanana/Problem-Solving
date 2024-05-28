#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

struct t_student
{
    std::string name;
    int ACP_Rank;

    inline bool operator<(const t_student &other) const
    {
        return (this->ACP_Rank < other.ACP_Rank);
    }
};

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int studentCnt;
    int shakeRank;
    t_student pupil;
    std::string jaehak;
    std::string notyet;
    std::priority_queue<t_student> pq;

    std::cin >> studentCnt;
    while (studentCnt--)
    {
        std::cin >> pupil.name >> jaehak >> notyet >> shakeRank >> pupil.ACP_Rank;
        if (jaehak != "jaehak"
            || notyet != "notyet"
            || (0 < shakeRank && shakeRank <= 3))
            continue ;

        pq.push(pupil);
        if (pq.size() > 10)
        {
            pq.pop();
        }
    }

    std::vector<std::string> finalList;
    while (!pq.empty())
    {
        finalList.push_back(pq.top().name);
        pq.pop();
    }

    std::sort(finalList.begin(), finalList.end());
    std::cout << finalList.size() << '\n';
    for (const std::string &name : finalList)
    {
        std::cout << name << '\n';
    }
    return (0);
}
