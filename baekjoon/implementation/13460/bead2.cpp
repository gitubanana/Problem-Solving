#include <iostream>
#include <climits>

struct t_pos
{
    int y, x;
};

struct t_board
{
    static const int MAX = 10;

    enum e_status
    {
        WIN,
        LOSE,
        KEEP_GOING
    };

    enum e_space
    {
        EMPTY = '.',
        WALL = '#',
        GOAL = 'O',
        RED = 'R',
        BLUE = 'B'
    };

    char map[MAX][MAX + 1];
    t_pos red, blue;
    int ySize, xSize;

    inline void upBead(t_pos &bead)
    {
        static const int dy = -1;

        map[bead.y][bead.x] = EMPTY;
        do
        {
            bead.y += dy;
        } while (map[bead.y][bead.x] == EMPTY);
        if (map[bead.y][bead.x] != GOAL)
            bead.y -= dy;
    }

    int    up(void)
    {
        if (red.y < blue.y)
        {
            upBead(this->red);
            char &redSpace = map[red.y][red.x];
            if (redSpace != GOAL)
                redSpace = RED;

            upBead(this->blue);
        }
        else
        {
            upBead(this->blue);
            char &blueSpace = map[blue.y][blue.x];
            if (blueSpace == GOAL)
                return (LOSE);
            blueSpace = BLUE;

            upBead(this->red);
            char &redSpace = map[red.y][red.x];
            if (redSpace != GOAL)
                redSpace = RED;
        }

        char &blueSpace = map[blue.y][blue.x];
        if (blueSpace == GOAL)
            return (LOSE);

        char &redSpace = map[red.y][red.x];
        if (redSpace == GOAL)
            return (WIN);

        blueSpace = BLUE;
        return (KEEP_GOING);
    }

    void    rotate90(void)
    {
        static int tempMap[MAX][MAX];

        int newYsize = xSize;
        int newXsize = ySize;

        for (int y = 0; y < newYsize; ++y)
        {
            for (int x = 0; x < newXsize; ++x)
            {
                tempMap[y][x] = map[ySize - x - 1][y];
            }
        }

        for (int y = 0; y < newYsize; ++y)
        {
            for (int x = 0; x < newXsize; ++x)
            {
                map[y][x] = tempMap[y][x];
            }
        }

        int tmp = red.x;
        red.x = ySize - red.y - 1;
        red.y = tmp;

        tmp = blue.x;
        blue.x = ySize - blue.y - 1;
        blue.y = tmp;

        ySize = newYsize;
        xSize = newXsize;
    }
};

const int DEPTH_LIMIT = 11;

int ans = INT_MAX;

void    back_tracking(t_board &board, int depth=1)
{
    if (depth == DEPTH_LIMIT)
    {
        return ;
    }

    int i = 1;

    if (depth != 1)
        board.rotate90();
    else
        i = 0;

    for (; i < 4; ++i)
    {
        t_board next = board;

        switch (next.up())
        {
        case t_board::KEEP_GOING:
            back_tracking(next, depth + 1);
            break;
        case t_board::WIN:
            ans = std::min(ans, depth);
            break;
        }

        board.rotate90();
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_board init;

    std::cin >> init.ySize >> init.xSize;
    for (int y = 0; y < init.ySize; ++y)
    {
        std::cin >> init.map[y];
        for (int x = 0; x < init.xSize; ++x)
        {
            char &curSpace = init.map[y][x];

            switch (curSpace)
            {
            case t_board::RED:
                init.red = {y, x};
                break;
            case t_board::BLUE:
                init.blue = {y, x};
            }
        }
    }

    back_tracking(init);

    std::cout << (ans == INT_MAX ? -1 : ans) << '\n';
    return (0);
}
