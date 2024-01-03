#include <iostream>
#include <deque>

typedef std::deque<int> t_deque;

class Logger
{
    private:
        t_deque left, right;

    public:
        void    take_input(char ch)
        {
            switch (ch)
            {
            case '<':
                if (!left.empty())
                {
                    right.push_front(left.back());
                    left.pop_back();
                }
                break ;
            case '>':
                if (!right.empty())
                {
                    left.push_back(right.front());
                    right.pop_front();
                }
                break ;
            case '-':
                if (!left.empty())
                    left.pop_back();
                break ;
            default:
                left.push_back(ch);
            }
        }

        std::string output(void)
        {
            return std::string(left.begin(), left.end())
                    + std::string(right.begin(), right.end());
        }
};

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    std::string input;

    std::cin >> testCnt;
    while (testCnt)
    {
        std::cin >> input;

        Logger vscode;
        for (const char &ch : input)
            vscode.take_input(ch);

        std::cout << vscode.output() << '\n';
        --testCnt;
    }
    return (0);
}
