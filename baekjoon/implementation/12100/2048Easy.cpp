#include <iostream>

enum e_idx
{
    Y = 0,
    X
};

const int MAX = 20;
const int EMPTY = 0;
const int DEPTH_LIMIT = 5;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ans;
int size;
int dirByDepth[DEPTH_LIMIT];

void printBoard(int board[MAX][MAX])
{
    std::cout << "========================" << '\n';
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cout << board[y][x] << ' ';
        }
        std::cout << '\n';
    }
}

inline int getMax(int board[MAX][MAX])
{
    int maxNum = 0;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
            maxNum = std::max(maxNum, board[y][x]);
    }
    return (maxNum);
}

inline bool isBound(int pos)
{
    return (0 <= pos && pos < size);
}

void    moveToDir(int board[MAX][MAX], int dir)
{
    static const int startPos[2][4] = {
        {0, size - 1, 0, 0},
        {0, 0, 0, size - 1}
    };
    static const int steps[2][4] = {
        {1, -1, 1, 1},
        {1, 1, 1, -1}
    };

    int pos[] = {startPos[0][dir], startPos[1][dir]};
    int firstIdx = (dir <= 1);
    int secondIdx = (dir > 1);
    int &firstPos = pos[firstIdx];
    int &secondPos = pos[secondIdx];

    while (isBound(firstPos))
    {
        secondPos = startPos[secondIdx][dir];
        while (true)
        {
            int &curSpace = board[pos[Y]][pos[X]];

            secondPos += steps[secondIdx][dir];
            int copy = secondPos;
            while (isBound(secondPos)
                && board[pos[Y]][pos[X]] == EMPTY)
            {
                secondPos += steps[secondIdx][dir];
            }

            if (!isBound(secondPos))
                break ;

            int &nextSpace = board[pos[Y]][pos[X]];

            if (curSpace == nextSpace)
            {
                curSpace <<= 1;
                nextSpace = EMPTY;

                secondPos += steps[secondIdx][dir];
                if (!isBound(secondPos))
                    break ;
            }
            else
                secondPos = copy;
        }

        // moveEmptys
        secondPos = startPos[secondIdx][dir];
        while (isBound(secondPos))
        {
            int &curSpace = board[pos[Y]][pos[X]];

            if (curSpace == EMPTY)
            {
                int copy = secondPos;

                secondPos += steps[secondIdx][dir];
                while (isBound(secondPos)
                    && board[pos[Y]][pos[X]] == EMPTY)
                {
                    secondPos += steps[secondIdx][dir];
                }
                if (isBound(secondPos))
                {
                    curSpace = board[pos[Y]][pos[X]];
                    board[pos[Y]][pos[X]] = EMPTY;
                    secondPos = copy;
                }
            }

            secondPos += steps[secondIdx][dir];
        }

        firstPos += steps[firstIdx][dir];
    }
}

void    back_tracking(int board[MAX][MAX], int depth=0)
{
    if (depth == DEPTH_LIMIT)
    {
        ans = std::max(ans, getMax(board));
        return ;
    }

    int &curDir = dirByDepth[depth];
    while (curDir < dirSize)
    {
        int newBoard[MAX][MAX];

        for (int y = 0; y < size; ++y)
        {
            for (int x = 0; x < size; ++x)
                newBoard[y][x] = board[y][x];
        }

        moveToDir(newBoard, curDir);
        back_tracking(newBoard, depth + 1);
        ++curDir;
    }
    curDir = 0;
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int board[MAX][MAX];

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
            std::cin >> board[y][x];
    }

    back_tracking(board);

    std::cout << ans << '\n';
    return (0);
}
