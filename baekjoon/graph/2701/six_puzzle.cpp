#include <iostream>
#include <queue>
#include <map>

int ALL_1 = 0b1111111111111111111111;
int DATA_BIT = 3;
int FIRST_3_1 = 0b0111;
int FIRST_3_0 = 0b1111111111111111111000;
int chToInt[] = {1, 2, 3, 4, 5, 6};
const char *intToCh = "0ABCDEF";

void    print_bits(int num)
{
    int pos = 0;

    for (int i = 0; i < 7; ++i) {
        std::cout << intToCh[((num >> pos) & FIRST_3_1)];
        pos += DATA_BIT;
    }
    std::cout << '\n';
}

struct t_puzzle
{
    static const int EMPTY = 0;
    static const int SIZE = 7;
    static const int LAST_POS = 18;

    int map;
    int emptyPos;

    t_puzzle(void) : map(0), emptyPos(LAST_POS) {
        int cnt = 0;
        int pos = 0;

        for (int i = 1; i < SIZE; ++i) {
            map |= (++cnt << pos);
            pos += DATA_BIT;
        }
        // print_bits(map);
    }

    t_puzzle(std::string &str) : map(0), emptyPos(LAST_POS) {
        int pos = 0;

        for (const char &ch : str) {
            map |= (chToInt[ch - 'A'] << pos);
            pos += DATA_BIT;
        }
        // print_bits(map);
    }

    int getEmptyPos(int idx) {
        static int nextEmptyPos[][3] = {
            {3, 15, -1},
            {6, 18, 0},
            {3, 9, -1},
            {6, 12, -1},
            {9, 15, 18},
            {12, 0, -1},
            {12, 3, -1}
        };
        return nextEmptyPos[emptyPos / 3][idx];
    }

    int    swap_empty(int idx) {
        int nextEmptyPos = getEmptyPos(idx);
        if (nextEmptyPos == -1)
            return (-1);

        int a = (map >> nextEmptyPos) & FIRST_3_1;

        // 0 표시하기
        map &= ((FIRST_3_1 << nextEmptyPos) ^ ALL_1);

        // a 표시하기
        map |= (a << emptyPos);

        emptyPos = nextEmptyPos;
        return (a);
    }
};

void bfs(t_puzzle &start, t_puzzle &end)
{
    typedef std::map<int, int> t_map;

    if (start.map == end.map)
    {
        std::cout << "0";
        return ;
    }

    std::queue<t_puzzle> q;
    t_map                cnt;
    std::map<int, std::string> _str;

    q.push(start), cnt[start.map] = 0;
    _str[start.map] = "";
    while (!q.empty())
    {
        t_puzzle &cur = q.front();
        int      &cur_cnt = cnt[cur.map];

        for (int i = 0; i < 3; ++i)
        {
            t_puzzle next = cur;

            int idx = next.swap_empty(i);
            if (idx == -1)
                continue ;

            char swapped_ch = intToCh[idx];

            if (next.map == end.map)
            {
                std::cout << cur_cnt + 1 << ' ' << _str[cur.map] << swapped_ch;
                return ;
            }

            t_map::iterator it = cnt.find(next.map);
            if (it == cnt.end())
            {
                cnt[next.map] = cur_cnt + 1;
                _str[next.map] = _str[cur.map] + swapped_ch;
                q.push(next);
            }
        }
        q.pop();
    }

    std::cout << "-1";
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::string str;
    t_puzzle    end;
    int         test_cnt;

    std::cin >> test_cnt;
    while (test_cnt--)
    {
        std::cin >> str;
        t_puzzle start(str);

        bfs(start, end);
        std::cout << '\n';
    }
    return (0);
}
