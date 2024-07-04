#include <iostream>
#include <deque>

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int size;
    std::deque<int> line, backstreet;

    std::cin >> size;
    for (int i = 0; i < size; ++i)
    {
        int student;

        std::cin >> student;
        line.push_back(student);
    }


    int come = 1;
    for (; come <= size; ++come)
    {
        if (!backstreet.empty() && backstreet.front() == come)
        {
            backstreet.pop_front();
        }
        else
        {
            while (!line.empty())
            {
                if (line.front() == come)
                    break ;

                backstreet.push_front(line.front());
                line.pop_front();
            }

            if (line.empty())
                break ;

            line.pop_front();
        }
    }

    std::cout << (come <= size ? "Sad" : "Nice") << '\n';
    return (0);
}
