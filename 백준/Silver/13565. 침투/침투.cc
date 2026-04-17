#include <iostream>

const int       MAX = 1001;
const char      CAN_GO = '0';
const char      VISITED = '2';

char    map[MAX][MAX];
//up, down, right, left
int             dy[] = {-1, 1, 0, 0};
int             dx[] = {0, 0, 1, -1};

void    dfs(int y, int x, int &y_size, int &x_size)
{
        if (!(0 <= y && y < y_size)     || !(0 <= x && x < x_size)
                || (map[y][x] == VISITED) || (map[y][x] != CAN_GO))
                return ;
        map[y][x] = VISITED;
        for (int i = 0; i < 4; i++)
                dfs(y + dy[i], x + dx[i], y_size, x_size);
}


int     main(void)
{
        int     y, x;
        int     y_size, x_size;

        std::cin >> y_size >> x_size;
        for (y = 0; y < y_size; y++)
                std::cin >> map[y];
        for (x = 0; x < x_size; x++)
                dfs(0, x, y_size, x_size);
        for (x = 0; x < x_size; x++)
        {
                if (map[y_size - 1][x] == VISITED)
                {
                        std::cout << "YES";
                        return (0);
                }
        }
        std::cout << "NO";
        return (0);
}