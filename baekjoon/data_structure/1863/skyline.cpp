#include <iostream>
#include <stack>

//     # #
//  #### ##
// ########

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    int buildingCnt = 0;
    std::stack<int> stack;

    std::cin >> size;
    while (size--)
    {
        int x, height;

        std::cin >> x >> height;
        while (!stack.empty() && stack.top() > height)
        {
            stack.pop();
        }

        if (height > 0 &&
            (stack.empty() || stack.top() < height))
        {
            ++buildingCnt;
            stack.push(height);
        }
    }

    std::cout << buildingCnt << '\n';
    return (0);
}
