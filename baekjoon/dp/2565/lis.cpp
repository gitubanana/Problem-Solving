#include <iostream>
#include <algorithm>

struct t_line
{
    int start;
    int end;

    inline bool operator<(const t_line &other) const
    {
        return (this->start < other.start);
    }
};

inline std::istream &operator>>(std::istream &in, t_line &input)
{
    in >> input.start >> input.end;
    return (in);
}

const int MAX = 100;

int size;
int dp[MAX];
t_line arr[MAX];

int getMaxLineCnt(void)
{
    for (int i = 0; i < size; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < i; ++j)
        {
            if (arr[i].end > arr[j].end)
                dp[i] = std::max(dp[i], dp[j] + 1);
        }
    }
    return (*std::max_element(dp, dp + size));
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + size);

    std::cout << size - getMaxLineCnt() << '\n';
    return (0);
}
