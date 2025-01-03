#include <iostream>
#include <iomanip>
#include <vector>

const int MAX_V = 3000 + 1;
const int ROOT = 1;

int degree[MAX_V];
int parents[MAX_V];

void initParents(int vCnt) {
    for (int v = 1; v <= vCnt; v++) {
        parents[v] = v;
    }
}

int getParent(int x) {
    int &xParent = parents[x];
    if (xParent != x) {
        xParent = getParent(xParent);
    }
    return xParent;
}

void group(int y, int x) {
    int &yParent = parents[getParent(y)];
    int &xParent = parents[getParent(x)];

    if (yParent > xParent) {
        yParent = xParent;
    } else {
        xParent = yParent;
    }
}

bool isConnectedGraph(int vCnt) {
    for (int v = 1; v <= vCnt; v++) {
        if (getParent(v) != ROOT) {
            return false;
        }
    }
    return true;
}

bool isTraverable(int vCnt) {
    int oddCnt = 0;

    for (int v = 1; v <= vCnt; v++) {
        if (degree[v] & 1) {
            oddCnt++;
        }
    }
    return (oddCnt == 0 || oddCnt == 2);
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int vCnt, eCnt;
    const char *msg[] = {"NO", "YES"};

    std::cin >> vCnt >> eCnt;
    initParents(vCnt);
    while (eCnt-- > 0) {
        int a, b;

        std::cin >> a >> b;
        group(a, b);
        degree[a]++;
        degree[b]++;
    }


    std::cout << msg[isConnectedGraph(vCnt) && isTraverable(vCnt)] << '\n';
    return 0;
}
