#include <iostream>

int main()
{
    size_t  bomb_pos;
    std::string str, bomb;
    std::string stack;

    std::cin >> str >> bomb;
    for (int i = 0; i < str.size(); ++i)
    {
        stack += str[i];
        if (stack.size() >= bomb.size()
            && stack.back() == bomb.back())
        {
            bomb_pos = stack.size() - bomb.size();
            if (stack.substr(bomb_pos, bomb.size()) == bomb)
                stack.erase(bomb_pos, bomb.size());
        }
    }
    std::cout << ((stack == "") ? "FRULA" : stack) << '\n';
    return 0;
}
