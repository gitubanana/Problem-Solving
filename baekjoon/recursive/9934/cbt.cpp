#include <iostream>
#include <cmath>

int lastLevelNode;
int *tree, treeSize;

void    recursive(int cur)
{
    if (cur >= lastLevelNode)
    {
        std::cin >> tree[cur];
        return ;
    }

    int leftChild = cur * 2 + 1;

    recursive(leftChild);
    std::cin >> tree[cur];
    recursive(leftChild + 1);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    std::cin >> size;

    treeSize = pow(2, size) - 1;
    tree = new int[treeSize];

    int two = 1;
    for (int i = 1; i < size; ++i)
    {
        lastLevelNode += two;
        two *= 2;
    }

    recursive(0);

    two = 2;
    int endline = 0;
    for (int i = 0; i < treeSize; ++i)
    {
        std::cout << tree[i] << ' ';
        if (i == endline)
        {
            std::cout << '\n';
            endline += two;
            two *= 2;
        }
    }

    delete[] tree;
    return (0);
}
