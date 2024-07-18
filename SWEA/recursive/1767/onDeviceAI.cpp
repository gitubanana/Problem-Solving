#include <iostream>
#include <vector>
#include <climits>

struct t_pos
{
    int y, x;
};

const int MAX_SIZE = 12;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
int maxCore, minLine;
bool map[MAX_SIZE][MAX_SIZE];
std::vector<t_pos> cores;

inline bool isBound(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < size)
            && (0 <= pos.x && pos.x < size));
}

void    makeLine(std::vector<t_pos> &arr, bool value)
{
    for (const t_pos &pos : arr)
    {
        map[pos.y][pos.x] = value;
    }
}

void    findMinLine(int curIdx=0, int lineSize=0, int coreCnt=0)
{
    if (curIdx == cores.size())
    {
        if (maxCore < coreCnt)
        {
            maxCore = coreCnt;
            minLine = lineSize;
        }
        else if (maxCore == coreCnt)
        {
            minLine = std::min(minLine, lineSize);
        }

        return ;
    }

    int canMakeCnt = coreCnt + (cores.size() - curIdx);
    if (maxCore > canMakeCnt)
    {
        return ;
    }
    else if (maxCore == canMakeCnt && minLine <= lineSize)
    {
        return ;
    }

    std::vector<t_pos> linePos;
    const t_pos &cur = cores[curIdx];

    findMinLine(curIdx + 1, lineSize, coreCnt);
    linePos.reserve(size);
    for (int dir = 0; dir < dirSize; ++dir)
    {
        bool canMakeLine = true;
        t_pos next = {
            cur.y + dy[dir],
            cur.x + dx[dir]
        };

        linePos.clear();
        do
        {
            if (map[next.y][next.x])
            {
                canMakeLine = false;
                break ;
            }

            linePos.push_back(next);
            next.y += dy[dir];
            next.x += dx[dir];
        } while (isBound(next));

        if (!canMakeLine)
            continue ;

        makeLine(linePos, true);
        findMinLine(curIdx + 1, lineSize + linePos.size(), coreCnt + 1);
        makeLine(linePos, false);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    cores.reserve(MAX_SIZE);
    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        cores.clear();
        std::cin >> size;
        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
            {
                bool &space = map[y][x];

                std::cin >> space;
                if (y == 0 || y == size - 1 || x == 0 || x == size - 1)
                    continue ;

                if (space)
                    cores.push_back({y, x});
            }
        }

        maxCore = 0;
        minLine = INT_MAX;
        findMinLine();
        std::cout << '#' << t << ' ' << minLine << '\n';
    }
    return (0);
}
