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

        const   T&top(void)
        {
            return (container[0]);
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

//    중간값을 기준으로
//    /         |
// max_heap   max_heap

priority_queue<int> left;
priority_queue<int, std::vector<int>, std::greater<int>> right;

void    print_middle(int size, int to_push)
{
    if (size == 1)
    {
        left.push(to_push);
        right.push(to_push);
    }
    else
    {
        const int   left_top = left.top();

        if (to_push > left_top)
        {
            if (size & 1)
                right.pop(), left.push(to_push);
            right.push(to_push);
            if (left.top() != right.top())
                left.pop(), left.push(right.top());
        }
        else
        {
            if (!(size & 1))
                left.pop(), right.push(to_push);
            left.push(to_push);
            if (left.top() != right.top())
                right.pop(), right.push(left.top());
        }
    }
    std::cout << left.top() << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size, num;

    std::cin >> size;
    for (int cnt = 1; cnt <= size; ++cnt)
    {
        std::cin >> num;
        print_middle(cnt, num);
    }
    return (0);
}
