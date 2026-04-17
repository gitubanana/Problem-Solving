#include <iostream>

using namespace std;

int main() {

    cin.tie(0)->sync_with_stdio(0);

    int n;

    int idx = 1;

    const char *msg[] { "False", "True" };

    cin >> n;

    while (n--) {

        int h;

        cin >> h;

        if (h < 48) {

            idx = 0;

            break;

        }

    }

    cout << msg[idx];

    return 0;

}