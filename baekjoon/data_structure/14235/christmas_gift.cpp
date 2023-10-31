#include <iostream>
#include <vector>
#include <functional>

//                 arr[i]
//               /       |
//     arr[i * 2 + 1]    arr[i * 2 + 2]
template <typename T, typename Container = std::vector<T>,
          typename Compare = std::less<T> >
class priority_queue
{
    private:
        Container container;

    public:
        void    push(const T &to_push)
        {
            container.push_back(to_push);

            size_t  child_idx = container.size() - 1;
            while (child_idx > 0)
            {
                size_t  parent_idx = (child_idx - 1) / 2;

                if (Compare()(container[child_idx], container[parent_idx]))
                    break ;

                std::swap(container[child_idx], container[parent_idx]);
                child_idx = parent_idx;
            }
        }

        void    print_top(void)
        {
            if (container.empty())
                std::cout << "-1\n";
            else
                std::cout << container[0] << '\n';
        }

        void    pop(void)
        {
            if (container.empty())
                return ;

            container[0] = container[container.size() - 1];
            container.pop_back();

            size_t  parent_idx = 0;
            size_t  child_idx = 1;
            while (child_idx < container.size())
            {
                if (Compare()(container[child_idx], container[child_idx + 1]))
                    ++child_idx;

                if (Compare()(container[child_idx], container[parent_idx]))
                    break ;

                std::swap(container[child_idx], container[parent_idx]);
                parent_idx = child_idx;
                child_idx = child_idx * 2 + 1;
            }
        }
};

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    priority_queue<int> pq;
    int                 n, gift_cnt, gift;

    std::cin >> n;
    while (n--)
    {
        std::cin >> gift_cnt;
        if (gift_cnt == 0)
            pq.print_top(), pq.pop();
        else
        {
            while (gift_cnt--)
                std::cin >> gift, pq.push(gift);
        }
    }

    return (0);
}
