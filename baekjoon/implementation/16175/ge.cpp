#include <iostream>
#include <algorithm>
#include <vector>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    while (testCnt--)
    {
        int candidateCnt, regionCnt;
        std::cin >> candidateCnt >> regionCnt;

        std::vector<int> votes(candidateCnt, 0);
        while (regionCnt--)
        {
            for (int i = 0; i < candidateCnt; ++i)
            {
                int vote;

                std::cin >> vote;
                votes[i] += vote;
            }
        }

        std::cout << std::max_element(
                        votes.begin(),
                        votes.end()
                    ) - votes.begin() + 1<< '\n';
    }
    return (0);
}
