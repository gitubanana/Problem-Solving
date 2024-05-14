#include <iostream>
#include <vector>

const int MAX = 10;

int ans, size;
std::vector<int> weight;

void    back_tracking(int energy=0, int depth=0)
{
    if (depth == size - 2)
    {
        ans = std::max(ans, energy);
        return ;
    }

    int size_1 = weight.size() - 1;
    for (int x = 1; x < size_1; ++x)
    {
        int removeW = weight[x];

        weight.erase(weight.begin() + x);
        back_tracking(energy + weight[x - 1] * weight[x], depth + 1);
        weight.insert(weight.begin() + x, removeW);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int w;

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> w;
        weight.push_back(w);
    }

    back_tracking();
    std::cout << ans << '\n';
    return (0);
}
