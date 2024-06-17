#include <iostream>
#include <stack>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int ans = 0;
    std::string str;
    std::stack<char> stack;

    std::cin >> str;
    for (const char &ch : str)
    {
        if (ch == ')')
        {
            if (stack.empty())
                ++ans;
            else
                stack.pop();
        }
        else
        {
            stack.push('(');
        }
    }

    std::cout << ans + stack.size() << '\n';
    return (0);
}
