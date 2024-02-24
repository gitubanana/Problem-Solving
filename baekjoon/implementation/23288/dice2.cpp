#include <iostream>
#include <cstring>

enum e_dir
{
    NORTH = 0,
    EAST,
    SOUTH,
    WEST
};

enum e_space
{
    UP = 0,
    CEIL,
    DOWN,
    FLOOR,
    LEFT,
    RIGHT
};

const int MAX = 20;

int ySize, xSize;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

struct t_dice
{
    static const int SIZE = 6;

    int score;
    int dir;
    int y, x;
    int arr[SIZE];

    t_dice() : score(0), dir(1), y(0), x(0)
    {
        arr[UP] = 2;
        arr[CEIL] = 1;
        arr[DOWN] = 5;
        arr[FLOOR] = 6;
        arr[LEFT] = 4;
        arr[RIGHT] = 3;
    }

    void    moveArr(void)
    {
        int up, floor, right, left;

        switch (dir)
        {
        case NORTH:
        {
            up = arr[UP];
            for (int i = 0; i < 3; ++i)
                arr[i] = arr[i + 1];
            arr[FLOOR] = up;
        }
            break;
        case SOUTH:
        {
            floor = arr[FLOOR];
            for (int i = 3; i >= 1; --i)
                arr[i] = arr[i - 1];
            arr[UP] = floor;
        }
            break;
        case EAST:
        {
            right = arr[RIGHT];

            arr[RIGHT] = arr[CEIL];
            arr[CEIL] = arr[LEFT];
            arr[LEFT] = arr[FLOOR];
            arr[FLOOR] = right;
        }
            break;
        default: // WEST
        {
            left = arr[LEFT];

            arr[LEFT] = arr[CEIL];
            arr[CEIL] = arr[RIGHT];
            arr[RIGHT] = arr[FLOOR];
            arr[FLOOR] = left;
        }
        }
    }

    void dfs(int y, int x, int num, int &toAdd)
    {
        visited[y][x] = true;

        for (int i = 0; i < 4; ++i)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];

            if (!(0 <= nextY && nextY < ySize)
                || !(0 <= nextX && nextX < xSize)
                || map[nextY][nextX] != num
                || visited[nextY][nextX])
                continue ;

            ++toAdd;
            dfs(nextY, nextX, num, toAdd);
        }
    }

    void    move(void)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!(0 <= nextY && nextY < ySize)
            || !(0 <= nextX && nextX < xSize))
        {
            dir = (dir + 2) % 4;

            nextY = y + dy[dir];
            nextX = x + dx[dir];
        }

        y = nextY;
        x = nextX;
        moveArr();

        // 점수 추가하기
        memset(visited, false, sizeof(visited));

        int cnt = 1;
        dfs(y, x, map[y][x], cnt);
        score += map[y][x] * cnt;

        //  이동 방향 결정
        if (arr[FLOOR] > map[y][x])
        {
            dir = (dir + 1) % 4;
        }
        else if (arr[FLOOR] < map[y][x])
        {
            if (dir == 0)
                dir = 3;
            else
                --dir;
        }
    }
};

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int moveCnt;
    t_dice dice;

    std::cin >> ySize >> xSize >> moveCnt;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
        {
            std::cin >> map[y][x];
        }
    }

    while (moveCnt--)
    {
        dice.move();
    }

    std::cout << dice.score << '\n';
    return (0);
}
