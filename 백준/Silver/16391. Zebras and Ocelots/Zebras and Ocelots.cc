#include <iostream>

const int MAX_SIZE = 60;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    int64_t bellCnt = 0;

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        char ch;

        std::cin >> ch;
        bellCnt = (bellCnt << 1) | (ch == 'O');
    }

    std::cout << bellCnt << '\n';
    return (0);
}
