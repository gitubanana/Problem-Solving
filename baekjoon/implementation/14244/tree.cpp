#include <iostream>
#define PRINT_LINE(parent, child) std::cout << (parent) << ' ' << (child) << '\n'

// 1이 루트
// leaf_cnt만큼 1의 자식으로 만듦
// 그래도, n이 남으면 -> leaf_cnt 아래로 넣음

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int root = 1;
    int v_cnt, leaf_cnt;

    std::cin >> v_cnt >> leaf_cnt;

    std::cout << "0 1\n1 2" << '\n';
    for (int v = 3; v <= leaf_cnt; ++v)
    {
        PRINT_LINE(root, v);
    }

    int parent = leaf_cnt;
    for (int v = leaf_cnt + 1; v < v_cnt; ++v)
    {
        PRINT_LINE(parent, v);
        parent = v;
    }

    return (0);
}
