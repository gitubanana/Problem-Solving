#include <iostream>
#include <queue>
#include <cstring>

const int   MAX = 10000;

bool visited[MAX];

struct t_register
{
    int   _num;
    std::string methods;

    t_register(int num) : _num(num)
    {
    }

    inline bool operator==(const t_register &other) const
    {
        return (_num == other._num);
    }

    void    D(void)
    {
        _num = (_num * 2) % 10000;
    }

    void    S(void)
    {
        if (_num == 0)
            _num = 9999;
        else
            --_num;
    }

    void    L(void)
    {
        _num = (_num % 1000 * 10) + (_num / 1000);
    }

    void    R(void)
    {
        _num = (_num % 10 * 1000) + (_num / 10);
    }
};

void    bfs(t_register start, t_register end)
{
    typedef void    (t_register::*t_func)(void);

    std::queue<t_register>  q;
    static const std::string &method_name = "DSLR";
    static t_func             func_arr[] = {
        &t_register::D,
        &t_register::S,
        &t_register::L,
        &t_register::R
    };

    visited[start._num] = true;
    q.push(start);
    while (!q.empty())
    {
        t_register    &cur = q.front();
        for (int i = 0; i < 4; ++i)
        {
            t_func  &func = func_arr[i];
            t_register  next(cur);

            (next.*func)();
            next.methods.push_back(method_name[i]);
            if (visited[next._num] == true)
                continue ;
            if (next == end)
            {
                std::cout << next.methods << '\n';
                return ;
            }
            visited[next._num] = true;
            q.push(next);
        }
        q.pop();
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int test_cnt;
    int start, end;

    std::cin >> test_cnt;
    while (test_cnt--)
    {
        std::cin >> start >> end;
        bfs(start, end);
        if (test_cnt > 0)
            memset(visited, 0, sizeof(visited));
    }
    return (0);
}
