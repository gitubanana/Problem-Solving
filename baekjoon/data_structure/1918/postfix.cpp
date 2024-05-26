#include <iostream>
#include <stack>

std::string infix;
std::string postfix;
std::stack<char> stack;

inline int getPriority(char op)
{
    switch (op)
    {
    case '(':
        return (0);
    case '+': case '-':
        return (1);
    case '*': case '/':
        return (2);
    }
    return (-1);
}

void    pushOperator(char op)
{
    int curPriority = getPriority(op);

    while (!stack.empty())
    {
        char cmp = stack.top();

        if (getPriority(cmp) < curPriority)
            break ;

        postfix.push_back(cmp);
        stack.pop();
    }
    stack.push(op);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> infix;

    for (const char &ch : infix)
    {
        if (std::isalpha(ch))
        {
            postfix.push_back(ch);
            continue ;
        }

        switch (ch)
        {
        case '(':
            stack.push(ch);
            break ;
        case ')':
            while (!stack.empty())
            {
                char popped = stack.top();
                stack.pop();
                if (popped == '(')
                    break ;

                postfix.push_back(popped);
            }
            break;
        default:
            pushOperator(ch);
        }
    }
    while (!stack.empty())
    {
        postfix.push_back(stack.top());
        stack.pop();
    }
    std::cout << postfix << '\n';
    return (0);
}
