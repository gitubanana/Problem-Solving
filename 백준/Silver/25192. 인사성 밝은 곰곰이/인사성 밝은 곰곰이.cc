#include <iostream>
#include <map>

std::map<std::string, int>  _map;

int main(void)
{
    std::string    str;
    int            line_cnt, ans;

    scanf(" %d", &line_cnt);
    ans = 0;
    while (line_cnt)
    {
        std::cin >> str;
        if (str == "ENTER")
            _map.clear();
        else if (_map[str] == 0)
        {
            _map[str] = 1;
            ++ans;
        }
        --line_cnt;
    }
    printf("%d\n", ans);
    return 0;
}