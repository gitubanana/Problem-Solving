#include <iostream>
#include <vector>
#define CURMAP map[curIdx]
#define NEXTMAP map[nextIdx]

enum e_space
{
    EMPTY = 0
};

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }

    inline bool operator!=(const t_pos &other) const
    {
        return (this->y != other.y || this->x != other.x);
    }
};

const int GROUP_SIZE = 4;
const int MAX_COLOR = 3;
const int MAX_SIZE = 49;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};
const int dirSize = sizeof(dy) / sizeof(dy[0]);
const int switchDir[] = {-1, 3, 1, 0, 2};
const t_pos END = {0, -1};

int size;
t_pos shark;
int curIdx, nextIdx;
int map[2][MAX_SIZE][MAX_SIZE];
int exploded[MAX_COLOR + 1];

struct t_move : public t_pos
{
    int dir;
    int dist;
    int remainDist;

    inline void    move(void)
    {
        this->y += dy[dir];
        this->x += dx[dir];

        if (--remainDist == 0)
        {
            if (dir & 1)
            {
                ++dist;
            }
            dir = (dir + 1) % dirSize;
            remainDist = dist;
        }
    }
};

void    blizzard(int dir, int dist)
{
    t_pos remove = {
        shark.y + dy[dir],
        shark.x + dx[dir]
    };

    while (dist--)
    {
        CURMAP[remove.y][remove.x] = EMPTY;
        remove.y += dy[dir];
        remove.x += dx[dir];
    }
}

void    fillEmpty(void)
{
    t_move cur = {
        shark.y,
        shark.x,
        0,
        1,
        1
    };
    cur.move();
    t_move next = cur;

    while (cur != END)
    {
        int &curSpace = CURMAP[cur.y][cur.x];
        int &nextSpace = NEXTMAP[next.y][next.x];

        if (curSpace != EMPTY)
        {
            nextSpace = curSpace;
            next.move();
        }

        cur.move();
    }

    while (next != END)
    {
        NEXTMAP[next.y][next.x] = EMPTY;
        next.move();
    }
}

bool makeExplosion(void)
{
    static std::vector<t_pos> groupPos;

    bool removed = false;
    t_move cur = {
        shark.y,
        shark.x,
        0,
        1,
        1
    };
    cur.move();

    while (cur != END)
    {
        int &groupBead = CURMAP[cur.y][cur.x];
        if (groupBead == EMPTY)
            break ;

        groupPos.clear();
        do
        {
            groupPos.push_back({cur.y, cur.x});
            cur.move();
        } while (cur != END && groupBead == CURMAP[cur.y][cur.x]);

        if (groupPos.size() >= GROUP_SIZE)
        {
            removed = true;
            exploded[groupBead] += groupPos.size();

            for (const t_pos &pos : groupPos)
            {
                CURMAP[pos.y][pos.x] = EMPTY;
            }
        }
    }

    return (removed);
}

void    makeNewBeads(void)
{
    t_move cur = {
        shark.y,
        shark.x,
        0,
        1,
        1
    };
    cur.move();
    t_move next = cur;

    while (cur != END)
    {
        int cnt = 0;
        int &groupBead = CURMAP[cur.y][cur.x];
        if (groupBead == EMPTY)
            break ;

        do
        {
            ++cnt;
            cur.move();
        } while (cur != END && groupBead == CURMAP[cur.y][cur.x]);

        NEXTMAP[next.y][next.x] = cnt;
        next.move();
        if (next == END)
            break ;

        NEXTMAP[next.y][next.x] = groupBead;
        next.move();
        if (next == END)
            break ;
    }

    while (next != END)
    {
        NEXTMAP[next.y][next.x] = EMPTY;
        next.move();
    }
}

inline int getAnswer(void)
{
    int ans = 0;

    for (int i = 1; i <= MAX_COLOR; ++i)
    {
        ans += i * exploded[i];
    }
    return (ans);
}

int main(void) 
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cmdCnt;

    std::cin >> size >> cmdCnt;
    shark = {size / 2, size / 2};
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> CURMAP[y][x];
        }
    }

    while (cmdCnt--)
    {
        int dir, dist;

        std::cin >> dir >> dist;

        blizzard(switchDir[dir], dist);
        do
        {
            nextIdx = curIdx ^ 1;
            fillEmpty();
            curIdx = nextIdx;
        } while (makeExplosion());

        nextIdx = curIdx ^ 1;
        makeNewBeads();
        curIdx = nextIdx;
    }

    std::cout << getAnswer() << '\n';
    return (0);
}
