#include <iostream>
#include <algorithm>

enum e_idx
{
    UP = 0,
    DOWN
};

const int MAX_SIZE = 200'000;
const int MAX_HEIGHT = 500'000;
const int HEIGHT_TYPE = 2;

int size, maxHeight;
int sectionCnt[MAX_SIZE];
int heights[HEIGHT_TYPE][MAX_SIZE / 2];

inline int getBreakCnt(int *start, int *end, int height)
{
    return (end - std::upper_bound(start, end, height));
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> maxHeight;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> heights[i & 1][i / 2];
    }

    int halfSize = size / 2;
    for (int i = 0; i < HEIGHT_TYPE; ++i)
    {
        std::sort(heights[i], heights[i] + halfSize);
    }

    for (int h = 0; h < maxHeight; ++h)
    {
        int breakCnt = 
            getBreakCnt(heights[UP], heights[UP] + halfSize, h)
            + getBreakCnt(heights[DOWN], heights[DOWN] + halfSize, maxHeight - h - 1);

        ++sectionCnt[breakCnt];
    }

    for (int cnt = 0; cnt <= size; ++cnt)
    {
        if (sectionCnt[cnt])
        {
            std::cout << cnt << ' ';
            std::cout << sectionCnt[cnt] << '\n';
            break ;
        }
    }
    return (0);
}
