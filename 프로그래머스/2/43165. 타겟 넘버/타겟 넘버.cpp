#include <string>
#include <vector>

using namespace std;

int answer;

void    dfs(vector<int> &numbers, int target, int curNum=0, int depth=0)
{
    if (depth == numbers.size())
    {
        answer += (curNum == target);
        return ;
    }

    dfs(numbers, target, curNum + numbers[depth], depth + 1);
    dfs(numbers, target, curNum - numbers[depth], depth + 1);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target);
    return answer;
}