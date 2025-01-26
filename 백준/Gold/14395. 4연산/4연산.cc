#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>

const char START = 'S';
const char *OPCODES = "*+-/";

std::unordered_map<long, int> prev;
std::unordered_map<long, char> opCodes;

std::string findPath(int cur) {
    std::string path;

    do {
        path.push_back(opCodes[cur]);
        cur = prev[cur];
    } while (opCodes[cur] != START);

    std::reverse(path.begin(), path.end());
    return path;
}

std::string bfs(int start, int end) {
    if (start == end) {
        return "0";
    }

    std::queue<long> q;

    opCodes[start] = START;
    q.push(start);
    while (!q.empty()) {
        int opIdx = -1;
        const long cur = q.front();
        q.pop();

        for (const long &next : {cur * cur, cur + cur, 0L, 1L}) {
            ++opIdx;
            if (opCodes[next] != 0) {
                continue;
            }

            opCodes[next] = OPCODES[opIdx];
            prev[next] = cur;
            if (next == end) {
                return findPath(end);
            }

            q.push(next);
        }
    }
    return "-1";
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int start, end;

    std::cin >> start >> end;
    std::cout << bfs(start, end) << '\n';
    return 0;
}
