#include <iostream>
#include <cstring>

enum e_cmd {
    ASSIGN = 'a',
    RESET = 'r',
    SWAP = 's'
};

class Pointers {
private:
    int *pointers;

public:
    static const int NONE = 0;

    Pointers(int pointerCnt) : pointers(new int[pointerCnt]) {
    }

    ~Pointers() {
        delete[] pointers;
    }

    void assign(int old, int new_) {
        pointers[old] = pointers[new_];
    }

    void swap(int a, int b) {
        int tmp = pointers[a];

        pointers[a] = pointers[b];
        pointers[b] = tmp;
    }

    void reset(int x) {
        pointers[x] = NONE;
    }

    friend int main(void); // friend가 main에 되는지 테스트
};

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int objectCnt, pointerCnt, cmdCnt;
    std::cin >> objectCnt >> pointerCnt >> cmdCnt;

    Pointers pointers(pointerCnt + 1);
    for (int i = 1; i <= pointerCnt; i++) {
        std::cin >> pointers.pointers[i];
    }

    while (cmdCnt--) {
        int a, b;
        std::string cmd;

        std::cin >> cmd;
        switch (cmd[0])
        {
        case ASSIGN:
            std::cin >> a >> b;
            pointers.assign(a, b);
            break;
        case SWAP:
            std::cin >> a >> b;
            pointers.swap(a, b);
            break;
        case RESET:
            std::cin >> a;
            pointers.reset(a);
            break;
        }
    }

    int aliveCnt = 0;
    bool *isAlive = new bool[objectCnt + 1];
    for (int i = 1; i <= objectCnt; i++) {
        isAlive[i] = false;
    }
    for (int i = 1; i <= pointerCnt; i++) {
        const int &object = pointers.pointers[i];
        if (object == Pointers::NONE || isAlive[object]) {
            continue;
        }

        isAlive[object] = true;
        aliveCnt++;
    }

    // counting sort
    std::cout << aliveCnt << '\n';
    for (int i = 1; i <= objectCnt; i++) {
        if (isAlive[i]) {
            std::cout << i << '\n';
        }
    }

    delete[] isAlive;
    return 0;
}
