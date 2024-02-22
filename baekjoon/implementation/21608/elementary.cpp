#include <iostream>
#include <unordered_set>
#include <vector>
#include <cmath>
#include <algorithm>

struct t_student
{
    const static int LIKE_CNT = 4;

    std::unordered_set<int> likes;
};

struct t_standard
{
    int likeCnt;
    int emptyCnt;
    int y, x;

    inline bool operator<(const t_standard &other) const
    {
        if (likeCnt != other.likeCnt)
            return (likeCnt < other.likeCnt);

        if (emptyCnt != other.emptyCnt)
            return (emptyCnt < other.emptyCnt);

        if (y != other.y)
            return (y > other.y);

        return (x > other.x);
    }
};

const int MAX = 20;

int size;
int map[MAX][MAX];
int dy[] = {0, 0, 1, -1};
int dx[] = {1, -1, 0, 0};
int studentCnt;
t_student arr[MAX * MAX + 1];

inline std::istream &operator>>(std::istream &in, t_student &input)
{
    int like;
    for (int i = 0; i < t_student::LIKE_CNT; ++i)
    {
        in >> like;
        input.likes.insert(like);
    }
    return (in);
}

inline int getLikeCnt(t_student &cur, int y, int x, int &emptyCnt)
{
    int ret = 0;

    for (int i = 0; i < 4; ++i)
    {
        int nextY = y + dy[i];
        int nextX = x + dx[i];

        if (!(0 <= nextY && nextY < size)
            || !(0 <= nextX && nextX < size))
            continue ;

        int &nextSpace = map[nextY][nextX];
        if (cur.likes.find(nextSpace) != cur.likes.end())
        {
            ++ret;
        }
        else if (nextSpace == 0)
            ++emptyCnt;
    }
    return (ret);
}

inline int getSatisfaction(void)
{
    int tmp = 0;
    int ret = 0;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            t_student &cur = arr[map[y][x]];
            int likeCnt = getLikeCnt(cur, y, x, tmp);

            if (likeCnt > 0)
                ret += pow(10, likeCnt - 1);
        }
    }
    return (ret);
}

void    takeAsit(int stuNum, t_student &student)
{
    // cnt로 정렬, empty, y, x
    std::vector<t_standard> toSit;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            if (map[y][x] != 0)
                continue ;

            int emptyCnt = 0;
            int likeCnt = getLikeCnt(arr[stuNum], y, x, emptyCnt);

            toSit.push_back({likeCnt, emptyCnt, y, x});
        }
    }
    t_standard &realSit = *std::max_element(toSit.begin(), toSit.end());
    map[realSit.y][realSit.x] = stuNum;
}

void    printMap(void)
{
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
            std::cout << map[y][x] << ' ';
        std::cout << '\n';
    }
    std::cout << "=================" << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;

    studentCnt = size * size;
    for (int i = 0; i < studentCnt; ++i)
    {
        int stuNum;

        std::cin >> stuNum >> arr[stuNum];
        takeAsit(stuNum, arr[stuNum]);
    }

    std::cout << getSatisfaction() << '\n';
    return (0);
}
