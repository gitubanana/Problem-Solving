#include <iostream>
#include <queue>
#include <vector>

typedef std::vector<int> t_vec;
typedef std::queue<int> t_queue;

enum e_color
{
    EMPTY = 0,
    BLACK = 1,
    WHITE = 2
};

int nextIs[] = {BLACK, WHITE};

int *colors;
t_vec *links;

bool bfs(int start)
{
    t_queue q;

    q.push(start);
    colors[start] = BLACK;
    while (!q.empty())
    {
        int &cur = q.front();
        int &curColor = colors[cur];

        for (int &next: links[cur])
        {
            int &nextColor = colors[next];
            if (nextColor == EMPTY)
            {
                nextColor = nextIs[curColor == BLACK];
                q.push(next);
            }
            else if (nextColor == curColor)
                return false;
        }
        q.pop();
    }
    return true;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int test_cnt;
    int vCnt, eCnt;
    int from, to;
    const std::string msg[] = {"NO", "YES"};

    std::cin >> test_cnt;
    while (test_cnt--)
    {
        std::cin >> vCnt >> eCnt;

        colors = new int[vCnt + 1];
        for (int i = 1; i <= vCnt; ++i)
            colors[i] = EMPTY;

        links = new t_vec[vCnt + 1];
        while (eCnt--)
        {
            std::cin >> from >> to;
            links[from].push_back(to);
            links[to].push_back(from);
        }

        bool isBipartite = true;
        for (int v = 1; v <= vCnt; ++v)
        {
            if (colors[v] == EMPTY && !bfs(v))
            {
                isBipartite = false;
                break ;
            }
        }
        std::cout << msg[isBipartite] << '\n';

        delete[] links;
        delete[] colors;
    }
    return (0);
}
