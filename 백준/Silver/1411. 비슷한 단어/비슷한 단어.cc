#include <iostream>
#include <vector>
#include <cstring>

typedef std::vector<std::string> t_vec;

char    origin[26];
int     new_ch[26];

bool    is_shawm_like(std::string from, std::string &to)
{
    int i = 0;

    memset(origin, 0, sizeof(origin));
    memset(new_ch, 0, sizeof(new_ch));
    for (; from[i]; ++i)
    {
        int to_idx = to[i] - 'a';
        int from_idx = from[i] - 'a';

        if (origin[from_idx] == 0 && new_ch[to_idx]== 0)
            origin[from_idx] = to[i], new_ch[to_idx] = from[i];

        from[i] = origin[from_idx];
        if (from[i] != to[i])
            return (false);
    }
    return (true);
}

void    print_ans(t_vec &_vec)
{
    t_vec::iterator origin = _vec.begin(), cmp;
    t_vec::iterator end = _vec.end();
    int shawm_cnt = 0;

    for (; origin != end - 1; ++origin)
        for (cmp = origin + 1; cmp != end; ++cmp)
            if (is_shawm_like(*origin, *cmp))
                ++shawm_cnt;
    std::cout << shawm_cnt;
}

int main(void)
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int     size;
    t_vec   _vec;
    std::string str;

    std::cin >> size;
    while (size)
    {
        std::cin >> str;
        _vec.push_back(str);
        --size;
    }

    print_ans(_vec);
    return 0;
}
