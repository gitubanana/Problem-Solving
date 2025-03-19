#include <sys/mman.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <ctype.h>

inline void skipLine(char *&input, int &remainCnt) {
    while (*input != '\n') {
        input++;
        remainCnt--;
    }
    input++;
    remainCnt--;
}

int main(void) {
    struct stat fileInfo;

    fstat(STDIN_FILENO, &fileInfo);
    char *save = (char *)mmap(0, fileInfo.st_size, PROT_READ, MAP_PRIVATE, STDIN_FILENO, 0);
    if (save == MAP_FAILED) {
        perror("");
        return 1;
    }

    char *input = save;
    int remainCnt = fileInfo.st_size;

    skipLine(input, remainCnt);
    while (remainCnt--) {
        printf("%c", tolower(*input));
        input++;
    }

    if (munmap(save, fileInfo.st_size) == -1) {
        perror("");
        return 1;
    }
    return 0;
}
