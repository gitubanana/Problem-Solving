#include <iostream>
#include <algorithm>

int limit;
bool visited[10];
char signs[9];
std::string arr;
std::string max_ = "0";
std::string min_ = "999999999";

void    back_tracking(int depth)
{
    if (depth == limit)
    {
        max_ = std::max(max_, arr);
        min_ = std::min(min_, arr);
        return ;
    }

    char start, end;

    if (signs[depth - 1] == '<')
    {
        start = arr[depth - 1] + 1;
        end = '9';
    }
    else
    {
        start = '0';
        end = arr[depth - 1];
    }

    for (char n = start; n <= end; ++n)
    {
        int idx = n - '0';
        if (!visited[idx])
        {
            arr[depth] = n;
            visited[idx] = true;
            back_tracking(depth + 1);
            visited[idx] = false;
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> limit;

    for (int i = 0; i < limit; ++i)
        std::cin >> signs[i];

    ++limit;
    arr.resize(limit);
    for (char n = '0'; n <= '9'; ++n)
    {
        arr[0] = n;

        int idx = n - '0';
        visited[idx] = true;
        back_tracking(1);
        visited[idx] = false;
    }

    std::cout << max_ << '\n';
    std::cout << min_ << '\n';
    return (0);
}
