#include <string>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

const int MAX_V = 50;

int endIdx = -1, wordsSize;
std::string *strs;
bool visited[MAX_V];
std::queue<int> q;

inline bool oneDifferent(const std::string &a, const std::string &b)
{
    int diff = 0;

    for (int i = 0; a[i]; ++i)
    {
        if (a[i] != b[i])
        {
            if (diff == 1)
                return (false);

            ++diff;
        }
    }

    return (true);
}

bool    findEnd(const std::string &cur)
{
    for (int nextIdx = 0; nextIdx < wordsSize; ++nextIdx)
    {
        if (visited[nextIdx]
            || !oneDifferent(cur, strs[nextIdx]))
            continue ;

        if (nextIdx == endIdx)
            return (true);

        visited[nextIdx] = true;
        q.push(nextIdx);
    }

    return (false);
}

int solution(string begin, string target, vector<string> words) {
    strs = &words[0];
    wordsSize = words.size();
    for (int i = 0; i < wordsSize; ++i)
    {
        if (target == words[i])
        {
            endIdx = i;
            break ;
        }
    }

    if (endIdx == -1)
        return (0);

    int answer = 1;
    if (findEnd(begin))
        return (answer);

    while (!q.empty())
    {
        int qSize = q.size();

        ++answer;
        while (qSize--)
        {
            const int curIdx = q.front();
            const std::string &cur = words[curIdx];
            q.pop();

            if (findEnd(cur))
                return (answer);
        }
    }

    return (0);
}
