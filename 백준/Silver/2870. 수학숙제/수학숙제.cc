#include <iostream>
#include <map>

struct t_num
{
    std::string num;

    inline bool operator<(const t_num &other) const
    {
        size_t this_size = this->num.size();
        size_t other_size = other.num.size();

        if (this_size == other_size)
            return this->num < other.num;
        return this_size < other_size;
    }
};

typedef std::map<t_num, int> t_map;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    int start, end;
    std::string str;
    t_map map_;

    std::cin >> testCnt;
    while (testCnt--)
    {
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

            ++map_[{str.substr(start, end - start)}];
        }
    }

    for (const std::pair<t_num, int> &pair : map_)
    {
        for (int i = 0; i < pair.second; ++i)
            std::cout << pair.first.num << '\n';
    }
    return (0);
}
