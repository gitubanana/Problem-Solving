#include <iostream>
#include <algorithm>

struct t_puddle
{
    int start;
    int end;

    inline bool operator<(const t_puddle &other) const
    {
        return (this->start < other.start);
    }
};

inline std::istream &operator>>(std::istream &in, t_puddle &input)
{
    in >> input.start >> input.end;
    return (in);
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int start, end;
    int puddleCnt, plankLength;

    std::cin >> puddleCnt >> plankLength;
    t_puddle *arr = new t_puddle[puddleCnt];
    for (int i = 0; i < puddleCnt; ++i)
        std::cin >> arr[i];

    std::sort(arr, arr + puddleCnt);

    int ans = 0;
    int lastPlankPos = 0;
    for (int i = 0; i < puddleCnt; ++i)
    {
        t_puddle &cur = arr[i];

        if (cur.start <= lastPlankPos && lastPlankPos < cur.end)
        {
            int fillLength = cur.end - lastPlankPos;
            int addCnt = fillLength / plankLength + (fillLength % plankLength != 0);

            ans += addCnt;
            lastPlankPos += addCnt * plankLength;
        }
        else if (lastPlankPos < cur.end)
        {
            int fillLength = cur.end - cur.start;
            int addCnt = fillLength / plankLength + (fillLength % plankLength != 0);

            ans += addCnt;
            lastPlankPos = cur.start + addCnt * plankLength;
        }
    }

    std::cout << ans << '\n';
    delete[] arr;
    return 0;
}
