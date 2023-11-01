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
        Compare   comp;
        Container container;

    public:
        void    push(const T &to_push)
        {
            container.push_back(to_push);

            size_t  child_idx = container.size() - 1;
            while (child_idx > 0)
            {
                size_t  parent_idx = (child_idx - 1) / 2;
                T       &child = container[child_idx];
                T       &parent = container[parent_idx];

                if (comp(child, parent))
                    break ;

                std::swap(child, parent);
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
            size_t  container_size = container.size();
            while (child_idx < container_size)
            {
                size_t  sibling_idx = child_idx + 1;
                if (sibling_idx < container_size
                    && comp(container[child_idx], container[sibling_idx]))
                    child_idx = sibling_idx;

                T   &parent = container[parent_idx];
                T   &child = container[child_idx];

                if (comp(child, parent))
                    break ;

                std::swap(child, parent);
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
