#include <bits/stdc++.h>
// reference code : https://blog.naver.com/jinhan814/222369943703

using ll = long long;
using lll = __int128_t;

template <typename K, typename V>
using umap = std::unordered_map<K, V>;

umap<ll, lll> dp;
ll base, modular;

lll divideAndConquer(ll exponent) {
    if (exponent == 1) {
        return base;
    }

    umap<ll, lll>::iterator it = dp.find(exponent);
    if (it != dp.end()) {
        return it->second;
    }

    ll left = exponent >> 1;
    ll right = left + (left << 1 != exponent);
    lll save = (divideAndConquer(left) * divideAndConquer(right)) % modular;

    dp.insert({exponent, save});
    return save;
}

int main(void) {
    ll exponent;

    scanf(" %lld %lld %lld", &base, &exponent, &modular);
    base %= modular;
    printf("%lld\n", divideAndConquer(exponent));
    return 0;
}
