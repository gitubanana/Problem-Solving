#include <iostream>
#include <stack>

int calculate(int a, char op, int b)
{
    switch (op)
    {
    case '+':
        return (a + b);
    case '-':
        return (a - b);
    case '*':
        return (a * b);
    }
    return (a / b);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::string postfix;
    std::stack<int> stack;

    std::cin >> postfix;
    for (const char &ch : postfix)
    {
        if (std::isdigit(ch))
        {
            stack.push(ch - '0');
        }
        else
        {
            int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            stack.push(calculate(a, ch, b));
        }
    }

    std::cout << stack.top() << '\n';
    return (0);
}
