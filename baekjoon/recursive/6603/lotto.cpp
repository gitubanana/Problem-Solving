#include <iostream>
#include <algorithm>

const int MAX = 13;

int arr[MAX];
int toPrint[MAX];
int size;
const int LIMIT = 6;

void back_tracking(int cur, int depth)
{
    if (depth == LIMIT)
    {
        for (int i = 0; i < LIMIT; ++i)
        {
            std::cout << toPrint[i] << ' ';
        }
        std::cout << '\n';
        return ;
    }

    for (int i = cur; i < size; ++i)
    {
        toPrint[depth] = arr[i];
        back_tracking(i + 1, depth + 1);
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    while (true)
    {
        std::cin >> size;
        if (size == 0)
            break ;

        for (int i = 0; i < size; ++i)
            std::cin >> arr[i];
    
        back_tracking(0, 0);
        std::cout << '\n';
    }
    return 0;
}
