#include <stdio.h>

class Validator {
private:
    bool isOk;
public:
    Validator(const char *str) : isOk(true) {
        int *cnt = new int[26]();

        for (int i = 0; str[i]; i++) {
            int &curCnt = cnt[str[i] - 'A'];

            if (++curCnt == 3) {
                if (str[i] != str[++i]) {
                    isOk = false;
                    break;
                }
                curCnt = 0;
            }
        }
        delete[] cnt;
    }

    const char *toString() const {
        static const char *result[] = {"FAKE", "OK"};

        return result[isOk];
    }
};

const int MAX_SIZE = 100000;

int main(void) {
    int testCnt;
    char str[MAX_SIZE + 1];

    scanf(" %d", &testCnt);
    for (int t = 0; t < testCnt; t++) {
        scanf(" %s", str);
        printf("%s\n", Validator(str).toString());
    }
    return 0;
}
