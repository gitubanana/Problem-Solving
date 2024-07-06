#include <iostream>
#include <deque>
#include <vector>
#include <climits>
#include <unordered_map>

struct t_pos
{
    int y, x;
    char ch;
};

using t_dirMap = std::unordered_map<char, std::vector<int>>;

const int MAX_SIZE = 500;
const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
t_dirMap dirMap({
    {'\\', {0, 1, 3, 4, 5, 7}},
    {'/',  {1, 2, 3, 5, 6, 7}}
});

int ySize, xSize;
int cnt[MAX_SIZE + 2][MAX_SIZE + 2];
char map[MAX_SIZE + 2][MAX_SIZE + 2];

inline char changeCh(char ch)
{
    switch (ch)
    {
    case '/':
        return ('\\');
    case '\\':
        return ('/');
    }

    std::cerr << __func__ << " error!" << '\n';
    return ('/');
}

int bfs(void)
{
    int endCnt = INT_MAX;
    std::deque<t_pos> q;

    cnt[0][0] = 1;
    q.push_front({0, 0, '\\'});
    while (!q.empty())
    {
        const t_pos cur = q.front();
        const int &curCnt = cnt[cur.y][cur.x];
        q.pop_front();

        if (curCnt >= endCnt)
            continue ;

        for (const int &dir : dirMap[cur.ch])
        {
            t_pos next = {
                cur.y + dy[dir],
                cur.x + dx[dir],
                (dir & 1 ? changeCh(cur.ch) : cur.ch)
            };

            if (next.y == ySize + 1 && next.x == xSize + 1)
            {
                endCnt = std::min(endCnt, curCnt);
                continue ;
            }

            if (!(1 <= next.y && next.y <= ySize)
                || !(1 <= next.x && next.x <= xSize))
                continue ;

            char &nextSpace = map[next.y][next.x];
            bool rotated = (next.ch != nextSpace);
            int &cmpCnt = cnt[next.y][next.x];
            int nextCnt = curCnt + rotated;

            if (!(cmpCnt == 0 || cmpCnt > nextCnt))
                continue ;

            cmpCnt = nextCnt;
            if (rotated)
            {
                q.push_back(next);
            }
            else
            {
                q.push_front(next);
            }
        }
    }
    return (endCnt - 1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> ySize >> xSize;
    for (int y = 1; y <= ySize; ++y)
    {
        std::cin >> map[y] + 1;
    }

    int changeCnt = bfs();
    if (changeCnt == INT_MAX - 1)
    {
        std::cout << "NO SOLUTION" << '\n';
    }
    else
    {
        std::cout << changeCnt << '\n';
    }
    return (0);
}
