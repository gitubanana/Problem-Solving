#include <iostream>
#include <vector>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    while (true)
    {
        int playerCnt, roundTurn;
        if (!(std::cin >> playerCnt >> roundTurn))
            break ;

        int start = 0;
        std::vector<int> turns(playerCnt, 0);

        while (true)
        {
            int allPlus = roundTurn / turns.size();
            int end = (start + roundTurn % turns.size()) % turns.size();

            for (int i = 0; i < turns.size(); ++i)
            {
                turns[i] += allPlus;
            }
            for (int i = start; i != end; i = (i + 1) % turns.size())
            {
                ++turns[i];
            }

            int eraseIdx = (end == 0 ? turns.size() - 1 : end - 1);
            turns.erase(turns.begin() + eraseIdx);

            bool endOfGame = true;
            int cmp = turns[0];
            for (int i = 1; i < turns.size(); ++i)
            {
                if (cmp != turns[i])
                {
                    endOfGame = false;
                    break ;
                }
            }

            if (endOfGame)
                break ;

            if (eraseIdx < end)
                start = eraseIdx;
            else
                start = 0;
        }

        std::cout << turns.size() << ' ' << turns[0] << '\n';
    }
    return (0);
}
