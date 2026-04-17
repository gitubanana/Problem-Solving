#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

const int       CNT = 8;
const std::string       ABB_ZERO = "z";


void strtrim(std::string &str, const std::string &charset)
{
        size_t start = str.find_first_not_of(charset);
        size_t end = str.find_last_not_of(charset) + 1;

        str = str.substr(start, end - start);
}

int     main(void)
{
        int     i;
        int     zero_cnt;
        bool    is_zero;
        std::string     str;
        std::vector<std::string>        ipv6;

        is_zero = false;
        while (std::getline(std::cin, str, ':'))
        {
                if (str == "")
                {
                        if (!is_zero)
                        {
                                ipv6.push_back(ABB_ZERO);
                                is_zero = true;
                        }
                }
                else
                        ipv6.push_back(str);
        }
        try
        {
                strtrim(ipv6.back(), "\n\r\t \v");
        }
        catch (std::exception &e)
        {
                ipv6.pop_back();
        }

        for (i = 0; i < ipv6.size(); ++i)
        {
                if (ipv6[i] == ABB_ZERO)
                {
                        zero_cnt = CNT - i - (ipv6.size() - i - 1);
                        while (zero_cnt > 0)
                        {
                                std::cout << "0000";
                                if (zero_cnt > 1)
                                        std::cout << ':';
                                --zero_cnt;
                        }
                }
                else
                        std::cout << std::setw(4) << std::setfill('0') << ipv6[i];
                if (i != ipv6.size() - 1)
                        std::cout << ':';
        }
        std::cout << '\n';
        return (0);
}