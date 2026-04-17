#include <iostream>
#include <deque>
#include <vector>

struct t_pos
{
    int y;
    int x;
};

struct t_move
{
    int sec;
    char dir;
};

enum e_space
{
    EMPTY,
    APPLE,
    SNAKE
};

enum e_dir
{
    DIR_LEFT = 'L',
    DIR_RIGHT = 'D'
};

const int   MAX = 101;

int size;
int map[MAX][MAX];

// right, down, left, up
// -> RIGHT일 때는 ( + 1) % 4
// -> LEFT일 때는 ( + 3) % 4
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};

int simulation(t_move *move_arr, int arr_size)
{
    int sec;
    int dir;
    int idx, plus;
    t_pos   cur_pos, next_pos, tail;
    std::deque<t_pos>   snake;

    sec = dir = idx = 0;
    tail.y = tail.x = 1;
    map[tail.y][tail.x] = SNAKE;
    snake.push_back(tail);
    while (true)
    {
        ++sec;
        cur_pos = snake.back();
        next_pos.y = cur_pos.y + dy[dir];
        next_pos.x = cur_pos.x + dx[dir];
        if (!(0 < next_pos.y && next_pos.y <= size)
            || !(0 < next_pos.x && next_pos.x <= size)
            || map[next_pos.y][next_pos.x] == SNAKE)
            break ;
        snake.push_back(next_pos);
        if (map[next_pos.y][next_pos.x] == EMPTY)
        {
            map[tail.y][tail.x] = EMPTY;
            snake.pop_front(), tail = snake.front();
        }
        if (idx < arr_size && move_arr[idx].sec == sec)
        {
            plus = 1 + ((move_arr[idx++].dir == DIR_LEFT) * 2);
            dir = (dir + plus) % 4;
        }
        map[next_pos.y][next_pos.x] = SNAKE;
    }
    return (sec);
}

int main(void)
{
    t_pos   apple;
    t_move  *move_arr;
    int     pos_cnt, arr_size;

    scanf(" %d %d", &size, &pos_cnt);
    while (pos_cnt--)
    {
        scanf(" %d %d", &apple.y, &apple.x);
        map[apple.y][apple.x] = APPLE;
    }

    scanf(" %d", &arr_size);
    move_arr = new t_move[arr_size];
    for (int i = 0; i < arr_size; ++i)
        scanf(" %d %c", &move_arr[i].sec, &move_arr[i].dir);

    printf("%d\n", simulation(move_arr, arr_size));

    delete[] move_arr;
    return (0);
}
