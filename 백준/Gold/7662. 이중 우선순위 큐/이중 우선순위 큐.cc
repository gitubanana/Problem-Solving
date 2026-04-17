#include <iostream>
#include <queue>
#include <map>

enum e_cmd
{
    INSERT = 'I',
    DELETE = 'D'
};

typedef std::priority_queue<int,
            std::vector<int>, std::less<int> > max_heap_t;
typedef std::priority_queue<int,
            std::vector<int>, std::greater<int> > min_heap_t;
typedef std::map<int, int> map_t;

void    insert(min_heap_t &min_heap, max_heap_t &max_heap,
               map_t &map, int num)
{
    max_heap.push(num);
    min_heap.push(num);
    ++map[num];
}

void    _delete(min_heap_t &min_heap, max_heap_t &max_heap,
               map_t &map, int is_max)
{
    int  top_value;
    bool is_empty = true;

    if (is_max == 1)
    {
        while (!max_heap.empty())
        {
            top_value = max_heap.top(), max_heap.pop();
            if (map[top_value] > 0 && !(is_empty = false))
                break ;
        }
    }
    else
    {
        while (!min_heap.empty())
        {
            top_value = min_heap.top(), min_heap.pop();
            if (map[top_value] > 0 && !(is_empty = false))
                break ;
        }
    }
    if (!is_empty)
        --map[top_value];
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    char cmd;
    int  test_cnt, cmd_cnt, num;

    std::cin >> test_cnt;
    while (test_cnt--)
    {
        std::cin >> cmd_cnt;

        min_heap_t min_heap;
        max_heap_t max_heap;
        map_t      map;
        while (cmd_cnt--)
        {
            std::cin >> cmd >> num;
            switch (cmd)
            {
                case INSERT:
                    insert(min_heap, max_heap, map, num);
                    break ;
                case DELETE:
                    _delete(min_heap, max_heap, map, num);
                    break ;
            }
        }

        // min_heap, max_heap 출력.
        int  min_top, max_top;
        bool is_empty = true;

        while (!max_heap.empty())
        {
            max_top = max_heap.top(), max_heap.pop();
            if (map[max_top] > 0 && !(is_empty = false))
                break ;
        }

        while (!min_heap.empty())
        {
            min_top = min_heap.top(), min_heap.pop();
            if (map[min_top] > 0 && !(is_empty = false))
                break ;
        }

        if (is_empty)
            std::cout << "EMPTY" << '\n';
        else
            std::cout << max_top << ' ' << min_top << '\n';
    }
    return (0);
}
