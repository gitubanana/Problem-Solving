#include <iostream>
#include <algorithm>
#include <cstring>

const int MAX = 100000;
const int ALPHABET_CNT = 26;

char toPrint[MAX + 1];
int  alphabetCnt[ALPHABET_CNT];
int  limit;

void back_tracking(int depth)
{
    if (depth == limit)
    {
        toPrint[depth] = '\0';
        std::cout << toPrint << '\n';
        return ;
    }

    for (int i = 0; i < ALPHABET_CNT; ++i)
    {
        if (alphabetCnt[i] > 0)
        {
            toPrint[depth] = 'a' + i;
            --alphabetCnt[i];
            back_tracking(depth + 1);
            ++alphabetCnt[i];
        }
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    std::string input;

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> input;
        for (char &ch : input)
            ++alphabetCnt[ch - 'a'];

        limit = input.size();
        back_tracking(0);

        if (testCnt >= 1)
            memset(alphabetCnt, 0, sizeof(alphabetCnt));
    }
    return 0;
}
