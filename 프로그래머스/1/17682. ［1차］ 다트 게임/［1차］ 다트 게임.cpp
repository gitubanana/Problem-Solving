#include <string>
#include <iostream>
#include <vector>
#include <cstring>

int solution(std::string str) {
    static const int DART_CNT = 3;

    int idx = 0;
    int score[DART_CNT + 1];

    memset(score, 0, sizeof(score));
    for (int cur = 1; cur <= DART_CNT; ++cur)
    {
        int &num = score[cur];

        while (std::isdigit(str[idx]))
        {
            num = num * 10 + (str[idx] - '0');
            ++idx;
        }

        switch (str[idx])
        {
            case 'T':
                num = num * num * num;
                break ;
            case 'D':
                num = num * num;
                break ;
        }

        switch (str[++idx])
        {
            case '*':
                num *= 2;
                score[cur - 1] *= 2;
                ++idx;
                break;
            case '#':
                num *= -1;
                ++idx;
                break;
        }
    }

    int answer = 0;
    for (int i = 1; i <= DART_CNT; ++i)
    {
        std::cout << score[i] << ' ';
        answer += score[i];
    }
    return answer;
}