#include <iostream>
#include <algorithm>
#include <vector>

struct t_serial
{
    std::string _num;
    int _sum;

    t_serial(std::string &num) : _num(num), _sum(0)
    {
        for (const char &ch : _num)
        {
            if (!std::isdigit(ch))
                continue ;

            _sum += ch - '0';
        }
    }

    inline bool operator<(const t_serial &other) const
    {
        if (this->_num.size() == other._num.size())
        {
            if (this->_sum == other._sum)
                return (this->_num < other._num);

            return (this->_sum < other._sum);
        }

        return (this->_num.size() < other._num.size());
    }
};

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    std::string input;
    std::vector<t_serial> arr;

    std::cin >> size;
    while (size--)
    {
        std::cin >> input;
        arr.push_back(t_serial(input));
    }

    std::sort(arr.begin(), arr.end());
    for (const t_serial &cur : arr)
    {
        std::cout << cur._num << '\n';
    }
    return (0);
}
