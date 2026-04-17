#include <iostream>
#include <queue>
#include <vector>

const int ALPHABET_COUNT = 26;

std::queue<int> qs[ALPHABET_COUNT];

int main() {
    std::cin.tie(0)->sync_with_stdio(0);

    std::string key, cipherText;
    std::cin >> key >> cipherText;

    int xSize = key.length();
    for (int x = 0; x < xSize; x++) {
        qs[key[x] - 'A'].push(x);
    }

    int ySize = cipherText.length() / key.length();
    std::vector<int> map(xSize);
    for (int i = 0, x = 0; i < ALPHABET_COUNT; i++) {
        std::queue<int> &q = qs[i];
        while (!q.empty()) {
            int mapX =  q.front();
            q.pop();

            map[mapX] = x;
            x += ySize;
        }
    }

    for (int y = 0; y < ySize; y++) {
        for (int x = 0; x < xSize; x++) {
            printf("%c", cipherText[map[x] + y]);
        }
    }
    printf("\n");
    return 0;
}