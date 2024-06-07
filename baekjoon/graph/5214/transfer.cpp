#include <iostream>
#include <queue>

template <typename T>
using t_vec = std::vector<T>;

const int MAX_V = 100000;

bool visited[MAX_V + 1];
t_vec<int> tubeIndices[MAX_V + 1];
t_vec<t_vec<int>> tubes;

int bfs(int start, int end)
{
    int curTime = 2;
    std::queue<int> q;

    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            const int cur = q.front();
            q.pop();

            for (const int &tIdx : tubeIndices[cur])
            {
                for (const int &next : tubes[tIdx])
                {
                    if (visited[next])
                        continue ;

                    if (next == end)
                        return (curTime);

                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        ++curTime;
    }
    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int v;
    int vCnt, tubeSize, tubeCnt;
    t_vec<int> tube;

    std::cin >> vCnt >> tubeSize >> tubeCnt;
    for (int tIdx = 0; tIdx < tubeCnt; ++tIdx)
    {
        for (int i = 0; i < tubeSize; ++i)
        {
            std::cin >> v;
            tube.push_back(v);
            tubeIndices[v].push_back(tIdx);
        }
        tubes.push_back(tube);
        tube.clear();
    }

    std::cout << (vCnt == 1 ? 1 : bfs(1, vCnt)) << '\n';
    return (0);
}
