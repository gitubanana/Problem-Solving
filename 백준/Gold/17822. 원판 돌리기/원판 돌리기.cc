#include <iostream>
#include <vector>
#include <queue>

struct t_circle
{
    int start;
    std::vector<int> arr;

    t_circle(void) : start(0) { }

    inline void fill(int size, int num=0)
    {
        arr.resize(size, num);
    }

    inline void push(int num)
    {
        arr.push_back(num);
    }

    inline void rotateCounterClockWise(int move)
    {
        start = (start + move) % arr.size();
    }

    inline int &operator[](int idx)
    {
        return (arr[(start + idx) % arr.size()]);
    }
};

using t_func = void (t_circle::*)(int);

const int MAX_SIZE = 50;
const int REMOVED = 0;

int ySize, xSize;
int maxDepth;
t_circle map[MAX_SIZE + 2];

int getSum(void)
{
    int sum = 0;

    for (int y = 1; y <= ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            sum += map[y][x];
        }
    }
    return (sum);
}

void    removeSameAdjacent(void)
{
    static std::queue<std::pair<int, int>> q;

    double numCnt = 0;

    for (int y = 1; y <= ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            int &num = map[y][x];
            if (!num)
                continue ;

            ++numCnt;
            if (num == map[y + 1][x]
                || num == map[y - 1][x]
                || num == map[y][(x + 1) % xSize]
                || num == map[y][(x + xSize - 1) % xSize])
            {
                q.push({y, x});
            }
        }
    }

    if (q.size())
    {
        while (q.size())
        {
            auto [y, x] = q.front();
            q.pop();

            map[y][x] = REMOVED;
        }
    }
    else if (numCnt != 0)
    {
        double avg = getSum() / numCnt;
        for (int y = 1; y <= ySize; ++y)
        {
            for (int x = 0; x < xSize; ++x)
            {
                int &num = map[y][x];
                if (!num)
                    continue ;

                if (num > avg)
                    --num;
                else if (num < avg)
                    ++num;
            }
        }
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cmdCnt;

    std::cin >> ySize >> xSize >> cmdCnt;
    map[0].fill(xSize);
    map[ySize + 1].fill(xSize);
    for (int y = 1; y <= ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            int num;

            std::cin >> num;
            map[y].push(num);
        }
    }

    while (cmdCnt--)
    {
        int mul, dir, move;

        std::cin >> mul >> dir >> move;
        if (dir == 0)
            move = xSize - move;

        for (int y = mul; y <= ySize; y += mul)
        {
            t_circle &toMove = map[y];

            toMove.rotateCounterClockWise(move);
        }

        removeSameAdjacent();
    }

    std::cout << getSum() << '\n';
    return 0;
}