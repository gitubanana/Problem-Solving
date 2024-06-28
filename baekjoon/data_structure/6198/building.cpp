#include <iostream>
#include <stack>

const int MAX_SIZE = 80000;

int height[MAX_SIZE];
int canSee[MAX_SIZE];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> height[i];
    }

    uint64_t benchMark = 0;
    std::stack<int> front;

    front.push(size - 1);
    for (int cur = size - 2; cur >= 0; --cur)
    {
        int &curCanSee = canSee[cur];
        const int &curHeight = height[cur];

        while (!front.empty())
        {
            const int &top = front.top();
            const int &frontHeight = height[top];
            if (frontHeight >= curHeight)
                break ;

            curCanSee += canSee[top] + 1;
            front.pop();
        }
        front.push(cur);

        benchMark += curCanSee;
    }

    std::cout << benchMark << '\n';
    return (0);
}
