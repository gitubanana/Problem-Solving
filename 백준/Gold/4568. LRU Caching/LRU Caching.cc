#include <stdio.h>
#include <algorithm>
#include <string>
#include <vector>

const int MAX_ACCESS = 1024;
const char PRINT = '!';

struct Line {
    int time_;
    char name;

    inline bool operator<(const Line &other) const {
        return this->time_ < other.time_;
    }
};

struct LRU {
    int maxSize;
    int time_;
    std::vector<Line> lines;

    LRU(int maxSize) : maxSize(maxSize), time_(0) { }

    void access(char name) {
        Line *line = findLine(name);
        
        ++time_;
        if (line != NULL) {
            line->time_ = time_;
        } else if (maxSize == lines.size()) {
            lines.front().name = name;
            lines.front().time_ = time_;
        } else {
            lines.push_back({time_, name});
            return;
        }

        std::sort(lines.begin(), lines.end());
    }

    Line *findLine(char name) {
        for (Line &line : lines) {
            if (line.name == name) {
                return &line;
            }
        }
        return NULL;
    }

    std::string toString(void) const {
        std::string str;

        for (const Line &line : lines) {
            str.push_back(line.name);
        }
        return str;
    }
};

int main(void) {
    int size;
    int test = 0;
    char accessLog[MAX_ACCESS + 1];

    while (scanf(" %d %s", &size, accessLog) == 2) {
        LRU cache(size);

        printf("Simulation %d\n", ++test);
        for (int i = 0; accessLog[i]; i++) {
            if (accessLog[i] == PRINT) {
                printf("%s\n", cache.toString().c_str());
                continue;
            }

            cache.access(accessLog[i]);
        }
    }
    return 0;
}
