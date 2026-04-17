#include <iostream>
#include <set>
#include <algorithm>

std::set<std::string>   _set;

int    main(void)
{
        int     start, len;
    std::string str;

    std::cin >> str;
        for (start = 0; start < str.size(); ++start)
                for (len = 1; len <= str.size(); ++len)
                        _set.insert(str.substr(start, len));
        std::cout << _set.size() << '\n';
        return (0);
}