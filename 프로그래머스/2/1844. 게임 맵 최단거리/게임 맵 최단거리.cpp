#include<vector>
#include<queue>
using namespace std;

enum e_space
{
    WALL = 0,
    EMPTY
};

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int ySize, xSize;

struct t_pos
{
    int y, x;

    inline bool operator==(const t_pos &other) const
    {
        return (this->y == other.y && this->x == other.x);
    }
};

inline bool inRange(const t_pos &pos)
{
    return ((0 <= pos.y && pos.y < ySize)
            && (0 <= pos.x && pos.x < xSize));
}

int solution(vector<vector<int> > isEmpty)
{
    static const t_pos start = {0, 0};

    if (!isEmpty[start.y][start.x])
        return (-1);
    
    ySize = isEmpty.size();
    xSize = isEmpty[0].size();
    const t_pos end = {ySize - 1, xSize - 1};
    std::queue<t_pos> q;
    int answer = 1;

    isEmpty[start.y][start.x] = false;
    q.push(start);
    while (!q.empty())
    {
        int qSize = q.size();

        ++answer;
        while (qSize--)
        {
            const t_pos cur = q.front();
            q.pop();

            for (int dir = 0; dir < dirSize; ++dir)
            {
                t_pos next = {
                    cur.y + dy[dir],
                    cur.x + dx[dir]
                };

                if (!inRange(next)
                   || !isEmpty[next.y][next.x])
                    continue ;

                if (next == end)
                    return (answer);

                isEmpty[next.y][next.x] = false;
                q.push(next);
            }
        }
    }
    return (-1);
}