#include <iostream>
#include <deque>

void    fill_char(std::string &be_filled,
                    size_t size, const char &ch)
{
    while (be_filled.length() < size)
        be_filled.insert(be_filled.begin(), ch);
}

void    plus_large_num(std::string &result,
                        std::string &a, std::string &b)
{
    static const char   &zero_char = '0';
    static const char   &two_zero = zero_char * 2;

    fill_char(a, b.length(), '0');
    fill_char(b, a.length(), '0');

    char    next = 0;
    for (int i = a.length() - 1; i >= 0; --i)
    {
        char    sum = a[i] + b[i] - two_zero + next;
        char    cur = sum % 2 + zero_char;

        next = sum / 2;
        result.insert(result.begin(), cur);
    }
    if (next > 0)
        result.insert(result.begin(), next + zero_char);
}
int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::string a, b, result;

    std::cin >> a >> b;
    plus_large_num(result, a, b);
    int i = 0;
    for (; result[i]; ++i)
    {
        if (result[i] == '1')
            break ;
    }
    if (result[i] == '\0')
        --i;
    std::cout << result.c_str() + i << '\n';
    return (0);
}
