#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

typedef std::map<std::string, int> t_map;

int main(void)
{
    int i, test_cnt;
    int num_of_clothes;
    char    key[21], value[21];
    t_map::iterator iter;

        scanf(" %d", &test_cnt);
    while (test_cnt)
    {
        t_map   _map;

        scanf(" %d", &num_of_clothes);
        for (i = 0; i < num_of_clothes; ++i)
        {
            scanf(" %s %s", value, key);
            iter = _map.find(key);
            if (iter == _map.end())
                _map.insert({key, 1});
            else
                ++iter->second;
        }
        int    ans = 1;
        for (t_map::iterator iter = _map.begin(); iter != _map.end(); ++iter)
            ans *= (iter->second + 1);
        printf("%d\n", ans - 1);
        --test_cnt;
    }
    return (0);
}