#include <iostream>
#include <climits>
#include <vector>

struct t_circle
{
    static const int REMOVED = INT_MAX;

    std::vector<int> nums;
    int start;

    t_circle(void) : start(0) { }

    inline void rotateClockWise(void)
    {
        start = (start == 0 ? nums.size() - 1 : start - 1);
    }

    inline void rotateCounterClockWise(void)
    {
        start = (start + 1) % nums.size();
    }

    inline void push_back(int num)
    {
        nums.push_back(num);
    }

    inline int &operator[](int idx)
    {
        return (nums[(start + idx) % nums.size()]);
    }

    void    print(void)
    {
        int printIdx = start;

        for (int i = 0; i < nums.size(); ++i)
        {
            std::cout << nums[printIdx] << ' ';
            printIdx = (printIdx + 1) % nums.size();
        }
        std::cout << '\n';
    }
};

typedef void (t_circle::*t_func)(void);

const int MAX = 51;

int removeCnt;
double numCnt;
int ySize, xSize;
t_circle circles[MAX];
t_func funcs[] = {
    &t_circle::rotateClockWise,
    &t_circle::rotateCounterClockWise
};

void    dfs(int y, int x, int depth=0)
{
    static const int dy[] = {-1, 1, 0, 0};
    static const int dx[] = {0, 0, -1, 1};
    static const int dirSize = sizeof(dy) / sizeof(dy[0]);

    int curNum = circles[y][x];
    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (nextX == -1)
            nextX = xSize - 1;
        else if (nextX == xSize)
            nextX = 0;

        if (!(1 <= nextY && nextY <= ySize)
            || curNum != circles[nextY][nextX])
            continue ;

        ++removeCnt;
        circles[y][x] = t_circle::REMOVED;
        dfs(nextY, nextX, depth + 1);
    }

    if (removeCnt > 0)
        circles[y][x] = t_circle::REMOVED;
}

inline int getSum(void)
{
    int sum = 0;

    for (int y = 1; y <= ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            int &curNum = circles[y][x];
            if (curNum == t_circle::REMOVED)
                continue ;

            sum += curNum;
        }
    }
    return (sum);
}

void    makeCircleAvg(void)
{
    double avg = getSum() / numCnt;
    for (int y = 1; y <= ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            int &curNum = circles[y][x];
            if (curNum == t_circle::REMOVED)
                continue ;

            if (curNum > avg)
                --curNum;
            else if (curNum < avg)
                ++curNum;
        }
    }
}

// y는 1부터, x는 0부터
int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int num;
    int testCnt;
    int mul, dir, rotateCnt;

    std::cin >> ySize >> xSize >> testCnt;
    numCnt = ySize * xSize;
    for (int y = 1; y <= ySize; ++y)
    {
        t_circle &circle = circles[y];

        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> num;
            circle.push_back(num);
        }
    }
    while (testCnt--)
    {
        std::cin >> mul >> dir >> rotateCnt;

        int idx = mul;
        while (idx <= ySize)
        {
            t_circle &circle = circles[idx];

            for (int i = 0; i < rotateCnt; ++i)
            {
                (circle.*funcs[dir])();
            }
            idx += mul;
        }

        if (numCnt == 0)
            continue ;

        bool runAvg = true;
        for (int y = 1; y <= ySize; ++y)
        {
            for (int x = 0; x < xSize; ++x)
            {
                if (circles[y][x] == t_circle::REMOVED)
                    continue ;

                removeCnt = 0;

                dfs(y, x);
                runAvg &= (removeCnt == 0);
                numCnt -= removeCnt + (removeCnt > 0);
            }
        }

        if (runAvg)
            makeCircleAvg();
    }
    std::cout << getSum() << '\n';
    return (0);
}
