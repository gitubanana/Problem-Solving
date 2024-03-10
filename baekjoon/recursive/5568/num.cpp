#include <iostream>
#include <unordered_set>

const int MAX = 10;

std::string arr[MAX];
bool visited[MAX];
int size, limit;
std::unordered_set<std::string> uset;

void    back_tracking(std::string cur="", int depth=0)
{
    if (depth == limit)
    {
        uset.insert(cur);
        return ;
    }

    for (int i = 0; i < size; ++i)
    {
        if (visited[i])
            continue ;

        visited[i] = true;
        back_tracking(cur + arr[i], depth + 1);
        visited[i] = false;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size >> limit;
    for (int i = 0; i < size; ++i)
        std::cin >> arr[i];

    back_tracking();
    std::cout << uset.size() << '\n';
    return (0);
}
