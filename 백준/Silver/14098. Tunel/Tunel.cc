#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>

const int EMPTY = 0;

int globId;
std::unordered_map<std::string, int> strToInt;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int carCnt;
    std::string str;

    std::cin >> carCnt;
    for (int in = 0; in < carCnt; ++in)
    {
        std::cin >> str;
        strToInt[str] = ++globId;
    }

    int pass = 0;
    std::stack<int> stack;
    for (int out = 0; out < carCnt; ++out)
    {
        std::cin >> str;

        int &curId = strToInt[str];
        while (!stack.empty())
        {
            const int &cmpId = stack.top();
            if (cmpId < curId)
                break ;

            ++pass;
            stack.pop();
        }

        stack.push(curId);
    }

    std::cout << pass << '\n';
    return (0);
}
