#include <iostream>
#include <cstring>
#include <algorithm>

const int MAX = 51;
const int ALPHA_CNT = 26;
const char COUNTED = 'c';

char target[MAX];
char guess[MAX];
int targetAlpha[ALPHA_CNT];
int guessAlpha[ALPHA_CNT];

int countBlack(void)
{
    int blackCnt = 0;

    for (int i = 0; target[i]; ++i)
    {
        char &targetCh = target[i];
        char &guessCh = guess[i];

        if (targetCh == guessCh)
        {
            targetCh = guessCh = COUNTED;
            ++blackCnt;
        }
        else
        {
            ++targetAlpha[targetCh - 'A'];
            ++guessAlpha[guessCh - 'A'];
        }
    }
    return (blackCnt);
}

int countGrey(void)
{
    int greyCnt = 0;

    for (int i = 0; target[i]; ++i)
    {
        char &targetCh = target[i];
        char &guessCh = guess[i];

        for (int dd = -1; dd <= 1; dd += 2)
        {
            int checkIdx = i + dd;

            if (checkIdx < 0 || target[checkIdx] == COUNTED)
                continue ;

            char &checkCh = target[checkIdx];

            if (checkCh == guessCh)
            {
                --targetAlpha[checkCh - 'A'];
                --guessAlpha[guessCh - 'A'];
                ++greyCnt;
                checkCh = guessCh = COUNTED;
                break ;
            }
        }
    }
    return (greyCnt);
}

int countWhite(void)
{
    int whiteCnt = 0;

    for (int i = 0; i < ALPHA_CNT; ++i)
    {
        whiteCnt += std::min(targetAlpha[i], guessAlpha[i]);
    }
    return (whiteCnt);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    while (std::cin >> target >> guess)
    {

        std::cout << guess << ": "
                  << countBlack() << " black, "
                  << countGrey() << " grey, "
                  << countWhite() << " white"
                  << '\n';
        memset(targetAlpha, 0, sizeof(targetAlpha));
        memset(guessAlpha, 0, sizeof(guessAlpha));
    }
    return (0);
}
