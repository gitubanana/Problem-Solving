#include <iostream>
#include <cstring>

const int   MAX = 1001;

bool visited[MAX];
int  _friend[MAX], size;

int get_friend_cnt(int cur)
{
    int &next = _friend[cur];
    if (visited[next] == true)
        return (0);

    visited[cur] = true;
    return (1 + get_friend_cnt(next));
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;
    for (int i = 1; i <= size; ++i)
        std::cin >> _friend[i];

    int ans, cnt = 0;
    for (int i = 1; i <= size; ++i)
    {
        int cur_cnt = get_friend_cnt(i);
        if (cnt < cur_cnt)
        {
            cnt = cur_cnt;
            ans = i;
        }
        if (i != size - 1)
            memset(visited, 0, sizeof(visited));
    }

    std::cout << ans << '\n';
    return 0;
}
