#include <iostream>
#include <queue>
#include <cstring>

const int   MAX = 10000;

bool visited[MAX];

struct t_register
{
    int   num;
    std::string methods;

    t_register(int n) : num(n) { }

    inline bool operator==(const t_register &other) const {
        return (num == other.num);
    }

    void    D(void) { num = (num * 2) % 10000; }
    void    S(void) { (num == 0) ? num = 9999 : --num; }
    void    L(void) { num = (num % 1000 * 10) + (num / 1000); }
    void    R(void) { num = (num % 10 * 1000) + (num / 10); }
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

    visited[start.num] = true;
    q.push(start);
    while (!q.empty())
    {
        t_register    &cur = q.front();
        for (int i = 0; i < 4; ++i)
        {
            t_func  &func = func_arr[i];
            t_register  next(cur);

            (next.*func)();
            if (visited[next.num] == true)
                continue ;

            next.methods.push_back(method_name[i]);
            if (next == end)
            {
                std::cout << next.methods << '\n';
                return ;
            }
            visited[next.num] = true;
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
