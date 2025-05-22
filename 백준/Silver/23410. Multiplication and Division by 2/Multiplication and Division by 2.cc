#include <queue>
#include <stdio.h>
#include <ctype.h>
#include <unordered_set>

typedef unsigned int uint32;
typedef uint32 (*t_func)(uint32);

const int MAX_BUFFER_SIZE = 22016;

static char buffer[MAX_BUFFER_SIZE];

static inline uint32 nextUint32(void) {
    static int index = -1;
    uint32 ret = 0;

    while (isdigit(buffer[++index])) {
        ret = ret * 10 + (buffer[index] - '0');
    }
    return ret;
}

static inline uint32 dividedBy2(uint32 num) {
    return (num >> 1L);
}

static inline uint32 multipliedBy2(uint32 num) {
    return (num << 1L);
}

static bool bfs(uint32 start, uint32 end) {
    static t_func funcs[] = {&dividedBy2, &multipliedBy2};
    static int funcCnt = sizeof(funcs) / sizeof(t_func);
    static std::unordered_set<uint32> visited;
    std::queue<uint32> q;

    if (start == end) {
        return true;
    }

    visited.clear();
    visited.insert(start);
    q.push(start);
    while (!q.empty()) {
        const uint32 cur = q.front();
        q.pop();

        for (int i = 0; i < funcCnt; i++) {
            const uint32 next = funcs[i](cur);
            if (visited.find(next) != visited.end()) {
                continue;
            }

            if (next == end) {
                return true;
            }

            visited.insert(next);
            q.push(next);
        }
    }
    return false;
}

int main(void) {
    fread(buffer, sizeof(char), MAX_BUFFER_SIZE, stdin);

    const char *msg[] = {"No", "Yes"};
    int testCnt = nextUint32();
    for (int t = 0; t < testCnt; t++) {
        uint32 start = nextUint32();
        uint32 end = nextUint32();

        printf("%s\n", msg[bfs(start, end)]);
    }
    return 0;
}
