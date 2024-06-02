#include <iostream>
#include <set>

struct t_lid
{
    std::string str;
    int start;

    inline void rotate(void)
    {
        start = (start + 1) % str.size();
    }

    inline char &operator[](const int &idx)
    {
        return (str[(start + idx) % str.size()]);
    }
};

inline std::istream &operator>>(std::istream &in, t_lid &input)
{
    in >> input.str;
    input.start = 0;
    return (in);
}

int getFindNum(std::set<int, std::greater<int> > &_set, int findCnt)
{
    int curCnt = 0;

    for (const int &cur : _set)
    {
        ++curCnt;
        if (curCnt == findCnt)
            return (cur);
    }
    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    const std::string base16 = "0123456789ABCDEF";

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        t_lid pw;
        int strSize, findCnt;
        std::set<int, std::greater<int> > _set;

        std::cin >> strSize >> findCnt >> pw;

        int numSize = strSize / 4;
        for (int rCnt = 1; rCnt < strSize; ++rCnt)
        {
            for (int start = 0; start < strSize; start += numSize)
            {
                int num = 0;
                for (int i = 0; i < numSize; ++i)
                {
                    num = num * 16 + base16.find(pw[start + i]);
                }

                _set.insert(num);
            }
            pw.rotate();
        }

        std::cout << "#" << t << ' ' << getFindNum(_set, findCnt) << '\n';
    }
    return (0);
}
