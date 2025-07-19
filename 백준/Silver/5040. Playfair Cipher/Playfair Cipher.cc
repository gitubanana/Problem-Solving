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
            if (!islower(ch)) {
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
            if (ch == 'Q' || contains(ch)) {
                continue;
            }

            add(pos, ch);
            if (!pos.move(SIZE)) {
                return;
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
public:
    Playfair(const std::string &key) : keyMap(key) { }

    std::string encrypt(const std::string &plainText) {
        std::string cypherText;

        cypherText.reserve(plainText.size());
        for (int i = 0; i < plainText.size(); i += 2) {
            char one = toupper(plainText[i]);
            char two = (i + 1 == plainText.size()) ? 'X' : toupper(plainText[i + 1]);

            if (one == two) {
                two = 'X';
                i--;
            }

            cypherText.append(encryptGroup(one, two));
        }
        return cypherText;
    }
};

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    std::string key, plainText;

    std::getline(std::cin, key);
    for (std::string word; std::cin >> word;) {
        plainText.append(word);
    }

    std::cout << Playfair(key).encrypt(plainText) << '\n';
    return 0;
}
