#include <iostream>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>
#include <climits>

struct t_time
{
    int start;
    int end;

    inline bool operator<(const t_time &other) const
    {
        return (this->start < other.start);
    }
};

int size;
std::priority_queue<int, std::vector<int>, std::greater<int> > pq;
std::vector<t_time> arr;

inline std::istream &operator>>(std::istream &in, t_time &input)
{
    in >> input.start >> input.end;
    return (in);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_time input;

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> input;
        arr.push_back(input);
    }

    std::sort(arr.begin(), arr.end());
    pq.push(arr[0].end);
    for (int i = 1; i < arr.size(); ++i)
    {
        const int &nextStartTime = arr[i].start;
        const int &curEndTime = pq.top();

        if (curEndTime <= nextStartTime)
        {
            pq.pop();
        }

        pq.push(arr[i].end);
    }

    std::cout << pq.size() << '\n';
    return (0);
}
