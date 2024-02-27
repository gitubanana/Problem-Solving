#include <iostream>
#include <string>

const int MAX = 4000;

const int cnt[] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
int idx;
int nums[2][MAX];

void    change(int curSize)
{
    int nextIdx = (idx + 1) % 2;

    for (int i = 0; i < curSize; ++i)
    {
        nums[nextIdx][i] = (nums[idx][i] + nums[idx][i + 1]) % 10;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::string str;

    std::cin >> str;
    for (int i = 0; i < str.size(); ++i)
    {
        nums[idx][i * 2] = cnt[str[i] - 'A'];
    }

    std::cin >> str;
    for (int i = 0; i < str.size(); ++i)
    {
        nums[idx][i * 2 + 1] = cnt[str[i] - 'A'];
    }

    for (int curSize = str.size() * 2 - 1; curSize >= 2; --curSize)
    {
        change(curSize);
        idx = (idx + 1) % 2;
    }

    std::cout << nums[idx][0] << nums[idx][1] << '\n';
    return (0);
}
