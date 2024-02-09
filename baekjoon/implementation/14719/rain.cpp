#include <iostream>

const int MAX = 500;

int heights[MAX];
int width, maxHeight;

int measureRain(int curHeight)
{
    int rain = 0;
    int start = 0, end;

    while (start < width)
    {
        while (start < width && heights[start] < curHeight)
            ++start;

        end = start + 1;
        while (end < width && heights[end] < curHeight)
            ++end;
        
        if (end != width)
            rain += end - start - 1;

        start = end;
    }
    return (rain);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> maxHeight >> width;
    for (int i = 0; i < width; ++i)
        std::cin >> heights[i];

    int totalRain = 0;
    for (int curHeight = 1; curHeight <= maxHeight; ++curHeight)
    {
        totalRain += measureRain(curHeight);
    }

    std::cout << totalRain << '\n';
    return (0);
}
