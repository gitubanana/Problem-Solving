#include <iostream>
#include <cstring>

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::string str;
    int         size;

    std::cin >> size >> str;

    int    ans = 1;
    size_t pos = 1;

    while (true)
    {
        pos = str.find('W', pos);
        pos = str.find('E', pos);
        if (pos == std::string::npos)
            break ;
        ++ans;
        
    }

    std::cout << ans << '\n';
    return 0;
}
