#include <iostream>
#include <cstring>

const int   MAX = 50;

char    map[MAX][MAX + 1];
int     visited[MAX];
int     v_cnt;

int main(void)
{
    int v, i, first, second;
    int tmp, max;

    scanf(" %d", &v_cnt);
    for (v = 0; v < v_cnt; ++v)
        scanf(" %s", map[v]);
    max = 0;
    for (v = 0; v < v_cnt; ++v)
    {
        tmp = 0;
        memset(visited, 0, sizeof(int) * v_cnt);
        visited[v] = 1;
        for (first = 0; first < v_cnt; ++first)
        {
            if (map[v][first] == 'Y')
            {
                tmp += (visited[first] == 0);
                visited[first] = 1;
                for (second = 0; second < v_cnt; ++second)
                    if (map[first][second] == 'Y' && !visited[second])
                        visited[second] = 1, ++tmp;
            }
        }
        if (max < tmp)
            max = tmp;
    }
    printf("%d\n", max);
    return 0;
}