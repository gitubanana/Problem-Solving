#include <iostream>
#include <queue>

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (y == other.y && x == other.x);
    }
};

std::istream   &operator>>(std::istream &in_stream, t_pos &pos)
{
    in_stream >> pos.y >> pos.x;
    return (in_stream);
}

const int Y_SIZE = 10;
const int X_SIZE = 9;

int cnt[Y_SIZE][X_SIZE];
// up, down, left, right
int dy1[] = {-1, 1, 0, 0};
int dx1[] = {0, 0, -1, 1};
const int d1_size = sizeof(dy1) / sizeof(dy1[0]);
//
int dy2[] = {-1, -1, 1, 1, -1, 1, -1, 1};
int dx2[] = {-1, 1, -1, 1, -1, -1, 1, 1};

int bfs(const t_pos &start, const t_pos &end)
{
    std::queue<t_pos> q;

    cnt[start.y][start.x] = 1;
    q.push(start);
    while (!q.empty())
    {
        const t_pos &cur = q.front();
        for (int i = 0; i < d1_size; ++i)
        {
            t_pos one = {cur.y + dy1[i], cur.x + dx1[i]};

            if (!(0 <= one.y && one.y < Y_SIZE)
                || !(0 <= one.x && one.x < X_SIZE)
                || one == end)
                continue ;

            int start_idx = i * 2;
            
            for (int j = start_idx; j <= start_idx + 1; ++j)
            {
                int move = 2;
                t_pos two = one;
                while (move--)
                {
                    two.y += dy2[j];
                    two.x += dx2[j];
            
                    if (!(0 <= two.y && two.y < Y_SIZE)
                        || !(0 <= two.x && two.x < X_SIZE)
                        || (move != 0 && two == end))
                        break ;
                }

                if (move != -1
                    || cnt[two.y][two.x] != 0)
                    continue ;

                cnt[two.y][two.x] = cnt[cur.y][cur.x] + 1;
                if (two == end)
                    return (cnt[cur.y][cur.x]);
                q.push(two);
            }
        }
        q.pop();
    }
    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_pos start, end;

    std::cin >> start >> end;

    std::cout << bfs(start, end) << '\n';
    return (0);
}
