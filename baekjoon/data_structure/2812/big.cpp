#include <iostream>

const int MAX_SIZE = 500000;

int top;
char stack[MAX_SIZE];
char num[MAX_SIZE + 1];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int numSize, removeCnt;

    std::cin >> numSize >> removeCnt;
    std::cin >> num;

    int shouldSize = numSize - removeCnt;

    stack[top++] = num[0];
    for (int i = 1; num[i]; ++i)
    {
        const char &cur = num[i];
        int remainCnt = numSize - i;

        while (top > 0 &&
                top + remainCnt > shouldSize)
        {
            char &cmp = stack[top - 1];
            if (cmp >= cur)
                break ;

            cmp = cur;
            --top;
        }

        if (top < shouldSize)
        {
            stack[top++] = cur;
        }
    }

    stack[shouldSize] = 0;
    std::cout << stack << '\n';
    return (0);
}
