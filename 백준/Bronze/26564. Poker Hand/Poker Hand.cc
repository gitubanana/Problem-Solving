#include <iostream>

#include <cstring>

#include <algorithm>

using namespace std;

const int CARD_CNT = 5;

const string RANK = "A23456789TJQK";

int cnt[13];

int main() {

    cin.tie(0)->sync_with_stdio(0);

    int testCnt;

    string card;

    cin >> testCnt;

    while (testCnt--) {

        memset(cnt, 0, sizeof(cnt));

        for (int i = 0; i < CARD_CNT; i++) {

            cin >> card;

            cnt[RANK.find(card[0])]++;

        }

        cout << *max_element(cnt, cnt + sizeof(cnt) / sizeof(int)) << '\n';

    }

    return 0;

}