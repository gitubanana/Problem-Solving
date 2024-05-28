#include <iostream>

const int MAX_SIZE = 100;

int berry[MAX_SIZE];
int grape[MAX_SIZE];
int robotMoveCnt[MAX_SIZE];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    int plusGrape, plusBerry;
    int *ptr[] = {berry, grape};

    std::cin >> size >> plusBerry >> plusGrape;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cin >> ptr[i][j];
        }
    }

    for (int i = 0; i < size; ++i)
    {
        int &curBerry = berry[i];
        int &curGrape = grape[i];
        int &curMoveCnt = robotMoveCnt[i];

        while (curBerry != curGrape
                && curMoveCnt < 10000)
        {
            curBerry += plusBerry;
            curGrape += plusGrape;
            ++curMoveCnt;
        }

        if (curBerry != curGrape)
        {
            std::cout << "NO" << '\n';
            return (0);
        }
    }

    std::cout << "YES" << '\n';
    for (int i = 0; i < size; ++i)
    {
        std::cout << robotMoveCnt[i] << ' ';
    }
    std::cout << '\n';
    return (0);
}
