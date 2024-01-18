#include <iostream>
#include <map>
#include <cstring>

struct t_num
{
    char *start;
    char *end;

    inline bool operator<(const t_num &other) const
    {
        size_t this_size = end - start;
        size_t other_size = other.end - other.start;

        if (this_size == other_size)
            return strcmp(start, other.start) < 0;
        return this_size < other_size;
    }
};

typedef std::map<t_num, int> t_map;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    int start, end;
    t_map map_;
    std::string *strs;

    std::cin >> testCnt;
    strs = new std::string[testCnt];

    for (int i = 0; i < testCnt; ++i)
    {
        std::string &str = strs[i];

        std::cin >> str;
        int strSize = str.size();
        for (int i = 0; i < strSize; ++i)
        {
            start = i;
            while (std::isdigit(str[i]))
                ++i;
            end = i;

            if (start == end)
                continue ;

            if (str[start] == '0')
            {
                while (str[start] == '0')
                    ++start;
                if (!std::isdigit(str[start]))
                    --start;
            }

            str[end] = '\0';
            ++map_[{&str[start], &str[end]}];
        }
    }

    for (const std::pair<t_num, int> &pair : map_)
    {
        for (int i = 0; i < pair.second; ++i)
            std::cout << pair.first.start << '\n';
    }

    delete[] strs;
    return (0);
}
