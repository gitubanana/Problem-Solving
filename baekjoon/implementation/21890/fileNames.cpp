#include <iostream>

inline bool canTransfer(const std::string &file)
{
    int nameEnd = 0;

    while (file[nameEnd] && nameEnd < 8)
    {
        const char &cur = file[nameEnd];
        if (cur == '.')
            break ;

        if (!std::islower(cur))
            return (false);

        ++nameEnd;
    }

    if (file[nameEnd] != '.' || nameEnd == 0)
        return (false);

    int extEnd = 1;
    while (file[nameEnd + extEnd] && extEnd < 4)
    {
        if (!std::islower(file[nameEnd + extEnd]))
            return (false);

        ++extEnd;
    }

    return (!file[nameEnd + extEnd] && 1 < extEnd);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    std::string file;
    int canTransferCnt = 0;

    std::cin >> testCnt;
    while (testCnt--)
    {
        std::cin >> file;
        canTransferCnt += canTransfer(file);
    }

    std::cout << canTransferCnt << '\n';
    return (0);
}
