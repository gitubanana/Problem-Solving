#include <iostream>
#include <unordered_set>
#include <cstring>
#include <vector>
#include <queue>

const int MAX_NUM = 9999;

bool isNotPrime[MAX_NUM + 1];
bool visited[MAX_NUM + 1];
std::string nums[] = {
    "123456879",
    "0123456789",
    "0123456789",
    "1379"
};

int bfs(std::string &start, std::string &end)
{
    int startNum = std::stoi(start);
    int endNum = std::stoi(end);

    if (startNum == endNum)
        return (0);

    int changeCnt = 0;
    std::queue<std::string> q;

    memset(visited, false, sizeof(visited));
    visited[startNum] = true;
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        ++changeCnt;
        while (qSize--)
        {
            const std::string cur = q.front();
            q.pop();

            for (int i = 0; i < cur.size(); ++i)
            {
                std::string next = cur;

                for (const char &num : nums[i])
                {
                    next[i] = num;

                    int nextNum = std::stoi(next);
                    if (isNotPrime[nextNum] || visited[nextNum])
                        continue ;

                    if (nextNum == endNum)
                        return (changeCnt);

                    visited[nextNum] = true;
                    q.push(next);
                }
            }
        }
    }

    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    for (int start = 2; start <= MAX_NUM; ++start)
    {
        if (isNotPrime[start])
            continue ;

        for (int check = start * 2; check <= MAX_NUM; check += start)
        {
            isNotPrime[check] = true;
        }
    }

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::string start, end;
        std::cin >> start >> end;

        int changeCnt = bfs(start, end);
        if (changeCnt == -1)
        {
            std::cout << "Impossible" << '\n';
        }
        else
        {
            std::cout << changeCnt << '\n';
        }
    }
    return (0);
}
