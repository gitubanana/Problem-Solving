#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

vector<string> answer;
unordered_map<string, vector<string>> edges;
unordered_map<string, unordered_set<int>> visited;

const int MAX_TICKET = 10000;

int ticketCnt;

bool    backTracking(const string &cur, int used=0)
{
    if (used == ticketCnt)
    {
        return (true);
    }

    int nextIdx = -1;
    vector<string> &curEdges = edges[cur];
    unordered_set<int> &curVisited = visited[cur];
    for (const string &next : curEdges)
    {
        ++nextIdx;
        if (curVisited.find(nextIdx) != curVisited.end())
            continue ;

        answer.push_back(next);
        curVisited.insert(nextIdx);

        if (backTracking(next, used + 1))
            return (true);

        answer.pop_back();
        curVisited.erase(nextIdx);
    }

    return (false);
}

vector<string> solution(vector<vector<string>> tickets) {
    for (vector<string> &toPush : tickets)
    {
        const string &from = toPush[0];
        const string &to = toPush[1];

        edges[from].push_back(to);
    }

    for (pair<const string, vector<string>> &node : edges)
    {
        std::sort(node.second.begin(), node.second.end());
    }

    ticketCnt = tickets.size();
    answer.push_back("ICN");
    backTracking("ICN");
    return answer;
}