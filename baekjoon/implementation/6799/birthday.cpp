#include <iostream>
#include <vector>
#include <algorithm>

struct t_com
{
    std::string name;
    int prefer;
    
    inline bool operator<(const t_com &o) const
    {
        if (this->prefer == o.prefer)
            return this->name < o.name;

        return this->prefer > o.prefer;
    }
};

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    std::vector<t_com> arr;
    
    std::cin >> size;
    arr.reserve(size);
    while (size--)
    {
        std::string name;
        int r, s, d;
        
        std::cin >> name >> r >> d >> s;
        arr.push_back({name, 2*r + 3*d + s});
    }

    std::sort(arr.begin(), arr.end());
    if (arr.size() >= 1)
        std::cout << arr[0].name << '\n';
    if (arr.size() >= 2)
        std::cout << arr[1].name << '\n';
    
    return 0;
}
