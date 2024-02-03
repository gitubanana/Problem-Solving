#include <iostream>

const int MAX = 10000;
const int NUM_CNT = 2;

char ans[MAX + 2];
int ansIdx = MAX;
int inputIdx[NUM_CNT];
std::string input[NUM_CNT];

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < NUM_CNT; ++i)
        std::cin >> input[i];

    int carry = 0;

    for (int i = 0; i < NUM_CNT; ++i)
        inputIdx[i] = input[i].size() - 1;
    while (true)
    {
        int curNum = 0;
        bool isBreak = true;

        for (int i = 0; i < NUM_CNT; ++i)
        {
            if (inputIdx[i] >= 0)
            {
                curNum += input[i][inputIdx[i]--] - '0';
                isBreak &= inputIdx[i] < 0;
            }
        }

        int toAdd = carry + curNum;
        ans[ansIdx--] = toAdd % 10 + '0';
        carry = (toAdd >= 10);

        if (isBreak)
            break ;
	}
    if (carry)
        ans[ansIdx--] = carry + '0';

    std::cout << &ans[ansIdx + 1] << '\n';
	return 0;
}
