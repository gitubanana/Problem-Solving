#include <iostream>

enum e_space
{
    TEACHER = 'T',
    STUDENT = 'S',
    WALL = 'O',
    EMPTY = 'X'
};

struct t_pos
{
    int y, x;
};

const int MAX = 6;
const int TEACHER_CNT = 15;

int size, tSize;
int LIMIT = 3;
char map[MAX][MAX + 1];
t_pos teachers[TEACHER_CNT];
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

bool foundStudent(t_pos &teacher)
{
    for (int i = 0; i < 4; ++i)
    {
        int y = teacher.y;
        int x = teacher.x;

        while ((0 <= y && y < size)
                && (0 <= x && x < size))
        {
            if (map[y][x] == STUDENT)
                return (true);

            if (map[y][x] == WALL)
                break ;

            y += dy[i];
            x += dx[i];
        }
    }
    return (false);
}

bool    back_tracking(int startY, int startX, int depth)
{
    if (depth == LIMIT)
    {
        for (int i = 0; i < tSize; ++i)
        {
            if (foundStudent(teachers[i]))
            {
                return (false);
            }
        }
        return (true);
    }

    int y = startY;
    int x = startX;
    while (true)
    {
        if (y >= size && x >= size)
            break ;

        if (x == size)
        {
            x = 0;
            ++y;
        }

        if (map[y][x] == EMPTY)
        {
            map[y][x] = WALL;
            if (back_tracking(y, x + 1, depth + 1))
                return (true);
            map[y][x] = EMPTY;
        }
        ++x;
    }

    return (false);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    const char *msg[] = {"NO", "YES"};

    std::cin >> size;
    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            std::cin >> map[y][x];
            if (map[y][x] == TEACHER)
            {
                teachers[tSize++] = {y, x};
            }
        }
    }

    std::cout << msg[back_tracking(0, 0, 0)] << '\n';
    return (0);
}
