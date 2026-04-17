#include <stdio.h>
#include <queue>

class Stack {
private:
    int idx;
    int *arr;
public:
    static int SIZE;

    Stack() : Stack(SIZE) { }
    Stack(int size) : idx(0), arr(new int[size]) { }
    ~Stack() { delete[] arr; }

    inline void push(int elem) {
        arr[idx++] = elem;
    }

    inline int pop() {
        return arr[--idx];
    }
};

class Comp {
public:
    int num;
    int idx;

    inline bool operator<(const Comp &other) const {
        return this->num < other.num;
    }
};

int Stack::SIZE;

int findNthNum(Stack *stacks, int size) {
    int ret = 0;
    std::priority_queue<Comp> pq;

    for (int i = 0; i < size; i++) {
        pq.push({stacks[i].pop(), i});
    }
    for (int i = 0; i < size; i++) {
        Comp max = pq.top();
        pq.pop();
        
        ret = max.num;
        pq.push({stacks[max.idx].pop(), max.idx});
    }
    return ret;
}

int main(void) {
    int size;
    fscanf(stdin, " %d", &size);

    Stack::SIZE = size;
    Stack *stacks = new Stack[size];
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            int elem;

            fscanf(stdin, " %d", &elem);
            stacks[x].push(elem);
        }
    }

    fprintf(stdout, "%d\n", findNthNum(stacks, size));
    delete[] stacks;
    return 0;
}
