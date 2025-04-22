#include <stdio.h>
#include <string.h>


struct Browser {
    static const int LINE_LENGTH = 80;
    static constexpr const char *BR = "\n";
    static constexpr const char *HR = "--------------------------------------------------------------------------------";    

    char line[LINE_LENGTH + 1];

    Browser(void) { line[0] = 0; }

    bool process(void) {
        static char word[LINE_LENGTH + 1];

        if (scanf(" %s", word) != 1) {
            return false;
        }

        if (strcmp(word, "<br>") == 0) {
            this->breakLine();
        } else if (strcmp(word, "<hr>") == 0) {
            this->horizontal();
        } else {
            this->addWord(word);
        }
        return true;
    }

    void breakLine(void) {
        this->flush();
        printf(BR);
    }

    void horizontal(void) {
        if (line[0] != 0) {
            this->breakLine();
        }
        printf(HR);
        printf(BR);
    }

    void addWord(const char *word) {
        int wordLength = strlen(word);
        int oldLength = strlen(line);
        int newLength = oldLength + wordLength + (oldLength != 0);

        if (newLength > LINE_LENGTH) {
            this->breakLine();
            strcpy(line, word);
            return;
        }

        if (oldLength == 0) {
            oldLength = -1;
        } else {
            line[oldLength] = ' ';
        }
        strcpy(&line[oldLength + 1], word);
    }

    void flush(void) {
        if (line[0] == 0) {
            return;
        }

        printf("%s", line);
        line[0] = 0;
    }
};

int main(void) {
    Browser browser;

    while (browser.process()) {
        ;
    }
    browser.breakLine();
    return 0;
}
