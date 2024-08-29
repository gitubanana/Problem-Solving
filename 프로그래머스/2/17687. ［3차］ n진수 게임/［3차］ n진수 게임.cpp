#include <string>
#include <iostream>
#include <vector>

using namespace std;

void    numIntoStr(int num, std::string &numStr, int base)
{
    static const std::string &nums = "0123456789ABCDEF";

    if (num == 0)
    {
        numStr += '0';
        return ;
    }
    
    while (num)
    {
        numStr += nums[num % base];
        num /= base;
    }
}

string solution(int base, int t, int m, int p) {
    string answer = "";
    std::string numStr;

    int num = 0;
    while (t)
    {
        numStr.clear();
        numIntoStr(num, numStr, base);

        if (numStr.size() >= p)
        {
            while (numStr.size() >= p)
            {
                answer += numStr[numStr.size() - p];
                p += m;
                --t;
                if (t == 0)
                    break ;
            }

            p -= numStr.size();
        }
        else
        {
            p -= numStr.size();
        }

        ++num;
    }
    return answer;
}