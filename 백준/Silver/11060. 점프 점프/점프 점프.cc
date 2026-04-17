#include <queue>
#include <cstring>
#include <iostream>

void    bfs(int *&arr, int &size, int *&cnt)
{
    std::queue<int> q;
    int             i, cur_idx;
    
    q.push(0);
    while (!q.empty())
    {
        cur_idx = q.front(), q.pop();
        for (i = cur_idx + 1; i <= arr[cur_idx] + cur_idx; i++)
        {
            if (i > size - 1 || cnt[i] != 0)
                continue ;
            q.push(i);
            cnt[i] = cnt[cur_idx] + 1;
            if (i == size - 1)
                return ;
        }
    }
}

int main(void)
{
    int *cnt;
    int *arr, size;
    
    std::cin >> size;
    arr = new int[size];
    cnt = new int[size];
    for (int i = 0; i < size; i++)
        std::cin >> arr[i];
    memset(cnt, 0, sizeof(cnt));
    bfs(arr, size, cnt);
    if (size != 1)
        std::cout << (cnt[size - 1] != 0 ? cnt[size - 1] : -1);
    else
        std::cout << 0;
    delete[] arr;
    delete[] cnt;
    return (0);
}