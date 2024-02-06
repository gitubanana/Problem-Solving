#include <iostream>
#include <climits>
#include <unordered_map>

const long long MAX = 100000;
const long long REMOVED = INT_MAX;

long long size;

typedef std::unordered_map<long long, long long> t_umap;

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    long long cur;
    long long ans = 0;
    long long curSeries = 0;
    t_umap umap;

    std::cin >> size;
    for (long long i = 0; i < size; )
    {
        while (i < size)
        {
            std::cin >> cur, ++i;

            t_umap::iterator it = umap.find(cur);

            if (it != umap.end() && it->second != REMOVED)
            {
                ans += (curSeries + 1) * curSeries / 2;

                long long removeIdx = it->second;

                it->second = i;
                --curSeries;
                for (it = umap.begin(); it != umap.end(); ++it)
                {
                    if (it->second < removeIdx)
                    {
                        --curSeries;
                        it->second = REMOVED;
                    }
                }
                ans -= (curSeries + 1) * curSeries / 2;
                ++curSeries;
                break ;
            }

            ++curSeries;
            umap[cur] = i;
        }
    }

    ans += (curSeries + 1) * curSeries / 2;
    std::cout << ans << '\n';
    return (0);
}
