#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

enum e_idx
{
    LEFT = 0,
    RIGHT
};

enum e_pos
{
    X = 0,
    Y
};

struct t_pos
{
    int y, x;
    int num;

    inline bool operator<(const t_pos &other)
    {
        if (this->y == other.y)
            return (this->x > other.x);

        return (this->y > other.y);
    }
};

const int MAX_V = 1e4 + 1;
const int ROOT = 0;

int child[MAX_V][2];
vector<vector<int>> answer(2, vector<int>());
vector<t_pos> map;

void    insertNode(int putIdx, int cmpIdx=ROOT)
{
    const t_pos &cmp = map[cmpIdx];
    const t_pos &put = map[putIdx];

    int &nextCmp = child[cmpIdx][(cmp.x < put.x)];
    if (nextCmp == 0)
    {
        nextCmp = putIdx;
        return ;
    }

    insertNode(putIdx, nextCmp);
}

void    preorder(int cur, vector<int> &order)
{
    order.push_back(map[cur].num);
    for (int i = LEFT; i <= RIGHT; ++i)
    {
        const int &next = child[cur][i];
        if (next == 0)
            continue ;

        preorder(next, order);
    }
}

void    postorder(int cur, vector<int> &order)
{
    for (int i = LEFT; i <= RIGHT; ++i)
    {
        const int &next = child[cur][i];
        if (next == 0)
            continue ;

        postorder(next, order);
    }
    order.push_back(map[cur].num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    int num = 1;
    for (const vector<int> &vec : nodeinfo)
    {
        map.push_back({vec[Y], vec[X], num++});
    }
    std::sort(map.begin(), map.end());

    for (int i = 1; i < map.size(); ++i)
    {
        insertNode(i);
    }

    preorder(ROOT, answer[0]);
    postorder(ROOT, answer[1]);
    return answer;
}
