#include <iostream>
#include <algorithm>
#include <vector>

enum e_space
{
    EMPTY = '0',
    REVERSE,
    WALL
};

struct t_pos
{
    int y, x;
    int dir;
};

using t_vec = std::vector<int>;

const int MAX_SIZE = 12;
const int MAX_HORSE = 10;
const int MAX_TURN = 1000;
const int HEIGHT_LIMIT = 4;
const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
size_t maxHeight;
char map[MAX_SIZE][MAX_SIZE];
t_vec vec[MAX_SIZE][MAX_SIZE];
t_pos horses[MAX_HORSE];

void    moveEmpty(int num, const t_pos &cur, const t_pos &next)
{
    t_vec &curVec = vec[cur.y][cur.x];
    t_vec &nextVec = vec[next.y][next.x];

    int numIdx = std::find(curVec.begin(), curVec.end(), num) - curVec.begin();
    int curIdx = numIdx;
    while (curIdx < curVec.size())
    {
        int &toPush = curVec[curIdx];
        t_pos &pushPos = horses[toPush];

        nextVec.push_back(toPush);
        pushPos.y = next.y, pushPos.x = next.x;
        ++curIdx;
    }

    while (numIdx != curVec.size())
    {
        curVec.pop_back();
    }

    maxHeight = std::max(maxHeight, nextVec.size());
}

void    moveReverse(int num, const t_pos &cur, const t_pos &next)
{
    t_vec &curVec = vec[cur.y][cur.x];
    t_vec &nextVec = vec[next.y][next.x];

    int curIdx = std::find(curVec.begin(), curVec.end(), num) - curVec.begin();
    while (curIdx != curVec.size())
    {        
        int &toPush = curVec.back();
        t_pos &pushPos = horses[toPush];

        nextVec.push_back(toPush);
        pushPos.y = next.y, pushPos.x = next.x;
        curVec.pop_back();
    }

    maxHeight = std::max(maxHeight, nextVec.size());
}

void    moveHorse(int num, int depth=0)
{
    t_pos &cur = horses[num];
    t_pos next = {
        cur.y + dy[cur.dir],
        cur.x + dx[cur.dir],
        cur.dir
    };

    if (!(0 <= next.y && next.y < size)
        || !(0 <= next.x && next.x < size)
        || map[next.y][next.x] == WALL)
    {
        if (depth == 1)
            return ;

        cur.dir ^= 1;
        moveHorse(num, depth + 1);
        return ;
    }

    char &nextSpace = map[next.y][next.x];
    switch (nextSpace)
    {
        case EMPTY:
            moveEmpty(num, cur, next);
            break ;
        case REVERSE:
            moveReverse(num, cur, next);
            break ;
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int horseCnt;

    std::cin >> size >> horseCnt;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> map[y][x];
        }
    }
    for (int num = 0; num < horseCnt; ++num)
    {
        int y, x, dir;

        std::cin >> y >> x >> dir;
        --y, --x, --dir;
        horses[num] = {y, x, dir};
        vec[y][x].push_back(num);
    }

    int turn = 1;
    while (turn <= MAX_TURN)
    {
        int num = 0;
        for (; num < horseCnt; ++num)
        {
            moveHorse(num);
            if (maxHeight >= HEIGHT_LIMIT)
                break ;
        }
        if (num != horseCnt)
            break ;

        ++turn;
    }

    std::cout << (turn > MAX_TURN ? -1 : turn) << '\n';
    return 0;
}