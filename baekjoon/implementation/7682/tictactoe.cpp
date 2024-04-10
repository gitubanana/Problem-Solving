#include <iostream>

const int MAX = 3;

char map[MAX][MAX];

inline bool getInput(void)
{
    for (int y = 0; y < MAX; ++y)
    {
        for (int x = 0; x < MAX; ++x)
        {
            if (!(std::cin >> map[y][x]))
                return (false);
        }
    }
    return (true);
}

int cntCharInMap(char ch)
{
    int cnt = 0;

    for (int y = 0; y < MAX; ++y)
    {
        for (int x = 0; x < MAX; ++x)
        {
            cnt += (map[y][x] == ch);
        }
    }
    return (cnt);
}

bool madeLineInMap(char ch)
{
    for (int y = 0, x; y < MAX; ++y)
    {
        for (x = 0; x < MAX; ++x)
        {
            if (map[y][x] != ch)
                break ;
        }
        if (x == MAX)
            return (true);
    }

    for (int x = 0, y; x < MAX; ++x)
    {
        for (y = 0; y < MAX; ++y)
        {
            if (map[y][x] != ch)
                break ;
        }
        if (y == MAX)
            return (true);
    }

    int pos;
    for (pos = 0; pos < MAX; ++pos)
    {
        if (map[pos][pos] != ch)
            break ;
    }
    if (pos == MAX)
        return (true);

    for (pos = 0; pos < MAX; ++pos)
    {
        if (map[pos][MAX - pos - 1] != ch)
            break ;
    }
    if (pos == MAX)
        return (true);

    return (false);
}

bool isValidMap(void)
{
    const int oCnt = cntCharInMap('O');
    const int xCnt = cntCharInMap('X');
    const bool oWon = madeLineInMap('O');
    const bool xWon = madeLineInMap('X');

    if (!oWon && xWon)
    {
        return (oCnt + 1 == xCnt);
    }
    else if (oWon && !xWon)
    {
        return (oCnt == xCnt);
    }
    else if (!oWon && !xWon)
    {
        return (oCnt == 4 && xCnt == 5);
    }

    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    const char *msg[] = {"invalid", "valid"};

    while (getInput())
    {
        std::cout << msg[isValidMap()] << '\n';
    }
    return (0);
}
