#include <iostream>
#include <queue>
#include <unordered_map>

int dd[] = {-4, -12, 4, 12};
int minus[] = {0, 0, 8};
int64_t ALL_1 = 68719476735;
int64_t FIRST_4_1 = 15;
int64_t FIRST_4_0 = 68719476720;

// void    print_bits(int64_t num)
// {
//     int64_t pos = 0;

//     for (int i = 0; i < 9; ++i) {
//         std::cout << ((num >> pos) & FIRST_4_1) << ' ';
//         pos += 4;
//         if ((i + 1) % 3 == 0)
//             std::cout << '\n';
//     }
// }

struct t_puzzle
{
    static const int EMPTY = 0;
    static const int SIZE = 9;

    int64_t map;
    int     empty_pos;

    t_puzzle(void) : map(0), empty_pos(32) {
        int64_t cnt = 0;
        int64_t pos = 0;

        for (int i = 1; i < SIZE; ++i) {
            map |= (++cnt << pos);
            pos += 4;
        }
        // print_bits(map);
    }

    t_puzzle(std::istream &in) : map(0), empty_pos(0) {
        int64_t pos = 0;
        int64_t input;

        for (int i = 0; i < SIZE; ++i) {
            in >> input;
            map |= (input << pos);
            pos += 4;
        }
        // print_bits(map);
    }

    inline bool operator==(const t_puzzle &other) const {
        return (map == other.map);
    }

    void    swap_empty(const int next_E) {
        int64_t a = (map >> next_E) & FIRST_4_1;

        // 0 표시하기
        map &= ((FIRST_4_1 << next_E) ^ ALL_1);

        // a 표시하기
        map |= (a << empty_pos);

        empty_pos = next_E;
    }
};

namespace std {
    template <>
    struct hash<t_puzzle> {
        size_t operator()(const t_puzzle& puzzle) const {
            hash<int> hash_func;

            return hash_func(puzzle.map);
        }
    };
}

int bfs(t_puzzle &start, t_puzzle &end)
{
    typedef std::unordered_map<t_puzzle, int> t_umap;

    if (start.map == end.map)
        return (0);

    std::queue<t_puzzle> q;
    t_umap               cnt;

    q.push(start), cnt[start] = 1;
    q.push(end), cnt[end] = -1;
    while (!q.empty())
    {
        t_puzzle &cur = q.front();
        int      &cur_E = cur.empty_pos;
        int       cur_cnt = cnt[cur];

        for (int i = 0; i < 4; ++i)
        {
            t_puzzle next = cur;
            int      next_E = cur_E + dd[i];

            if (!(0 <= next_E && next_E <= 32))
                continue ;

            // 좌일때, 바깥으로 넘어가면
            // 우일때, 바깥으로 넘어가면
            if (i % 2 == 0 && (cur_E - minus[i]) % 12 == 0)
                continue ;

            next.swap_empty(next_E);

            t_umap::iterator it = cnt.find(next);
            if (it == cnt.end())
            {
                cnt[next] = cur_cnt + (cur_cnt > 0 ? 1 : -1);
                q.push(next);
            }
            else if ((cur_cnt > 0) != (it->second > 0))
                return std::abs(it->second) + std::abs(cur_cnt) - 1;
        }
        q.pop();
    }
    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    t_puzzle end;
    t_puzzle start(std::cin);

    std::cout << bfs(start, end) << '\n';
    return (0);
}
