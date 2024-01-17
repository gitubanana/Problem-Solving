#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <deque>

struct t_frequency
{
    int num;
    int cnt;
    int appeared;

    inline bool operator<(const t_frequency &other) const
    {
        if (this->cnt == other.cnt)
            return this->appeared < other.appeared;
        return this->cnt > other.cnt;
    }
};

typedef std::unordered_map<int, t_frequency> t_umap;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size, max;
    t_umap umap;

    std::cin >> size >> max;
    for (int i = 0; i < size; ++i)
    {
        int tmp;
        std::cin >> tmp;

        t_umap::iterator it = umap.find(tmp);
        if (it == umap.end())
            umap.insert({tmp, {tmp, 1, i}});
        else
            ++it->second.cnt;
    }

    std::deque<t_frequency> arr;
    t_umap::iterator it = umap.begin();
    for (; it != umap.end(); ++it)
        arr.push_front({it->second});

    std::sort(arr.begin(), arr.end());

    for (t_frequency &frequency : arr)
    {
        while (frequency.cnt--)
            std::cout << frequency.num << ' ';
    }
    std::cout << '\n';
}