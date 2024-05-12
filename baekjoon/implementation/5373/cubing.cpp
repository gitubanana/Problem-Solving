#include <iostream>
#include <vector>

enum e_dir
{
    UP = 0,
    DOWN,
    FRONT,
    BACK,
    LEFT,
    RIGHT
};

const char *msg[] = {"UP", "DOWN", "FRONT", "BACK", "LEFT", "RIGHT"};

typedef std::vector<std::string> t_vec;

struct t_plain
{
    static const int SIZE = 3;

    t_vec plain;

    t_plain(void) : plain(SIZE)
    {
        for (int y = 0; y < SIZE; ++y)
        {
            plain[y].resize(SIZE);
        }
    }

    void    rotate90(void)
    {
        static t_plain tmp;

        for (int y = 0; y < SIZE; ++y)
        {
            for (int x = 0; x < SIZE; ++x)
            {
                tmp.plain[y][x] = this->plain[SIZE - x - 1][y];
            }
        }

        this->plain = tmp.plain;
    }

    void    rotate_90(void)
    {
        static t_plain tmp;

        for (int y = 0; y < SIZE; ++y)
        {
            for (int x = 0; x < SIZE; ++x)
            {
                tmp.plain[y][x] = this->plain[x][SIZE - y - 1];
            }
        }

        this->plain = tmp.plain;
    }
};

std::vector<t_plain> cube(6);

void    initCube(void)
{
    static const char *color = "wyrogb";

    for (int dir = UP; dir <= RIGHT; ++dir)
    {
        for (int y = 0; y < t_plain::SIZE; ++y)
        {
            for (int x = 0; x < t_plain::SIZE; ++x)
            {
                cube[dir].plain[y][x] = color[dir];
            }
        }
    }
}

void    rotateUp(bool isClockWise)
{
    static const int moveCnt = 3;

    t_vec &leftP = cube[LEFT].plain;
    t_vec &backP = cube[BACK].plain;
    t_vec &rightP = cube[RIGHT].plain;
    t_vec &frontP = cube[FRONT].plain;
    char leftCh[] = {leftP[0][2], leftP[1][2], leftP[2][2]};
    char backCh[] = {backP[2][0], backP[2][1], backP[2][2]};
    char rightCh[] = {rightP[0][0], rightP[1][0], rightP[2][0]};
    char frontCh[] = {frontP[0][0], frontP[0][1], frontP[0][2]};

    std::vector<std::string> &up = cube[UP].plain;
    if (isClockWise)
    {
        // move Up plain
        up = {
            {up[2][0], up[1][0], up[0][0]},
            {up[2][1], up[1][1], up[0][1]},
            {up[2][2], up[1][2], up[0][2]},
        };

        // move Other plains
        int putY = 0, putX = 2;
        for (int i = 0; i < moveCnt; ++i)
        {
            cube[LEFT].plain[putY][putX] = frontCh[i];
            ++putY;
        }

        putY = 2, putX = 0;
        for (int i = moveCnt - 1; i >= 0; --i)
        {
            cube[BACK].plain[putY][putX] = leftCh[i];
            ++putX;
        }

        putY = 0, putX = 0;
        for (int i = 0; i < moveCnt; ++i)
        {
            cube[RIGHT].plain[putY][putX] = backCh[i];
            ++putY;
        }

        putY = 0, putX = 0;
        for (int i = moveCnt - 1; i >= 0; --i)
        {
            cube[FRONT].plain[putY][putX] = rightCh[i];
            ++putX;
        }
    }
    else
    {
        // move Up plain
        up = {
            {up[0][2], up[1][2], up[2][2]},
            {up[0][1], up[1][1], up[2][1]},
            {up[0][0], up[1][0], up[2][0]},
        };

        // move Other plains
        int putY = 0, putX = 0;
        for (int i = 0; i < moveCnt; ++i)
        {
            cube[FRONT].plain[putY][putX] = leftCh[i];
            ++putX;
        }

        putY = 0, putX = 2;
        for (int i = moveCnt - 1; i >= 0; --i)
        {
            cube[LEFT].plain[putY][putX] = backCh[i];
            ++putY;
        }

        putY = 2, putX = 0;
        for (int i = 0; i < moveCnt; ++i)
        {
            cube[BACK].plain[putY][putX] = rightCh[i];
            ++putX;
        }

        putY = 0, putX = 0;
        for (int i = moveCnt - 1; i >= 0; --i)
        {
            cube[RIGHT].plain[putY][putX] = frontCh[i];
            ++putY;
        }
    }
}

