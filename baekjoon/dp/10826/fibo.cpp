#include <iostream>
#include <deque>

typedef std::deque<char>    t_deq;

void    fill_char(t_deq &be_filled,
                    size_t size, const char &ch)
{
    while (be_filled.size() < size)
        be_filled.push_front(ch);
}

void    plus_large_num(t_deq &result,
                        t_deq &a, t_deq &b)
{
    static const char   &zero_char = '0';
    static const char   &two_zero = zero_char * 2;

    fill_char(a, b.size(), '0');
    fill_char(b, a.size(), '0');

    char    next = 0;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        char    sum = a[i] + b[i] - two_zero + next;
        char    cur = sum % 10 + zero_char;

        next = sum / 10;
        result.push_front(cur);
    }
    if (next > 0)
        result.push_front(next + zero_char);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int n;
    t_deq *dp;

    std::cin >> n;

    if (n <= 1)
        return !(std::cout << n << '\n');

    dp = new t_deq[n + 1];
    dp[0].push_back('0'), dp[1].push_back('1');
    for (int i = 2; i <= n; ++i)
    {
        plus_large_num(dp[i], dp[i - 1], dp[i - 2]);
    }

    const t_deq &to_print = dp[n];
    for (size_t i = 0; i < to_print.size(); ++i)
        std::cout << to_print[i];
    std::cout << '\n';

    delete[] dp;
    return (0);
}
