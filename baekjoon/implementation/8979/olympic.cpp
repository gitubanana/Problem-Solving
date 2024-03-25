#include <iostream>
#include <algorithm>

struct t_medal
{
    int medals[3];
    int num;

    inline bool operator<(const t_medal &other) const
    {
        for (int i = 0; i < 3; ++i)
        {
            if (this->medals[i] < other.medals[i])
                return true;
            else if (this->medals[i] > other.medals[i])
                return false;
        }
        return false;
    }
};

const int MAX = 1000;

int size;
t_medal arr[MAX];

inline std::istream &operator>>(std::istream &in, t_medal &input)
{
    in >> input.num;
    for (int i = 0; i < 3; ++i)
    {
        std::cin >> input.medals[i];
    }
    return (in);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int countryNum;
    t_medal *country;

    std::cin >> size >> countryNum;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
        if (countryNum == arr[i].num)
            country = &arr[i];
    }

    int rank = 1;

    for (int i = 0; i < size; ++i)
    {
        if (*country < arr[i])
            ++rank;
    }

    std::cout << rank << '\n';
    return (0);
}
