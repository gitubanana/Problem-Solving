#include <iostream>

enum e_idx
{
    UP = 0,
    CEIL,
    DOWN,
    FLOOR,
    LEFT,
    RIGHT
};

enum e_dir
{
    NONE = 0,
    EAST,
    WEST,
    NORTH,
    SOUTH
};

const int MAX = 20;

int map[MAX][MAX];
int ySize, xSize;
// 동, 서, 남, 북
int dy[] = {0, 0, 0, -1, 1};
int dx[] = {0, 1, -1, 0, 0};

struct t_dice
{
    int y, x;
    int nums[6];

    bool move(int cmd)
    {
        int nextY = y + dy[cmd];
        int nextX = x + dx[cmd];

        if (!(0 <= nextY && nextY < ySize)
            || !(0 <= nextX && nextX < xSize))
            return (false);

        switch (cmd)
        {
        case WEST: {
            int right = nums[RIGHT];

            nums[RIGHT] = nums[CEIL];
            nums[CEIL] = nums[LEFT];
            nums[LEFT] = nums[FLOOR];
            nums[FLOOR] = right;
        }
            break;
        case EAST: {
            int left = nums[LEFT];

            nums[LEFT] = nums[CEIL];
            nums[CEIL] = nums[RIGHT];
            nums[RIGHT] = nums[FLOOR];
            nums[FLOOR] = left;
        }
            break ;
        case NORTH: {
            int i = 0;
            int tmp = nums[UP];

            for (; i < 3; ++i)
            {
                nums[i] = nums[i + 1];
            }
            nums[i] = tmp;
        }
            break ;
        case SOUTH: {
            int i = 3;
            int tmp = nums[FLOOR];

            for (; i > 0; --i)
            {
                nums[i] = nums[i - 1];
            }
            nums[i] = tmp;
        }
            break ;
        }

        y = nextY;
        x = nextX;
        if (map[y][x] == 0)
        {
            map[y][x] = nums[FLOOR];
        }
        else
        {
            nums[FLOOR] = map[y][x];
            map[y][x] = 0;
        }
        return (true);
    }
};

t_dice dice;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cmdCnt;

    std::cin >> ySize >> xSize >> dice.y >> dice.x >> cmdCnt;
    for (int y = 0; y < ySize; ++y)
    {
        for (int x = 0; x < xSize; ++x)
            std::cin >> map[y][x];
    }

    int cmd;
    while (cmdCnt--)
    {
        std::cin >> cmd;
        if (dice.move(cmd))
            std::cout << dice.nums[CEIL] << '\n';
    }

    return (0);
}
