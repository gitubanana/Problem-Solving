#include <stdio.h>
#include <queue>
#include <vector>

class Node {
public:
    int cnt;
    std::vector<Node *> edges;

    Node() : cnt(0) {}
};

class Comp {
    public:
    inline bool operator()(const Node *a, const Node *b) const {
        return a->cnt > b->cnt;
    }
};

const int MAX_SIZE = 1e4*2;

class NodeAllocator {
private:
    static Node nodes[MAX_SIZE];
    int nextId;
public:
    NodeAllocator(int nodeCnt) : /*nodes(new Node[nodeCnt]),*/ nextId(0) {}

    // ~NodeAllocator() { delete[] nodes; }

    inline Node *newNode() {
        Node &node = nodes[nextId++];

        node.cnt = 0;
        node.edges.clear();
        return &node;
    }
};

Node NodeAllocator::nodes[MAX_SIZE];

using ll = long long;
using Pq = std::priority_queue<Node *, std::vector<Node *>, Comp>;

ll dfs(Node *cur, int depth=0) {
    if (cur->edges.empty()) {
        return static_cast<ll>(depth) * cur->cnt;
    }

    ll ret = 0;
    int nextDepth = depth + 1;

    for (Node *&next : cur->edges) {
        ret += dfs(next, nextDepth);
    }
    return ret;
}

// 0을 추가하는 로직은 미처 생각하지 못했습니다... ㅜㅜ
// addZero함수만 'https://testcase.ac/codes/7217' 을 참고했습니다.
void addZero(NodeAllocator *nodeAllocator, Pq &pq, int base) {
    if (base == 2) {
        return;
    }

    while (pq.size() % (base - 1) != 1) {
        Node *node = nodeAllocator->newNode();

        pq.push(node);
    }
}

ll huffmanLength(int vCnt, int base) {
    NodeAllocator nodeAllocator(vCnt * 2);
    Pq pq;

    for (int v = 0; v < vCnt; v++) {
        Node *node = nodeAllocator.newNode();

        scanf(" %d", &node->cnt);
        pq.push(node);
    }

    addZero(&nodeAllocator, pq, base);

    while (pq.size() != 1) { // 루트를 만듦
        Node *parent = nodeAllocator.newNode();

        for (int i = 0; i < base && !pq.empty(); i++) { // base만큼 빼기
            Node *child = pq.top();
            pq.pop();

            parent->cnt += child->cnt;
            parent->edges.push_back(child);
        }

        pq.push(parent);
    }

    return dfs(pq.top()); // root부터 dfs하기
}

int main(void) {
    int testCnt;

    scanf(" %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        int vCnt, base;

        scanf(" %d %d", &vCnt, &base);
        printf("%lld\n", huffmanLength(vCnt, base));
    }
    return 0;
}
