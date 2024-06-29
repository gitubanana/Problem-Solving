#include <iostream>
#include <vector>

enum e_idx
{
    LEFT = 0,
    RIGHT = 1
};

const int MAX_V = 10000;
const int END = -1;

int pos, lastLevel;
int children[MAX_V + 1][2];
std::vector<int> posByLevel[MAX_V];

void    inorder(int cur, int level=0)
{
    if (cur == END)
    {
        return ;
    }

    int &left = children[cur][LEFT];
    int &right = children[cur][RIGHT];
    lastLevel = std::max(lastLevel, level);

    std::vector<int> &curPos = posByLevel[level++];

    inorder(left, level);

    if (curPos.size() == 2)
    {
        curPos.pop_back();
    }
    curPos.push_back(pos++);

    inorder(right, level);
}

void    findLevelAndWidth(int root)
{
    inorder(root);

    int ansLevel, ansWidth = 0;
    for (int level = lastLevel; level >= 0; --level)
    {
        std::vector<int> &curPos = posByLevel[level];
        int curWidth = curPos.back() - curPos[0];

        if (ansWidth <= curWidth)
        {
            ansLevel = level;
            ansWidth = curWidth;
        }
    }

    std::cout << ansLevel + 1 << ' ';
    std::cout << ansWidth + 1 << '\n';
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, parent;

    std::cin >> vCnt;

    int root = vCnt * (vCnt + 1) / 2;
    for (int v = 1; v <= vCnt; ++v)
    {
        std::cin >> parent;

        int &left = children[parent][LEFT];
        int &right = children[parent][RIGHT];

        std::cin >> left >> right;
        root -= (left != END) * left;
        root -= (right != END) * right;
    }

    findLevelAndWidth(root);
    return (0);
}
