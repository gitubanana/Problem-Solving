class Solution {
public:

    bool canFinish(int vCnt, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edges(vCnt);
        vector<int> indegree(vCnt, 0);

        for (vector<int> &edge : prerequisites) {
            edges[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        int doneCnt = 0;

        for (int v = 0; v < vCnt; v++) {
            if (indegree[v] == 0) {
                q.push(v);
                doneCnt++;
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (const int &next : edges[cur]) {
                if (--indegree[next] == 0) {
                    q.push(next);
                    doneCnt++;
                }
            }
        }

        return doneCnt == vCnt;
    }
};