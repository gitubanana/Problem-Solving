#include <iostream>
#include <cstring>
#include <queue>

enum e_space
{
    EMPTY = 0,
    WALL,
    ARI,
    BOSS
};

const int MAX_SIZE = 50;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

struct t_pos
{
    int y, x;
    int dir;

    inline bool operator!=(const t_pos &other) const
    {
        return (this->y != other.y || this->x != other.x);
    }
};

struct t_champ : public t_pos
{
    int HP, AD;
};

struct t_move : public t_pos
{
    int change;
    int moved, moveCnt;

    inline void move(void)
    {
        y += dy[dir];
        x += dx[dir];

        ++moved;
        if (moved == moveCnt)
        {
            ++change;
            moved = 0;
            dir = (dir + 1) % dirSize;

            if (change == 2)
            {
                ++moveCnt;
                change = 0;
            }
        }
    }
};

t_champ ari, boss;
int ySize, xSize;
int map[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE][MAX_SIZE];

inline bool isBound(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

void    setInitDir(void)
{
    for (int dir = 0; dir < dirSize; ++dir)
    {
        t_pos check = {
            boss.y + dy[dir],
            boss.x + dx[dir]
        };

        if (!isBound(check))
            continue ;

        if (map[check.y][check.x] == ARI)
        {
            boss.dir = dir;
            ari.dir = dir;
            return ;
        }
    }
}

void    moveAri(void)
{
    int dirCnt = dirSize;

    while (dirCnt--)
    {
        t_pos next = {
            ari.y + dy[ari.dir],
            ari.x + dx[ari.dir]
        };

        if (isBound(next) && map[next.y][next.x] == EMPTY)
        {
            map[ari.y][ari.x] = EMPTY;
            ari.y = next.y, ari.x = next.x;
            map[ari.y][ari.x] = ARI;
            return ;
        }

        --ari.HP;
        ari.dir = (ari.dir + 1) % dirSize;
    }
}

void    moveBoss(void)
{
    int prevDir = (ari.dir + 2) % dirSize;
    t_pos prevAri = {
        ari.y + dy[prevDir],
        ari.x + dx[prevDir]
    };

    if (prevAri != boss)
    {
        map[boss.y][boss.x] = EMPTY;

        boss.y = prevAri.y;
        boss.x = prevAri.x;
        boss.dir = ari.dir;

        map[boss.y][boss.x] = BOSS;
    }
}

void    bfs(const t_pos &start)
{
    int monsterHP = boss.AD;
    std::queue<t_pos> q;

    memset(visited, false, sizeof(visited));
    visited[start.y][start.x] = true;
    q.push(start);
    while (!q.empty() && monsterHP)
    {
        int qSize = q.size();

        --monsterHP;
        while (qSize--)
        {
            const t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir]
                };

                if (!isBound(next)
                    || visited[next.y][next.x])
                    continue ;

                switch (map[next.y][next.x])
                {
                case ARI:
                    ari.HP -= monsterHP;
                    return ;
                case EMPTY:
                    visited[next.y][next.x] = true;
                    q.push(next);
                    break;
                }
            }
        }
    }
}

void    attackAri(void)
{
    static const int spaceCnt = ySize * xSize;

    int checkCnt = 1;
    t_move cur = {
        boss.y,
        boss.x,
        boss.dir,
        0,
        0,
        1
    };

    while (true)
    {
        cur.move();
        if (isBound(cur))
        {
            if (map[cur.y][cur.x] == WALL)
            {
                bfs({cur.y, cur.x});
                return ;
            }

            ++checkCnt;
            if (checkCnt == spaceCnt)
                break ;
        }
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    const char *msg[] = {"CAVELIFE...", "VICTORY!"};

    std::cin >> ySize >> xSize;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            int &space = map[y][x];

            std::cin >> space;
            switch (space)
            {
            case ARI:
                ari.y = y, ari.x = x;
                break;
            case BOSS:
                boss.y = y, boss.x = x;
                break;
            }
        }
    }
    std::cin >> ari.HP >> ari.AD >> boss.HP >> boss.AD;

    setInitDir();
    while (ari.HP > 0)
    {
        boss.HP -= ari.AD;
        if (boss.HP <= 0)
            break ;

        moveAri();

        attackAri();
        moveBoss();
    }

    std::cout << msg[ari.HP > 0] << '\n';
    return (0);
}
