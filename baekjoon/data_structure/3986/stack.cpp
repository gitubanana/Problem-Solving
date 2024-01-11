#include <iostream>
#include <stack>

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    int word_cnt;
    int good_cnt = 0;
    std::string word;

    std::cin >> word_cnt;
    while (word_cnt--)
    {
        std::stack<char> stack_;

        std::cin >> word;
        stack_.push(word[0]);
        for (int i = 1; word[i]; ++i)
        {
            char &ch = word[i];

            if (!stack_.empty()
                && stack_.top() == ch)
                stack_.pop();
            else
                stack_.push(ch);
        }

        good_cnt += (stack_.empty());
    }
    std::cout << good_cnt << '\n';
    return 0;
}
