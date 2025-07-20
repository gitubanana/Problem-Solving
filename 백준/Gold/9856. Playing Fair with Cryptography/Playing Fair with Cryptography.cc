#include <ctype.h>
#include <iostream>
#include <unordered_map>

template <typename K, typename V>
using Umap = std::unordered_map<K, V>;

class Pos {
public:
    int y, x;

    inline bool onTheSameRow(const Pos &other) const {
        return this->y == other.y;
    }

    inline bool onTheSameColumn(const Pos &other) const {
        return this->x == other.x;
    }

    inline bool move(int size) {
        x++;
        if (x == size) {
            y++;
            x = 0;
        }

        return (y != size);
    }
};

class KeyMap {
private:
    static const int SIZE = 5;

    Umap<char, Pos> posByChar;
    Umap<int, Umap<int, char>> charByPos;
public:
    KeyMap(const std::string &key) {
        Pos pos = {0, 0};

        for (const char &ch : key) {
            if (!isalpha(ch)) {
                continue;
            }

            char upperCh = toupper(ch);
            if (contains(upperCh)) {
                continue;
            }

            add(pos, upperCh);
            if (!pos.move(SIZE)) {
                return;
            }
        }

        for (char ch = 'A'; ; ch++) {
            if (ch == 'J' || contains(ch)) {
                continue;
            }

            add(pos, ch);
            if (!pos.move(SIZE)) {
                break;
            }
        }
    }

    inline bool contains(char ch) {
        return posByChar.find(ch) != posByChar.end();
    }

    inline void add(const Pos &pos, char ch) {
        posByChar[ch] = pos;
        charByPos[pos.y][pos.x] = ch;
    }

    inline char charAt(const Pos &pos) {
        return charByPos[pos.y][pos.x];
    }

    inline const Pos &posOf(char ch) {
        return posByChar[ch];
    }

    inline char nextCharOnTheSameRow(const Pos &pos) {
        return this->charAt({pos.y, (pos.x + 1) % SIZE});
    }

    inline char nextCharOnTheSameColumn(const Pos &pos) {
        return this->charAt({(pos.y + 1) % SIZE, pos.x});
    }
};

class Playfair {
private:
    KeyMap keyMap;

    std::string encryptGroup(char one, char two) {
        const Pos &first = keyMap.posOf(one);
        const Pos &second = keyMap.posOf(two);

        if (first.onTheSameRow(second)) {
            return {keyMap.nextCharOnTheSameRow(first), keyMap.nextCharOnTheSameRow(second)};
        }

        if (first.onTheSameColumn(second)) {
            return {keyMap.nextCharOnTheSameColumn(first), keyMap.nextCharOnTheSameColumn(second)};
        }

        return {keyMap.charAt({first.y, second.x}), keyMap.charAt({second.y, first.x})};
    }

    char nextInsertChar(char &insertCh) {
        char next = insertCh;

        insertCh = 'A' + (insertCh - 'A' + 1) % 26;
        if (insertCh == 'J') {
            insertCh = 'K';
        }
        return next;
    }
public:
    Playfair(const std::string &key) : keyMap(key) { }

    std::string encrypt(const std::string &plainText) {
        char insertCh = 'A';
        std::string cypherText;

        cypherText.reserve(plainText.size());
        for (int i = 0; i < plainText.size(); i += 2) {
            char one = plainText[i];
            char two = (i + 1 == plainText.size()) ? nextInsertChar(insertCh) : plainText[i + 1];

            if (one == two) {
                char nextCh = nextInsertChar(insertCh);
                two = (one == nextCh ? nextInsertChar(insertCh) : nextCh);
                i--;
            }

            cypherText += encryptGroup(one, two);
        }
        return cypherText;
    }
};

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int testCnt;
    std::string key, temp, plainText;

    std::getline(std::cin, temp);
    testCnt = atoi(temp.c_str());
    for (int t = 1; t <= testCnt; t++) {
        std::getline(std::cin, key);
        std::getline(std::cin, temp);

        plainText.clear();
        for (const char &ch : temp) {
            if (isalpha(ch)) {
                plainText += toupper(ch);
            }
        }
    
        std::cout << "Case " << t << ": " << Playfair(key).encrypt(plainText) << '\n';
    }
    return 0;
}
