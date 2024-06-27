#include <iostream>
#include <climits>

enum e_space
{
    EMPTY = '0',
    PAPER
};

enum e_ret
{
    BREAK = 0,
    CONTINUE,
    SUCCESS
};

const int SIZE = 10;
const int PAPER_CNT = 5;
const int PAPER_MAX_SIZE = 5;

int ans = INT_MAX;
char map[SIZE][SIZE + 1];
int paper[PAPER_MAX_SIZE + 1];

inline int    coverSpace(int y, int x, int paperSize, char shouldBe)
{
    --paperSize;

    int lastY = y + paperSize;
    int lastX = x + paperSize;

    if (lastY >= SIZE || lastX >= SIZE)
    {
        return (BREAK);
    }

    if (map[lastY][lastX] != shouldBe)
    {
        return (BREAK);
    }

    char changeValue = !(shouldBe - '0') + '0';

    // checking
    for (int dy = 0; dy < paperSize; ++dy)
    {
        char &toCover = map[y + dy][lastX];

        if (toCover != shouldBe)
            return (BREAK);
    }
    for (int dx = 0; dx < paperSize; ++dx)
    {
        char &toCover = map[lastY][x + dx];

        if (toCover != shouldBe)
            return (BREAK);
    }

    // changing
    map[lastY][lastX] = changeValue;
    for (int dy = 0; dy < paperSize; ++dy)
    {
        map[y + dy][lastX] = changeValue;
    }
    for (int dx = 0; dx < paperSize; ++dx)
    {
        map[lastY][x + dx] = changeValue;
    }

    ++paperSize;
    if (paper[paperSize] == 0)
    {
        return (CONTINUE);
    }

    return (SUCCESS);
}

void    backTracking(int remainPaper, int y=0, int x=0, int depth=0)
{
    if (ans <= depth)
    {
        return ;
    }

    if (remainPaper == 0)
    {
        ans = std::min(ans, depth);
        return ;
    }

    while (true)
    {
        if (x == SIZE)
        {
            x = 0;
            ++y;
            if (y == SIZE)
            {
                break ;
            }
        }

        if (map[y][x] == PAPER)
        {
            int size = 1;

            for (; size <= PAPER_MAX_SIZE; ++size)
            {
                int ret = coverSpace(y, x, size, PAPER);

                if (ret == BREAK)
                    break ;
                else if (ret == CONTINUE)
                    continue ;

                --paper[size];
                backTracking(
                    remainPaper - (size * size),
                    y,
                    x + 1,
                    depth + 1
                );
                ++paper[size];
            }

            while (--size)
            {
                coverSpace(y, x, size, EMPTY);
            }

            return ;
        }

        ++x;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int remainPaper = 0;

    for (int i = 1; i <= PAPER_MAX_SIZE; ++i)
    {
        paper[i] = PAPER_CNT;
    }
    for (int y = 0; y < SIZE; ++y)
    {
        for (int x = 0; x < SIZE; ++x)
        {
            std::cin >> map[y][x];
            remainPaper += (map[y][x] == PAPER);
        }
    }

    backTracking(remainPaper);
    std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
    return (0);
}
