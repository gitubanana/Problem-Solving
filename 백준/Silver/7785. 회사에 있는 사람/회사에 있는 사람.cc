#include <iostream>
#include <set>

typedef std::set<std::string> t_type;

int main()
{
    std::ios::sync_with_stdio(0), std::cin.tie(0);

    int size;
    t_type  list;
    std::string name, state;

    std::cin >> size;
    while (size--)
    {
        std::cin >> name >> state;
        if (state == "enter")
            list.insert(name);
        else
            list.erase(name);
    }
    t_type::reverse_iterator    iter = list.rbegin();

    for (; iter != list.rend(); ++iter)
    {
        std::cout << *iter << '\n';
    }
    return 0;
}

