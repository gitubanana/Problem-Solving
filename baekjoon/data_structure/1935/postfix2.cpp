#include <iostream>
#include <unordered_map>
#include <iomanip>
#include <stack>

double calculate(double a, char op, double b)
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

    int operandCnt;
    std::string postfix;
    std::stack<double> stack;
    std::unordered_map<char, double> operValue;

    std::cin >> operandCnt >> postfix;
    for (int i = 0; i < operandCnt; ++i)
    {
        double operand;

        std::cin >> operand;
        operValue.insert({'A' + i, operand});
    }

    for (const char &ch : postfix)
    {
        if (std::isalpha(ch))
        {
            stack.push(operValue[ch]);
        }
        else
        {
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();

            stack.push(calculate(a, ch, b));
        }
    }

    std::cout << std::fixed << std::setprecision(2) << stack.top() << '\n';
    return (0);
}
