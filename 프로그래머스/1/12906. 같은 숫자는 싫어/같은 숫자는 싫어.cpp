#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    int cur = -1;
    vector<int> answer;

    for (const int &cmp : arr)
    {
        if (cur == cmp)
            continue ;

        cur = cmp;
        answer.push_back(cur);
    }

    return answer;
}