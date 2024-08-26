#include <string>
#include <vector>

std::vector<std::vector<int>> answer;

void    hanoi(int plateCnt, int from, int to, int by)
{
    if (plateCnt == 1)
    {
        answer.push_back({from, to});
    }
    else
    {
        hanoi(plateCnt - 1, from, by, to);
        answer.push_back({from, to});
        hanoi(plateCnt - 1, by, to, from);
    }
}

std::vector<std::vector<int>> solution(int n) {

    hanoi(n, 1, 3, 2);
    return answer;
}