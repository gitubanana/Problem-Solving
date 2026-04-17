#include <stdio.h>

class Verifier {
public:
    virtual ~Verifier() {}
    virtual bool yes(void) const = 0;
};

class isOddVerifier : public Verifier {
private:
    const int num;

public:
    isOddVerifier(const int num) : num(num) { }

    bool yes(void) const {
        return num & 1;
    }
};

int main() {
    int testCnt;

    scanf(" %d", &testCnt);
    while (testCnt--) {
        int num;
        scanf(" %d", &num);

        Verifier &&verifier = isOddVerifier(num);
        printf("%d is %s\n", num, verifier.yes() ? "odd" : "even");
    }
    return 0;
}