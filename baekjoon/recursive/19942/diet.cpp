#include <iostream>
#include <climits>
#include <vector>
#include <cstring>

const int MAX = 15;
const int NUTRIENT_SIZE = 4;
const int PRICE_IDX = 4;

int ingredientSize;
int goal[NUTRIENT_SIZE];
int nutrientArr[MAX][NUTRIENT_SIZE + 1];
int min = INT_MAX;
char chosenArr[MAX];
char chosenAns[MAX + 1];
int cur[NUTRIENT_SIZE + 1];

inline void updateAns(int depth)
{
    for (int i = 0; i < depth; ++i)
    {
        chosenAns[i] = chosenArr[i];
    }
    chosenAns[depth] = 0;
}

inline void checkCur(int depth)
{
    if (min < cur[PRICE_IDX])
        return ;

    for (int i = 0; i < NUTRIENT_SIZE; ++i)
    {
        if (goal[i] > cur[i])
            return ;
    }

    if (min > cur[PRICE_IDX])
    {
        min = cur[PRICE_IDX];
        updateAns(depth);
    }
}

void back_tracking(int start, int depth)
{
    checkCur(depth);

    for (int i = start; i < ingredientSize; ++i)
    {
        chosenArr[depth] = i + 1;

        cur[PRICE_IDX] += nutrientArr[i][PRICE_IDX];
        for (int nutIdx = 0; nutIdx < NUTRIENT_SIZE; ++nutIdx)
        {
            cur[nutIdx] += nutrientArr[i][nutIdx];
        }

        back_tracking(i + 1, depth + 1);

        cur[PRICE_IDX] -= nutrientArr[i][PRICE_IDX];
        for (int nutIdx = 0; nutIdx < NUTRIENT_SIZE; ++nutIdx)
        {
            cur[nutIdx] -= nutrientArr[i][nutIdx];
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ingredientSize;
    for (int goalIdx = 0; goalIdx < NUTRIENT_SIZE; ++goalIdx)
        std::cin >> goal[goalIdx];
    for (int i = 0; i < ingredientSize; ++i)
    {
        for (int inIdx = 0; inIdx <= NUTRIENT_SIZE; ++inIdx)
        {
            std::cin >> nutrientArr[i][inIdx];
        }
    }

    back_tracking(0, 0);

    if (min == INT_MAX)
        std::cout << "-1";
    else
    {
        std::cout << min << '\n';
        for (int i = 0; chosenAns[i]; ++i)
            std::cout << static_cast<int>(chosenAns[i]) << ' ';
    }
    std::cout << '\n';

    return (0);
}
