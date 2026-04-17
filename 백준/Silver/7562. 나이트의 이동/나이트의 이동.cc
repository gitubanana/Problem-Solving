#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int   MAX = 300;
int         cnt[MAX][MAX];
//(x + 1, y + 2), (x + 2, y + 1), (x + 2, y - 1)
//(x + 1, y - 2), (x - 1, y - 2), (x - 2, y - 1), (x - 2, y + 1), (x - 1, y + 2)
int         dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int         dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

void    print_smallest_move(int board_len, int knight_x, int knight_y, int dest_x, int dest_y)
{
    pair<int, int>  cur_pos;
    int             i, cur_y, cur_x;
    queue<pair<int, int> >  q;

    if (knight_y == dest_y && knight_x == dest_x)
    {
        printf("0\n");
        return ;
    }
    q.push({knight_y, knight_x});
    while (!q.empty())
    {
        cur_pos = q.front();
        q.pop();
        for (i = 0; i < 8; i++)
        {
            cur_y = cur_pos.first + dy[i];
            cur_x = cur_pos.second + dx[i];
            if (!(0 <= cur_y && cur_y < board_len)
                || !(0 <= cur_x && cur_x < board_len)
                || cnt[cur_y][cur_x] != 0)
                continue ;
            q.push({cur_y, cur_x});
            cnt[cur_y][cur_x] = cnt[cur_pos.first][cur_pos.second] + 1;
            if (cur_y == dest_y && cur_x == dest_x)
            {
                printf("%d\n", cnt[cur_y][cur_x]);
                return ;
            }
        }
    }
}

int main(void)
{
    int i, test_cnt;
    int board_len, knight_x, knight_y, dest_x, dest_y;

    scanf("%d", &test_cnt);
    while (test_cnt--)
    {
        scanf("%d", &board_len);
        scanf("%d %d %d %d", &knight_x, &knight_y, &dest_x, &dest_y);
        print_smallest_move(board_len, knight_x, knight_y, dest_x, dest_y);
        for (i = 0; i < board_len; i++)
            memset(cnt[i], 0, sizeof(int) * board_len);
    }
    return 0;
}
