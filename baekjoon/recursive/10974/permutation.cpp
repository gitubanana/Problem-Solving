#include <iostream>

const int MAX = 8;

int limit;
bool visited[MAX];
char toPrint[MAX + 1];

void back_tracking(int depth)
{
    if (depth == limit)
    {
        for (int i = 0; i < limit; ++i)
            std::cout << toPrint[i] << ' ';
        std::cout << '\n';
        return ;
    }

    for (int i = 0; i < limit; ++i)
    {
        if (visited[i])
            continue ;

        toPrint[depth] = '1' + i;
        visited[i] = true;
        back_tracking(depth + 1);
        visited[i] = false;
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> limit;

    back_tracking(0);
    return 0;
}
