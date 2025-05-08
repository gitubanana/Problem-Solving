#include <stdio.h>
#include <ctype.h>

struct Reader {
    static const int MAX_SIZE = 63e2;

    int index;
    char buffer[MAX_SIZE];

    Reader(FILE *stream) : index(-1) {
        fread(buffer, sizeof(char), MAX_SIZE, stream);
    }

    inline int nextInt(void) {
        int ret = 0;

        while (isdigit(buffer[++index])) {
            ret = ret * 10 + (buffer[index] - '0');
        }
        return ret;
    }
};

int main(void) {
    Reader reader(stdin);

    while (true) {
        int logCnt = reader.nextInt();
        if (logCnt == 0) {
            break;
        }

        int totalMiles = 0;
        int prevTime = 0;
        for (int i = 0; i < logCnt; i++) {
            int speed = reader.nextInt();
            int curTime = reader.nextInt();

            totalMiles += speed * (curTime - prevTime);
            prevTime = curTime;
        }

        printf("%d miles\n", totalMiles);
    }
    return 0;
}
