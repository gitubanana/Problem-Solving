#include <stdio.h>
#include <functional>
#include <string>
#include <unordered_map>

const int MAX_SIZE = 1e4 + 1;
const int MAX_DEPTH = 1e2 + 1;
const std::hash<std::string> HASHER;

int textLen;
int depthLimit;
int alphabetCnt;
char ans[MAX_DEPTH];
char text[MAX_SIZE];
std::unordered_map<size_t, int> idxByHash;

void rabinKarp() {
    int end = textLen - depthLimit + 1;

    for (int i = 0; i < end; i++) {
        int nullIdx = i + depthLimit;
        char save = text[nullIdx];

        text[nullIdx] = 0;
        idxByHash[HASHER(&text[i])] = i;
        text[nullIdx] = save;
    }
}

bool isNotSubstring() {
    size_t hash = HASHER(ans);
    std::unordered_map<size_t, int>::iterator it = idxByHash.find(hash);
    if (it == idxByHash.end()) {
        return true;
    }

    int start = it->second;
    for (int i = 0; i < depthLimit; i++) {
        if (ans[i] != text[start + i]) {
            return true;
        }
    }
    return false;
}

bool backTracking(int depth=0) {
    if (depth == depthLimit) {
        if (isNotSubstring()) {
            printf("%s\n", ans);
            return true;
        }
        return false;
    }

    for (int i = 0; i < alphabetCnt; i++) {
        ans[depth] = 'a' + i;
        if (backTracking(depth + 1)) {
            return true;
        }
    }
    return false;
}

int main(void) {
    int testCnt;
    
    scanf(" %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        scanf(" %d %d %d %s", &textLen, &depthLimit, &alphabetCnt, text);
        
        idxByHash.clear();
        rabinKarp();

        ans[depthLimit] = 0;
        backTracking();
    }
    return 0;
}
