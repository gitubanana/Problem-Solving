#include <stdio.h>

// singleton pattern
// iterator pattern

class Numbers {
public:
    virtual void print(void) const = 0;
};

class PerfectNumbers : public Numbers {
private:
    static const int START = 1000;
    static const int END = 9999;
    static PerfectNumbers *instance;

    PerfectNumbers(void) { }
    PerfectNumbers(const PerfectNumbers&) { }
    PerfectNumbers& operator=(const PerfectNumbers&) { return *this; }

public:
    static PerfectNumbers *getInstance(void);

    inline void print(void) const {
        for (int num = START; num <= END; num++) {
            if (isPerfect(num)) {
                printf("%d ", num);
            }
        }
        printf("\n");
    }

    inline bool isPerfect(int number) const {
        int sum = 1;

        for (int divisor = 2; divisor * divisor <= number; divisor++) {
            int quotient = number / divisor;
            if (divisor * quotient != number) {
                continue;
            }

            sum += divisor + quotient;
        }
        return sum == number;
    }
};

PerfectNumbers *PerfectNumbers::getInstance(void) {
    if (instance == nullptr) {
        instance = new PerfectNumbers();
    }
    return instance;
}


class CubeNumbers : public Numbers {
private:
    static const int START = 100;
    static const int END = 999;
    static CubeNumbers *instance;

    CubeNumbers(void) { }
    CubeNumbers(const CubeNumbers&) { }
    CubeNumbers& operator=(const CubeNumbers&) { return *this; }

public:
    static CubeNumbers *getInstance(void);

    inline void print(void) const {
        for (int num = START; num <= END; num++) {
            if (isCube(num)) {
                printf("%d ", num);
            }
        }
        printf("\n");
    }

    inline bool isCube(int number) const {
        int sum = 0;
        int digits = number;

        while (digits > 0) {
            int digit = digits % 10;

            sum += digit * digit * digit;
            digits /= 10;
        }
        return sum == number;
    }
};

CubeNumbers *CubeNumbers::getInstance(void) {
    if (instance == nullptr) {
        instance = new CubeNumbers();
    }
    return instance;
}

PerfectNumbers *PerfectNumbers::instance = nullptr;
CubeNumbers *CubeNumbers::instance = nullptr;

int main(void) {
    Numbers *iterators[] = {PerfectNumbers::getInstance(), CubeNumbers::getInstance()};
    int size = sizeof(iterators) / sizeof(iterators[0]);

    for (int i = 0; i < size; i++) {
        iterators[i]->print();
    }
    return 0;
}
