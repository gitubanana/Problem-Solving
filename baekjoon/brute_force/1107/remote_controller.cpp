#include <iostream>
#include <climits>
#include <algorithm>
#include <cstring>
#include <set>

const char   MIN_BUTTON = '0';
const char   MAX_BUTTON = '9';

typedef std::set<char>  t_set;

int   cur_cnt;
int   min = INT_MAX;
t_set working_button;

bool    is_possible(const std::string &channel)
{
    for (int i = 0; channel[i]; ++i)
    {
        const char &num = channel[i];
        if (working_button.find(num) == working_button.end())
            return (false);
    }
    return (true);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int            size, dest;
    const int      start = 100;
    char           broken_button;

    for (char button = MIN_BUTTON; button <= MAX_BUTTON;
        ++button)
        working_button.insert(button);

    std::cin >> dest >> size;
    while (size)
    {
        std::cin >> broken_button;
        working_button.erase(broken_button);
        --size;
    }

    for (int channel_num = 0; channel_num <= 1000000; ++channel_num)
    {
        const std::string &cur_channel = std::to_string(channel_num);
        if (is_possible(cur_channel))
        {
            min = std::min(min,
                    (int)cur_channel.size() + std::abs(channel_num - dest));
        }
    }
    min = std::min(min, std::abs(start - dest));

    std::cout << min << '\n';

    return (0);
}
