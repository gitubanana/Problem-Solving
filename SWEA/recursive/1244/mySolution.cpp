#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

// *** 처음 풀 때 생각 ***
// 결국에, 최대 수를 만들고 남은 횟수만큼 마지막 자리 수 둘이 바꾸면 되지 않을까?

// - 최대 수와 0번 인덱스부터 비교하다가 다른 곳이 있으면,
//    그 곳을 그 뒤에 있는 최댓값과 swap
//    - 만약에 최댓값이 여러 개라면 => 각 부분을 바꿨을 때 완전 탐색
// - 최대 수를 만들었다면
//    - 만약에 똑같은 수가 있다면 => 계속 둘만 바꿔 최대 수를 만들 수 있으므로 안 바꾸고 저장
//    - 아니라면 => 마지막 자릿 수 둘이 계속 바꾸기

int maxFreq;
int freq[10];
std::string result;
std::string maxNum;

inline int getSwapIdx(const std::string &num)
{
    for (int i = 0; i < num.size(); ++i)
    {
        if (num[i] != maxNum[i])
        {
            return (i);
        }
    }

    return (-1);
}

void    swapToMax(std::string &num, int swapCnt)
{
    while (swapCnt)
    {
        int swapIdx = getSwapIdx(num);
        if (swapIdx == -1)
            break ;

        --swapCnt;
        char max = 0;
        std::vector<int> sameMax;
        for (int i = swapIdx + 1; i < num.size(); ++i)
        {
            char &cmp = num[i];

            if (max < cmp)
            {
                sameMax.clear();
                sameMax.push_back(i);
                max = cmp;
            }
            else if (max == cmp)
            {
                sameMax.push_back(i);
            }
        }

        for (int i = 1; i < sameMax.size(); ++i)
        {
            std::string next = num;

            std::swap(next[swapIdx], next[sameMax[i]]);
            swapToMax(next, swapCnt);
        }

        std::swap(num[swapIdx], num[sameMax[0]]);
    }

    if (maxFreq == 1 && (swapCnt & 1))
    {
        std::swap(num[num.size() - 1], num[num.size() - 2]);
    }

    result = std::max(result, num);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    for (int t = 1; t <= testCnt; ++t)
    {
        int swapCnt;
        std::string num;
        std::cin >> num >> swapCnt;

        memset(freq, 0, sizeof(freq));
        for (const char &ch : num)
        {
            ++freq[ch - '0'];
        }
        maxFreq = *std::max_element(freq, freq + 10);

        result.clear();
        maxNum = num;
        std::sort(maxNum.begin(), maxNum.end(), std::greater<char>());

        swapToMax(num, swapCnt);
        std::cout << '#' << t << ' ' << result << '\n';
    }
    return (0);
}
