#include <iostream>
#include <climits>
#include <algorithm>

const int MAX = 11;
const int OPERATOR_CNT = 4;

int size;
int arr[MAX];
int operators[OPERATOR_CNT];
int min_ = INT_MAX, max_ = INT_MIN;

int calculate(int a, int operatorIdx, int b)
{
    switch (operatorIdx) {
        case 0:
            return a + b;
        case 1:
            return a - b;
        case 2:
            return a * b;
    }
    return a / b;
}

void back_tracking(int cur, int depth)
{
    if (depth == size)
    {
        min_ = std::min(min_, cur);
        max_ = std::max(max_, cur);
        return ;
    }

    for (int i = 0; i < OPERATOR_CNT; ++i)
    {
        if (operators[i] > 0)
        {
            --operators[i];
            back_tracking(
                calculate(cur, i, arr[depth]),
                depth + 1
            );
            ++operators[i];
        }
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int i = 0; i < size; ++i)
        std::cin >> arr[i];
    for (int i = 0; i < OPERATOR_CNT; ++i)
        std::cin >> operators[i];

    back_tracking(arr[0], 1);

    std::cout << max_ << '\n';
    std::cout << min_ << '\n';
    return 0;
}