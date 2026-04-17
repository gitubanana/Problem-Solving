#include <iostream>
#include <algorithm>
#include <deque>

struct t_paper
{
    int priority;
    int turn;
};

bool    can_print(std::deque<t_paper> &printer, t_paper &to_be_printed)
{
    std::deque<t_paper>::iterator   iter;

    iter = printer.begin();
    for (; iter != printer.end(); ++iter)
        if (iter->priority > to_be_printed.priority)
            return (false);
    return (true);
}

void    print_turn(std::deque<t_paper> &printer, int to_find)
{
    int     turn;
    t_paper first;

    turn = 1;
    while (1)
    {
        first = printer.front();
        printer.pop_front();
        if (!can_print(printer, first))
            printer.push_back(first);
        else if (first.turn == to_find)
        {
            printf("%d\n", turn);
            return ;
        }
        else
            ++turn;
    }
}

int main(void)
{
    int i, size;
    int test_cnt;
    int to_find, priority;

    scanf(" %d", &test_cnt);
    while (test_cnt)
    {
        std::deque<t_paper> printer;

        scanf(" %d %d", &size, &to_find);
        for (i = 0; i < size; ++i)
        {
            scanf(" %d", &priority);
            printer.push_back({priority, i});
        }
        print_turn(printer, to_find);
        --test_cnt;
    }
    return (0);
}
