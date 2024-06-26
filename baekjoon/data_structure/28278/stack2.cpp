#include <iostream>
#include <stack>

struct t_stack
{
    std::stack<int> stack;

    inline void    push(void)
    {
        int x;

        std::cin >> x;
        stack.push(x);
    }

    inline void pop(void)
    {
        if (stack.empty())
        {
            std::cout << "-1";
        }
        else
        {
            std::cout << stack.top();
            stack.pop();
        }
        std::cout << '\n';
    }

    inline void size(void)
    {
        std::cout << stack.size() << '\n';
    }

    inline void empty(void)
    {
        std::cout << stack.empty() << '\n';
    }

    inline void top(void)
    {
        std::cout << (stack.empty() ? -1 : stack.top()) << '\n';
    }
};

using t_cmdFunc = void (t_stack::*)(void);

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cmdCnt;
    t_stack stack;
    t_cmdFunc funcs[] = {
        NULL,
        &t_stack::push,
        &t_stack::pop,
        &t_stack::size,
        &t_stack::empty,
        &t_stack::top
    };

    std::cin >> cmdCnt;
    while (cmdCnt--)
    {
        int cmd;

        std::cin >> cmd;
        (stack.*funcs[cmd])();
    }
    return (0);
}
