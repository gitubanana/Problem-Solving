#include <iostream>
#include <vector>

const int MAX_N = 1'000'000;

bool isNotPrime[MAX_N];

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    for (int step = 2; step < MAX_N; ++step)
    {
        if (isNotPrime[step])
            continue ;

        for (int num = step + step; num < MAX_N; num += step)
        {
            isNotPrime[num] = true;
        }
    }

    while (true)
    {
        int goal;

        std::cin >> goal;
        if (goal == 0)
            break ;

        int i = 3;
        int halfGoal = goal / 2;
        while (i <= halfGoal)
        {
            if (!isNotPrime[i] && !isNotPrime[goal - i])
                break ;

            i += 2;
        }


        if (i == halfGoal + 1)
        {
            std::cout << "Goldbach\'s conjecture is wrong." << '\n';
        }
        else
        {
            std::cout << goal << " = " << i << " + " << goal - i << '\n';
        }
    }
    return (0);
}
