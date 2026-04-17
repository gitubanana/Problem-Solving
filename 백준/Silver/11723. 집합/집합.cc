#include <iostream>
#include <climits>

struct Set
{
    int set;
    
    Set(void) : set(0) { }

    inline void    add(int x)
    {
        set |= (1 << x);
    }

    inline void    remove_(int x)
    {
        set &= ~(1 << x);
    }
    
    inline void    check(int x) const
    {
        std::cout << static_cast<bool>(set & (1 << x)) << '\n';
    }

    inline void    toggle(int x)
    {
        if (set & (1 << x))
            remove_(x);
        else
            add(x);
    }

    inline void    all(void) { set = ~0; }
    
    inline void    empty(void) { set = 0; }
};

int main()
{
    std::ios::sync_with_stdio(0), std::cin.tie(0);
    
    Set set;
    int cnt, x;
    std::string cmd;

    std::cin >> cnt;
    while (cnt--)
    {
        std::cin >> cmd;
        if (cmd == "add")
            std::cin >> x, set.add(x);
        else if (cmd == "remove")
            std::cin >> x, set.remove_(x);
        else if (cmd == "check")
            std::cin >> x, set.check(x);
        else if (cmd == "toggle")
            std::cin >> x, set.toggle(x);
        else if (cmd == "all")
            set.all();
        else
            set.empty();
    }
    return 0;
}
