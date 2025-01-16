#include <iostream>
#include <vector>
#include <queue>

// NFA (Non-Deterministic Finite Automata)

struct t_edge {
    int v;
    char label;
};

enum e_accepted {
    ACCEPTED1 = 4,
    ACCEPTED2 = 6
};

const int V_CNT = 7;
const int START = 0;

bool accepted[V_CNT];
std::vector<t_edge> edges[V_CNT];

void makeDFA() {
    edges[START].push_back({1, '1'});
    edges[1].push_back({2, '0'});
    edges[2].push_back({3, '0'});
    edges[3].push_back({3, '0'});
    edges[3].push_back({4, '1'});
    edges[4].push_back({4, '1'});
    edges[4].push_back({1, '1'});
    edges[4].push_back({5, '0'});

    edges[START].push_back({5, '0'});
    edges[5].push_back({6, '1'});
    edges[6].push_back({1, '1'});
    edges[6].push_back({5, '0'});

    accepted[ACCEPTED1] = accepted[ACCEPTED2] = true;
}

bool isAccepted(std::queue<int> &states) {
    while (!states.empty()) {
        int endState = states.front();
        if (accepted[endState]) {
            return true;
        }

        states.pop();
    }
    return false;
}

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    std::string str;
    std::cin >> str;

    std::queue<int> states;

    makeDFA();
    states.push(START);
    for (const char &curLabel : str) {
        for (int qSize = states.size(); qSize-- > 0; ) {
            int curState = states.front();
            states.pop();

            for (const t_edge &next : edges[curState]) {
                if (curLabel == next.label) {
                    states.push(next.v);
                }
            }
        }
    }

    const char *msg[] = {"NOISE", "SUBMARINE"};
    std::cout << msg[isAccepted(states)] << '\n';
    return (0);
}
