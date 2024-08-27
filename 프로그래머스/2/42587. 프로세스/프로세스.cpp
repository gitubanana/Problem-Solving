#include <string>
#include <vector>
#include <deque>

using namespace std;

int getMax(std::deque<int> &q)
{
    int max = 0;

    for (const int &cmp : q)
    {
        max = std::max(max, cmp);
    }
    return (max);
}

int solution(vector<int> prior, int location) {
    int answer = 0;
    std::deque<int> q(prior.begin(), prior.end());

    while (true)
    {
        int front = q.front();
        q.pop_front();

        int max = getMax(q);
        if (front < max)
        {
            q.push_back(front);
            if (location == 0)
                location = q.size();
        }
        else
        {
            ++answer;
            if (location == 0)
                return (answer);
        }

        --location;
    }

    return answer;
}