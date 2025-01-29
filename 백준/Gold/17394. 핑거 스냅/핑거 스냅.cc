#include <iostream>
#include <cstring>
#include <queue>

const int MAX_NUMBER = 1e6 + 1;
const int MAX_RANGE = 1e5 + 1;

bool visited[MAX_NUMBER];
bool isNotPrime[MAX_RANGE];

void eratosthenesSieve(void) {
    for (int mul = 2; mul < MAX_RANGE; ++mul) {
        if (isNotPrime[mul]) {
            continue;
        }

        for (int num = mul << 1; num < MAX_RANGE; num += mul) {
            isNotPrime[num] = true;
        }
    }
}

inline bool achieveTheGoal(int cur, int min, int max) {
    return (min <= cur && cur <= max)
            && !isNotPrime[cur];
}

inline bool outOfRange(int cur) {
    return !(0 < cur && cur < MAX_NUMBER);
}

int bfs(int start, int min, int max) {
    if (achieveTheGoal(start, min, max)) {
        return 0;
    }

    int snapCnt = 1;
    std::queue<int> q;

    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        int qSize = q.size();

        while (qSize-- > 0) {
            const int cur = q.front();
            q.pop();

            for (const int &next : {cur / 2, cur / 3, cur + 1, cur - 1}) {
                if (outOfRange(next) || visited[next]) {
                    continue;
                }

                if (achieveTheGoal(next, min, max)) {
                    return snapCnt;
                }

                visited[next] = true;
                q.push(next);
            }
        }
        ++snapCnt;
    }
    return -1;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    std::cin >> testCnt;
    eratosthenesSieve();
    while (testCnt-- > 0) {
        int start, min, max;

        std::cin >> start >> min >> max;
        memset(visited, false, sizeof(visited));
        std::cout << bfs(start, min, max) << '\n';
    }
    return 0;
}
