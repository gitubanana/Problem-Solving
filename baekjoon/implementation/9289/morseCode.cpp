#include <iostream>
#include <unordered_map>

using t_umap = std::unordered_map<std::string, char>;

t_umap morseCode({
    {".-", 'A'},
    {"-...", 'B'},
    {"-.-.", 'C'},
    {"-..", 'D'},
    {".", 'E'},
    {"..-.", 'F'},
    {"--.", 'G'},
    {"....", 'H'},
    {"..", 'I'},
    {".---", 'J'},
    {"-.-", 'K'},
    {".-..", 'L'},
    {"--", 'M'},
    {"-.", 'N'},
    {"---", 'O'},
    {".--.", 'P'},
    {"--.-", 'Q'},
    {".-.", 'R'},
    {"...", 'S'},
    {"-", 'T'},
    {"..-", 'U'},
    {"...-", 'V'},
    {".--", 'W'},
    {"-..-", 'X'},
    {"-.--", 'Y'},
    {"--..", 'Z'}
});

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        int letterCnt = 5;
        std::string word;

        while (letterCnt--)
        {
            std::string code;

            std::cin >> code;
            word.push_back(morseCode[code]);
        }

        std::cout << "Case " << t << ": " << word << '\n';
    }
    return (0);
}
