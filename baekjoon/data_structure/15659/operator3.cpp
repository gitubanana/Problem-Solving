#include <iostream>
#include <algorithm>
#include <climits>
#include <stack>

const int MAX = 11;
const int OPERATOR_CNT = 4;

int size;
int arr[MAX];
char ops[MAX];
int opCnt[OPERATOR_CNT];
int expression[MAX * 2];
int min_ = INT_MAX, max_ = INT_MIN;
std::string opCh ="+-*/";
int opInt[] = {-1, -2, -3, -4};

inline int getOpInt(char op)
{
    return opInt[opCh.find(op)];
}

inline int getPriority(int opInt)
{
    switch (opInt)
    {
    case -1: case -2:
        return (0);
    case -3: case -4:
        return (1);
    }
    return (2);
}

int cal(int a, int opInt, int b)
{
    switch (opInt)
    {
    case -1:
        return (a + b);
    case -2:
        return (a - b);
    case -3:
        return (a * b);
    }
    return (a / b); 
}

int calculate()
{
    int expSize = 0;
    std::stack<int> stack;

    for (int i = 0; i < size; ++i)
    {
        expression[expSize++] = arr[i];

        if (i == size - 1)
            continue ;

        int curOpInt = getOpInt(ops[i]);
        int curPriority = getPriority(curOpInt);
        while (!stack.empty())
        {
            if (getPriority(stack.top()) < curPriority)
                break ;

            expression[expSize++] = stack.top();
            stack.pop();
        }
        stack.push(curOpInt);
    }
    while (!stack.empty())
    {
        expression[expSize++] = stack.top();
        stack.pop();
    }

    for (int i = 0; i < expSize; ++i)
    {
        int &cur = expression[i];

        if (cur > 0)
        {
            stack.push(cur);
        }
        else
        {
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();

            stack.push(cal(b, cur, a));
        }
    }
    return (stack.top());
}

void back_tracking(int depth=0)
{
    if (depth == size - 1)
    {
        int result = calculate();

        min_ = std::min(min_, result);
        max_ = std::max(max_, result);
        return ;
    }

    for (int i = 0; i < OPERATOR_CNT; ++i)
    {
        int &operatorCnt = opCnt[i];

        if (operatorCnt > 0)
        {
            --operatorCnt;
            ops[depth] = opCh[i];
            back_tracking(depth + 1);
            ++operatorCnt;
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
        std::cin >> opCnt[i];

    back_tracking();

    std::cout << max_ << '\n';
    std::cout << min_ << '\n';
    return 0;
}