#include <stdio.h>
#include <queue>
#include <string>
#include <unordered_set>

using Uset = std::unordered_set<std::string>;

// immutable class
class Code {
public:
    static const int TWO_D_SIZE = 3;
    static const int ONE_D_SIZE = TWO_D_SIZE * TWO_D_SIZE;

    Code(const Code &other) {
        buttons[ONE_D_SIZE] = 0;
        for (int i = 0; i < ONE_D_SIZE; i++) {
            buttons[i] = other.buttons[i];
        }
    }

    Code(FILE *in) {
        buttons[ONE_D_SIZE] = 0;
        for (int i = 0; i < ONE_D_SIZE; i++) {
            fscanf(in, " %c", &buttons[i]);
        }
    }

    Code push(int y, int x) const {
        Code pushed = *this;

        for (int ySet = 0; ySet < TWO_D_SIZE; ySet++) {
            increment(pushed.buttons[ySet * TWO_D_SIZE + x]);
        }
        for (int xSet = 0; xSet < TWO_D_SIZE; xSet++) {
            increment(pushed.buttons[y * TWO_D_SIZE + xSet]);
        }
        increment(pushed.buttons[y * TWO_D_SIZE + x]);
        increment(pushed.buttons[y * TWO_D_SIZE + x]);
        increment(pushed.buttons[y * TWO_D_SIZE + x]);
        return pushed;
    }
    
    inline const char *toString() const {
        return buttons;
    }

    inline bool solved(void) const {
        for (int i = 0; i < ONE_D_SIZE; i++) {
            if (buttons[i] != '0') {
                return false;
            }
        }
        return true;
    }

private:
    char buttons[ONE_D_SIZE + 1];
    
    inline void increment(char &ch) const {
        ch = '0' + (ch - '0' + 1) % 4;
    }
};

int bfs(const Code &start) {
    if (start.solved()) {
        return 0;
    }

    int pushCnt = 1;
    Uset visited;
    std::queue<Code> q;

    visited.insert(start.toString());
    q.push(start);
    do {
        for (int qSize = q.size(); qSize; qSize--) {
            const Code &cur = q.front();

            for (int y = 0; y < Code::TWO_D_SIZE; y++) {
                for (int x = 0; x < Code::TWO_D_SIZE; x++) {
                    Code next = cur.push(y, x);
                    if (visited.find(next.toString()) != visited.end()) {
                        continue;
                    }

                    if (next.solved()) {
                        return pushCnt;
                    }

                    visited.insert(next.toString());
                    q.push(next);
                }
            }
            q.pop();
        }
    } while (!q.empty() && pushCnt++);

    return -1;
}

int main(void) {
    Code start(stdin);

    fprintf(stdout, "%d\n", bfs(start));
    return 0;
}
