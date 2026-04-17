#include <iostream>
#include <cstring>

int    cnt[26];

bool    is_anagram(std::string &s1, std::string &s2)
{
    for (char &ch : s1)
        ++cnt[ch - 'a'];
    for (char &ch : s2)
        --cnt[ch - 'a'];
    for (int i = 0; i < 26; ++i)
        if (cnt[i] != 0)
            return (false);
    return (true);
}

int    main(void)
{
    int    i, test_cnt;
    std::string    s1, s2;

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> test_cnt;
    while (test_cnt)
    {
        std::cin >> s1 >> s2;
        memset(cnt, 0, sizeof(cnt));
        std::cout << s1 << " & " << s2 << " are ";
        if (!is_anagram(s1, s2))
            std::cout << "NOT ";
        std::cout << "anagrams." << '\n';
        --test_cnt;
    }
    return (0);
}