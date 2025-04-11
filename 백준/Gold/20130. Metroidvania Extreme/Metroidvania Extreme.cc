#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#define IS_KEY islower
#define IS_DOOR isupper

enum e_space {
    WALL = '#',
    START = '@',
    EMPTY = '*',
    END = '!'
};

struct Pos {
    int y, x;
    int key;
};

using Pair = std::pair<int, int>;

const int MAX_SIZE = 300;
const int INIT_VALUE = -1;
const int KEY_COUNT = 26;
const int MAX_KEY = (1 << KEY_COUNT) - 1;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

struct BoolVector {
    std::unordered_set<int> uset;

    inline bool isSet(int idx) {
        return uset.find(idx) != uset.end();
    }

    inline void set(int idx) {
        uset.insert(idx);
    }
};

struct Umap {
    std::unordered_map<int, Pair> umap;

    inline Pair &get(int key) {
        return umap.at(key);
    }
    
    inline void set(int key, const Pair &vaule) {
        umap.insert({key, vaule});
    }
};

int ySize, xSize;
Umap prevs[MAX_SIZE][MAX_SIZE];
char map[MAX_SIZE][MAX_SIZE + 1];
BoolVector visited[MAX_SIZE][MAX_SIZE];
Pos start = {INIT_VALUE, INIT_VALUE, 0};

void printLog(Pos &cur) {
    int printCnt = 1;
    std::string result;
    BoolVector printed;
    std::vector<Pair> logs;

    do {
        Pair pair = prevs[cur.y][cur.x].get(cur.key);
        int prevKey = pair.first;
        int prevPos = pair.second;

        logs.push_back({cur.y + 1, cur.x + 1});
        cur.y = prevPos / xSize;
        cur.x = prevPos % xSize;
        cur.key = prevKey;
    } while (!(map[cur.y][cur.x] == START && cur.key == 0));

    ++start.y, ++start.x;
    printed.set(start.y*xSize + start.x);
    result.append(std::to_string(start.y)).append(" ").append(std::to_string(start.x)).append("\n");
    for (int i = logs.size() - 1; i >= 0; i--) {
        int &y = logs[i].first;
        int &x = logs[i].second;
        int check = y*xSize + x;
        if (printed.isSet(check)) {
            continue;
        }

        printed.set(check);
        result.append(std::to_string(y)).append(" ").append(std::to_string(x)).append("\n");
        printCnt++;
    }

    fprintf(stdout, "%d\n%s", printCnt, result.c_str());
}

inline void pickUpKey(Pos &pos, char &space) {
    pos.key |= (1 << (space - 'a'));
}

inline bool cannotOpenDoor(Pos &pos, char &space) {
    return !(pos.key & (1 << (space - 'A')));
}

void bfs(const Pos &start) {
    std::queue<Pos> q;
    
    visited[start.y][start.x].set(start.key);
    q.push(start);
    while (!q.empty()) {
        const Pos cur = q.front();
        q.pop();

        for (int dir = 0; dir < dirSize; dir++) {
            Pos next = {cur.y + dy[dir], cur.x + dx[dir], cur.key};
            char &nextSpace = map[next.y][next.x];
            if (nextSpace == WALL) {
                continue;
            }

            if (IS_KEY(nextSpace)) {
                pickUpKey(next, nextSpace);
            } else if (IS_DOOR(nextSpace)) {
                if (cannotOpenDoor(next, nextSpace)) {
                    continue;
                }
            }

            BoolVector &nextVisited = visited[next.y][next.x];
            if (nextVisited.isSet(next.key)) {
                continue;
            }

            prevs[next.y][next.x].set(next.key, {cur.key, cur.y*xSize + cur.x});
            if (nextSpace == END) {
                printLog(next);
                return;
            }

            nextVisited.set(next.key);
            q.push(next);
        }
    }
}

int main(void) {
    fscanf(stdin, " %d %d", &ySize, &xSize);
    for (int y = 0; y < ySize; y++) {
        fscanf(stdin, " %s", map[y]);
        if (start.y != INIT_VALUE) {
            continue;
        }

        for (int x = 0; x < xSize; x++) {
            if (map[y][x] == START) {
                start.y = y;
                start.x = x;
                break;
            }
        }
    }

    bfs(start);
    return 0;
}
