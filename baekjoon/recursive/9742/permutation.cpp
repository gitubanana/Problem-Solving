#include <iostream>
#include <cstring>

const int MAX = 11;

char p[MAX];
char str[MAX];
bool visited[MAX];
int findCnt, pCnt;

bool back_tracking(int depth=0)
{
    if (str[depth] == '\0')
    {
        ++pCnt;
        if (pCnt == findCnt)
        {
            p[depth] = '\0';
            std::cout << p;
            return true;
        }
        return false;
    }

    for (int i = 0; str[i]; ++i)
    {
        if (visited[i])
            continue ;

        visited[i] = true;
        p[depth] = str[i];
        if (back_tracking(depth + 1))
            return true;
        visited[i] = false;
    }
    return false;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    while (std::cin >> str >> findCnt)
    {
        std::cout << str << ' ' << findCnt << " = ";
        if (!back_tracking())
            std::cout << "No permutation";
        std::cout << '\n';
        pCnt = 0;
        memset(visited, false, sizeof(visited));
    }
    return (0);
}
