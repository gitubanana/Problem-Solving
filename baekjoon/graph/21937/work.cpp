#include <iostream>
#include <vector>

typedef std::vector<int> t_vec;

const int   MAX = 100001;

t_vec map[MAX];
bool  visited[MAX];
int   vCnt, start, ans;

void    dfs(int cur)
{
    t_vec   &linked = map[cur];

    visited[cur] = true;
    for (const int &next: linked)
    {
        if (visited[next])
            continue ;

        ++ans;
        dfs(next);
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;
    while (eCnt--)
    {
        int start, end;
        std::cin >> start >> end;
        map[end].push_back(start);
    }
    std::cin >> start;

    dfs(start);
    std::cout << ans << '\n';
    return 0;
}
