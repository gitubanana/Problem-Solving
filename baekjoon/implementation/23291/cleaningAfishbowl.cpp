#include <iostream>
#include <algorithm>
#include <cstring>
#include <deque>

const int MAX_SIZE = 100;

int startX, size;
std::deque<int> arr[MAX_SIZE];

template <typename Func>
struct Comp
{
    inline bool operator()(std::deque<int> &a, std::deque<int> &b)
    {
        static Func cmp;

        return (cmp(a[0], b[0]));
    }
};

void    plusOneFish(int min)
{
    for (int x = startX; x < size; ++x)
    {
        int &cur = arr[x][0];
        if (cur != min)
            continue ;

        ++cur;
    }
}

void    reverseBowl(void)
{
    int sameHeightSize = 1;

    arr[startX + 1].push_back(arr[startX].back());
    arr[startX++].pop_back();

    while (true)
    {
        int height = arr[startX].size();
        int putEnd = startX + sameHeightSize;
        int putIdx = putEnd + height - 1;
        if (putIdx >= size)
            break ;

        sameHeightSize = putIdx - putEnd + 1;
        while (putIdx >= putEnd)
        {
            for (int x = putEnd - 1; x >= startX; --x)
            {
                arr[putIdx].push_back(arr[x].back());
                arr[x].pop_back();
            }
            --putIdx;
        }

        startX = putEnd;
    }
}

void    controlFish()
{
    static int dd[MAX_SIZE][MAX_SIZE];
    static const int dx[] = {1, 0};
    static const int dy[] = {0, 1};
    static const int dirSize = sizeof(dx) / sizeof(dx[0]);

    memset(dd, 0, sizeof(dd));
    for (int x = startX; x < size; ++x)
    {
        for (int y = 0; y < arr[x].size(); ++y)
        {
            int &curNum = arr[x][y];
            for (int dir = 0; dir < dirSize; ++dir)
            {
                int cmpX = x + dx[dir];
                int cmpY = y + dy[dir];

                if (!(startX <= cmpX && cmpX < size)
                    || !(0 <= cmpY && cmpY < arr[cmpX].size()))
                    continue ;

                int &cmpNum = arr[cmpX][cmpY];
                int plus = std::abs(curNum - cmpNum) / 5;
                if (plus == 0)
                    continue ;

                if (cmpNum > curNum)
                {
                    dd[cmpX][cmpY] -= plus;
                    dd[x][y] += plus;
                }
                else if (cmpNum < curNum)
                {
                    dd[cmpX][cmpY] += plus;
                    dd[x][y] -= plus;
                }
            }
        }
    }

    for (int x = startX; x < size; ++x)
    {
        for (int y = 0; y < arr[x].size(); ++y)
        {
            arr[x][y] += dd[x][y];
        }
    }
}

void    putLinear(void)
{
    int putIdx = 0;

    for (int x = startX; x < size; ++x)
    {
        while (!arr[x].empty())
        {
            if (putIdx == x)
            {
                ++putIdx;
                break ;
            }

            arr[putIdx++].push_back(arr[x].front());
            arr[x].pop_front();
        }
    }

    startX = 0;
}

void    reverseHalf(void)
{
    int putIdx = size - 1;
    int half = (size - startX) / 2;

    while (half--)
    {
        while (!arr[startX].empty())
        {
            arr[putIdx].push_back(arr[startX].back());
            arr[startX].pop_back();
        }

        --putIdx;
        ++startX;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int wantDiff;

    std::cin >> size >> wantDiff;
    for (int x = 0; x < size; ++x)
    {
        int num;

        std::cin >> num;
        arr[x].push_back(num);
    }

    int ans = 0;
    Comp<std::greater<int>> greater;
    while (true)
    {
        int max = (*std::min_element(arr, arr + size, greater))[0];
        int min = (*std::max_element(arr, arr + size, greater))[0];
        if (max - min <= wantDiff)
            break ;

        startX = 0;
        plusOneFish(min);
        reverseBowl();
        controlFish();
        putLinear();
        for (int i = 0; i < 2; ++i)
        {
            reverseHalf();
        }
        controlFish();
        putLinear();

        ++ans;
    }

    std::cout << ans << '\n';
    return (0);
}
