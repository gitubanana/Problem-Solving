#include <iostream>
#include <algorithm>
#include <queue>

struct t_elem
{
    int deadLine;
    int reward;

    inline bool operator<(const t_elem &other) const
    {
        return (this->deadLine < other.deadLine);
    }
};

const int MAX = 200000;

t_elem arr[MAX];

inline std::istream &operator>>(std::istream &in, t_elem &elem)
{
    in >> elem.deadLine >> elem.reward;
    return (in);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    std::sort(arr, arr + size);

    std::priority_queue<int, std::vector<int>, std::greater<int> > pq;

    for (int i = 0; i < size;)
    {
        pq.push(arr[i].reward);

        int &curDeadLine = arr[i].deadLine;
        while (++i < size)
        {
            if (curDeadLine != arr[i].deadLine)
                break;
            pq.push(arr[i].reward);
        }

        while (pq.size() > curDeadLine)
        {
            pq.pop();
        }
    }

    int ans = 0;
    while (!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }

    std::cout << ans << '\n';
    return (0);
}