void    moveCube(char movePlain, bool isClockWise)
{
    // up, down, front, back, left, right

    switch (movePlain)
    {
    case 'U':
        rotateUp(isClockWise);
        break;
    case 'D':
        cube = {cube[DOWN], cube[UP], cube[FRONT], cube[BACK], cube[RIGHT], cube[LEFT]};
        cube[FRONT].rotate90(), cube[FRONT].rotate90();
        cube[BACK].rotate90(), cube[BACK].rotate90();

        rotateUp(isClockWise);

        cube[FRONT].rotate90(), cube[FRONT].rotate90();
        cube[BACK].rotate90(), cube[BACK].rotate90();
        cube = {cube[DOWN], cube[UP], cube[FRONT], cube[BACK], cube[RIGHT], cube[LEFT]};
        break;
    case 'F':
        cube = {cube[FRONT], cube[BACK], cube[DOWN], cube[UP], cube[LEFT], cube[RIGHT]};
        cube[LEFT].rotate_90();
        cube[RIGHT].rotate90();
        cube[FRONT].rotate90(), cube[FRONT].rotate90();

        rotateUp(isClockWise);

        cube[LEFT].rotate90();
        cube[RIGHT].rotate_90();
        cube[FRONT].rotate90(), cube[FRONT].rotate90();
        cube = {cube[BACK], cube[FRONT], cube[UP], cube[DOWN], cube[LEFT], cube[RIGHT]};
        break;
    case 'B':
        cube = {cube[BACK], cube[FRONT], cube[UP], cube[DOWN], cube[LEFT], cube[RIGHT]};
        cube[LEFT].rotate90();
        cube[RIGHT].rotate_90();
        cube[BACK].rotate90(), cube[BACK].rotate90();

        rotateUp(isClockWise);

        cube[LEFT].rotate_90();
        cube[RIGHT].rotate90();
        cube[BACK].rotate90(), cube[BACK].rotate90();
        cube = {cube[FRONT], cube[BACK], cube[DOWN], cube[UP], cube[LEFT], cube[RIGHT]};
        break;
    case 'L':
        cube = {cube[LEFT], cube[RIGHT], cube[FRONT], cube[BACK], cube[DOWN], cube[UP]};
        cube[FRONT].rotate90();
        cube[BACK].rotate_90();

        rotateUp(isClockWise);

        cube[FRONT].rotate_90();
        cube[BACK].rotate90();
        cube = {cube[RIGHT], cube[LEFT], cube[FRONT], cube[BACK], cube[UP], cube[DOWN]};
        break;
    case 'R':
        cube = {cube[RIGHT], cube[LEFT], cube[FRONT], cube[BACK], cube[UP], cube[DOWN]};
        cube[FRONT].rotate_90();
        cube[BACK].rotate90();

        rotateUp(isClockWise);

        cube[FRONT].rotate90();
        cube[BACK].rotate_90();
        cube = {cube[LEFT], cube[RIGHT], cube[FRONT], cube[BACK], cube[DOWN], cube[UP]};
        break;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int cmdCnt;
    int testCnt;
    std::string cmd;

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> cmdCnt;

        initCube();
        while (cmdCnt--)
        {
            std::cin >> cmd;
            moveCube(cmd[0], (cmd[1] == '+'));
        }

        for (int y = 0; y < t_plain::SIZE; ++y)
        {
            std::cout << cube[UP].plain[y] << '\n';
        }
    }
    return (0);
}
