#include <iostream>
#include <algorithm>
#include <set>

typedef std::multiset<int> t_bag;

struct t_gem
{
    int weight;
    int price;

    inline bool operator<(const t_gem &other) const
    {
        return (this->price > other.price);
    }
};

inline std::istream &operator>>(std::istream &in, t_gem &input)
{
    in >> input.weight >> input.price;
    return (in);
}

const int MAX = 300000;

t_bag bags;
t_gem gems[MAX];
int gemSize, bagSize;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int bag;

    std::cin >> gemSize >> bagSize;
    for (int i = 0; i < gemSize; ++i)
        std::cin >> gems[i];

    for (int i = 0; i < bagSize; ++i)
    {
        std::cin >> bag;
        bags.insert(bag);
    }

    std::sort(gems, gems + gemSize);

    int gemIdx = 0;
    long long ans = 0;
    while (bagSize && gemIdx < gemSize)
    {
        t_bag::iterator it = bags.lower_bound(gems[gemIdx].weight);

        if (it != bags.end())
        {
            ans += gems[gemIdx].price;
            bags.erase(it);
            --bagSize;
        }
        ++gemIdx;
    }

    std::cout << ans << '\n';
    return (0);
}
