#include <iostream>
#include <deque>
#include <sstream>
#include <vector>
#include <climits>

enum e_cmd
{
    REVERSE = 'R',
    DROP = 'D'
};

struct t_ac_deque
{
    private:
        bool    is_reversed;
        std::deque<int> _deque;
    public:
        t_ac_deque(void) : is_reversed(false) { }
        
        void    reverse(void)
        {
            is_reversed = !is_reversed;
        }

        void    drop(void)
        {
            if (_deque.empty())
                throw std::string("error");
            if (!is_reversed)
                _deque.pop_front();
            else
                _deque.pop_back();
        }

        void    parse_data(std::string &to_parse)
        {
            // parse data by using sstream
            int num;
            std::string num_str;
            std::stringstream    ss(&to_parse[1]);

            while (std::getline(ss, num_str, ','))
            {
                std::stringstream    num_ss(num_str);

                num_ss >> num;
                _deque.push_back(num);
            }
        }

        void    print_data(void)
        {
            int num;
            std::string to_print;

            std::cout << '[';
            for (int i = 0; i < _deque.size(); ++i)
            {
                if (!is_reversed)
                    num = _deque[i];
                else
                    num = _deque[_deque.size() - i - 1];
                std::cout << num;
                if (i != _deque.size() - 1)
                    std::cout << ',';
            }
            std::cout << to_print << "]\n";
        }
};

void    do_command(std::string &cmd, t_ac_deque &_deque)
{
    for (int i = 0; i < cmd.size(); ++i)
    {
        if (cmd[i] == DROP)
            _deque.drop();
        else
            _deque.reverse();
    }
}

int main()
{
    int test_cnt, num_cnt;
    std::string cmd, to_parse;

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::cin >> test_cnt;
    while (test_cnt--)
    {
        std::cin >> cmd >> num_cnt >> to_parse;

        t_ac_deque _deque;

        if (num_cnt > 0)
            _deque.parse_data(to_parse);
        try
        {
            do_command(cmd, _deque);
            _deque.print_data();
        }
        catch (const std::string &error_msg)
        {
            std::cout << error_msg << '\n';
        }
    }
    return 0;
}
