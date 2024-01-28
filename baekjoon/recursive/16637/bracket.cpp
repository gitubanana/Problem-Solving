#include <iostream>
#include <algorithm>
#include <climits>

const int MAX = 19;

int size, maxValue = INT_MIN;
char expression[MAX + 1];

inline int calculate(int op1, char operatorCh, int op2)
{
    switch (operatorCh) {
        case '+':
            return op1 + op2;
        case '-':
            return op1 - op2;
    }
    return op1 * op2;
}

void findMaxValue(int operatorIdx, int curValue)
{
    if (operatorIdx >= size)
    {
        maxValue = std::max(maxValue, curValue);
        return ;
    }

    char &operatorCh = expression[operatorIdx];

    findMaxValue(
        operatorIdx + 2,
        calculate(curValue, operatorCh, expression[operatorIdx + 1] - '0')
    );

    if (operatorIdx + 3 < size)
    {
        int bracketNum = calculate(
            expression[operatorIdx + 1] - '0',
            expression[operatorIdx + 2],
            expression[operatorIdx + 3] - '0'
        );
    
        findMaxValue(
            operatorIdx + 4,
            calculate(curValue, expression[operatorIdx], bracketNum)
        );
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);


    std::cin >> size >> expression;
    findMaxValue(1, expression[0] - '0');
    std::cout << maxValue << '\n';
    return 0;
}
