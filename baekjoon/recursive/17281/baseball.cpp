#include <iostream>

enum e_stat
{
    OUT = 0,
    ONE,
    TWO,
    THREE,
    HOMERUN
};

const int SIZE = 9;
const int MAX_INNING = 50;

int inningCnt, maxScore;
int order[SIZE];
bool visited[SIZE];
int stat[MAX_INNING][SIZE];

int simulation(void)
{
    int idx = 0;
    int score = 0;

    for (int inning = 0; inning < inningCnt; ++inning)
    {
        int out = 0;
        bool onBase[3] = {false, false, false};

        while (out < 3)
        {
            int &hitter = order[idx];
            int &curStat = stat[inning][hitter];

            switch (curStat)
            {
            case OUT:
                ++out;
                break;
            case HOMERUN:
                ++score;
                for (int i = 0; i < 3; ++i)
                {
                    score += onBase[i];
                    onBase[i] = false;
                }
                break;
            default:
                for (int i = 2; i >= 0; --i)
                {
                    if (!onBase[i])
                        continue ;

                    int next = i + curStat;

                    onBase[i] = false;
                    if (next >= 3)
                    {
                        ++score;
                    }
                    else
                    {
                        onBase[next] = true;
                    }
                }
                onBase[curStat - 1] = true;
                break;
            }

            idx = (idx + 1) % SIZE;
        }
    }
    return (score);
}

void    backTracking(int depth=0)
{
    if (depth == SIZE)
    {
        int score = simulation();
        maxScore = std::max(maxScore, score);
        return ;
    }

    int plus = (depth == 2);
    for (int p = 1; p < SIZE; ++p)
    {
        if (visited[p])
            continue ;

        order[depth] = p;
        visited[p] = true;

        backTracking(depth + 1 + plus);

        visited[p] = false;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> inningCnt;
    for (int inning = 0; inning < inningCnt; ++inning)
    {
        for (int p = 0; p < SIZE; ++p)
        {
            std::cin >> stat[inning][p];
        }
    }

    backTracking();

    std::cout << maxScore << '\n';
    return (0);
}
