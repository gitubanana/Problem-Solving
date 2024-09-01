#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

enum e_pos
{
    X = 0,
    Y
};

enum e_idx
{
    PRE = 0,
    POST
};

struct t_pos
{
    int y, x;
    int num;
};

const int MAX_V = 1e4 + 1;

vector<vector<int>> answer(2, vector<int>());
vector<t_pos> map;

int getRootIdx(const vector<int> &tree)
{
    int rootIdx;
    int maxY = -1;

    for (const int &idx : tree)
    {
        const int &cmpY = map[idx].y;

        if (maxY < cmpY)
        {
            maxY = cmpY;
            rootIdx = idx;
        }
    }

    return (rootIdx);
}

void    makeTree(const vector<int> &tree)
{
    if (tree.empty())
        return ;

    int rootIdx = getRootIdx(tree);
    const t_pos &root = map[rootIdx];
    vector<int> leftTree, rightTree;

    answer[PRE].push_back(root.num);
    for (const int &idx : tree)
    {
        const t_pos &cmp = map[idx];
        if (idx == rootIdx)
            continue ;

        if (root.x < cmp.x)
        {
            rightTree.push_back(idx);
        }
        else
        {
            leftTree.push_back(idx);
        }
    }
    makeTree(leftTree);
    makeTree(rightTree);
    answer[POST].push_back(root.num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    int num = 0;
    vector<int> tree;

    for (const vector<int> &node : nodeinfo)
    {
        tree.push_back(num++);
        map.push_back({node[Y], node[X], num});
    }

    makeTree(tree);
    return answer;
}
