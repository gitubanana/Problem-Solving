#include <iostream>
#include <unordered_set>

enum e_prev
{
    A = 0,
    B,
    C
};

const int MAX_SIZE = 50;
const int CHAR_TYPE = 3;

int depthLimit;
int cnt[CHAR_TYPE];
bool dp[MAX_SIZE][MAX_SIZE][MAX_SIZE][3][3];
char str[MAX_SIZE + 1];

void    dfs(int a, int b, int c, int prev=A, int pPrev=A, int depth=0)
{
    if (depth == depthLimit)
    {
        str[depth + 1] = 0;
        std::cout << str << '\n';
        exit(0);
    }

    bool &curDp = dp[a][b][c][prev][pPrev];
    if (curDp)
        return ;

    curDp = true;

    str[depth] = 'A';
    if (a > 0)
    {
        dfs(a - 1, b, c, A, prev, depth + 1);
    }

    str[depth] = 'B';
    if (b > 0 && prev != B)
    {
        dfs(a, b - 1, c, B, prev, depth + 1);
    }

    str[depth] = 'C';
    if (c > 0 && prev != C && pPrev != C)
    {
        dfs(a, b, c - 1, C, prev, depth + 1);
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::string record;
    std::cin >> record;

    depthLimit = record.size();
    for (const char &ch : record)
    {
        ++cnt[ch - 'A'];
    }

    dfs(cnt[0], cnt[1], cnt[2]);
    std::cout << "-1" << '\n';
    return (0);
}
