#include <iostream>

const int MAX = 100;

char name[MAX + 2];
char toPrint[MAX * 2 + 1];

void    change(void)
{
    int idx = 0;
    bool isCpp = false;
    bool isJava = false;

    if (isupper(name[0]) || name[0] == '_')
        throw std::runtime_error("first upper");

    for (int i = 0; name[i]; ++i)
    {
        const char &cur = name[i];

        if (cur == '_')
        {
            isJava = true;

            const char &next = name[++i];
            if (!('a' <= next && next <= 'z'))
                throw std::runtime_error("not lower");

            toPrint[idx++] = toupper(next);
        }
        else if ('A' <= cur && cur <= 'Z')
        {
            isCpp = true;

            toPrint[idx++] = '_';
            toPrint[idx++] = tolower(cur);
        }
        else
        {
            toPrint[idx++] = cur;
        }

        if (isCpp && isJava)
            throw std::runtime_error("cpp + java");
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> name;

    try
    {
        change();
        std::cout << toPrint << '\n';
    }
    catch(const std::exception& e)
    {
        // std::cerr << e.what() << '\n';
        std::cout << "Error!" << '\n';
    }
    return (0);
}
