#include <iostream>

const int MAX_SIZE = 100'001;
const int KILLED = -1;

int left[MAX_SIZE];
int right[MAX_SIZE];

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

	while (true) {
    	int s, b;

        std::cin >> s >> b;
        if (s == 0) {
            break;
        }

		for (int i = 1; i <= s; i++) {
			left[i] = i - 1;
			right[i] = i + 1;
		}
		left[1] = right[s] = KILLED;

        while (b-- > 0) {
    		int l, r;
            std::cin >> l >> r;

			left[right[r]] = left[l];
			if (left[l] != KILLED) {
                std::cout << left[l];
            } else {
                std::cout << '*';
            }

            std::cout << ' ';

			right[left[l]] = right[r];
			if (right[r] != KILLED) {
                std::cout << right[r];
            } else {
                std::cout << '*';
            }

            std::cout << '\n';
		}
        std::cout << '-' << '\n';
	}

	return 0;
}