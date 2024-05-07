#include <iostream>
#include <queue>

struct t_msg
{
    int emojiCnt;
    int clipboard;
};

typedef std::queue<t_msg> t_queue;
typedef bool (*t_func)(const t_msg &);

const int MAX = 1024;

int goal;
bool visited[MAX + 1][MAX + 1];
std::queue<t_msg> q;

bool    saveClipboard(const t_msg &cur)
{
    if (!visited[cur.emojiCnt][cur.emojiCnt])
    {
        visited[cur.emojiCnt][cur.emojiCnt] = true;
        q.push({cur.emojiCnt, cur.emojiCnt});
    }
    return (false);
}

bool copyClipboard(const t_msg &cur)
{
    int nextEmoji = cur.emojiCnt + cur.clipboard;
    if (nextEmoji > MAX)
        return (false);

    if (visited[nextEmoji][cur.clipboard])
        return (false);

    if (nextEmoji == goal)
        return (true);

    visited[nextEmoji][cur.clipboard] = true;
    q.push({nextEmoji, cur.clipboard});
    return (false);
}

bool deleteEmoji(const t_msg &cur)
{
    int nextEmoji = cur.emojiCnt - 1;
    if (nextEmoji < 1)
        return (false);

    if (visited[nextEmoji][cur.clipboard])
        return (false);

    if (nextEmoji == goal)
        return (true);

    visited[nextEmoji][cur.clipboard] = true;
    q.push({nextEmoji, cur.clipboard});
    return (false);
}

int bfs(void)
{
    static t_func funcs[] = {&copyClipboard, &saveClipboard, &deleteEmoji};

    if (goal == 1)
        return (0);

    int sec = 1;

    visited[1][0] = true;
    q.push({1, 0});
    while (!q.empty())
    {
        int qSize = q.size();

        while (qSize--)
        {
            const t_msg cur = q.front();

            for (int i = 0; i < 3; ++i)
            {
                if ((funcs[i])(cur))
                    return sec;
            }
            q.pop();
        }
        ++sec;
    }
    return (-1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> goal;
    std::cout << bfs() << '\n';
    return (0);
}
