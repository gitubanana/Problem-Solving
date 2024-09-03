#include <string>
#include <vector>

using namespace std;

int answer;
int *arr;
int goal;
int depthLimit;

void    dfs(int curNum=0, int depth=0)
{
    if (depth == depthLimit)
    {
        answer += (curNum == goal);
        return ;
    }

    dfs(curNum + arr[depth], depth + 1);
    dfs(curNum - arr[depth], depth + 1);
}

int solution(vector<int> numbers, int target) {
    arr = &numbers[0];
    goal = target;
    depthLimit = numbers.size();
    dfs();
    return answer;
}