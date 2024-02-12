#include <iostream>
#include <set>
#include <climits>
#include <algorithm>

typedef std::set<int> t_plug;

const int MAX = 100;
int cnt[MAX];
int arr[MAX];
int plugSize, useCnt;
t_plug plugs;

int getMinUse(void)
{
    int ret;
    int minUse = INT_MAX;

    for (const int &cur : plugs)
    {
        if (minUse > cnt[cur])
        {
            ret = cur;
            minUse = cnt[cur];
        }
    }
    return (ret);
}

int getLastOne(int start)
{
    int ret;
    int last = INT_MIN;

    for (const int &cur : plugs)
    {
        int found = (std::find(arr + start, arr + useCnt, cur) - arr);
        if (last < found)
        {
            ret = cur;
            last = found;
        }
    }
    return (ret);    
}

bool allWillBeUsed(void)
{
    for (const int &cur : plugs)
    {
        if (cnt[cur] == 0)
            return (false);
    }
    return (true);
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> plugSize >> useCnt;
    for (int i = 0; i < useCnt; ++i)
    {
        std::cin >> arr[i];
        ++cnt[arr[i]];
    }

    int i = 0;
    int ans = 0;
    for (; i < plugSize && i < useCnt; ++i)
    {
        int &cur = arr[i];

        --cnt[cur];
        plugs.insert(cur);
    }
    for (; i < useCnt; ++i)
    {
        int &cur = arr[i];

        if (plugs.size() < plugSize)
        {
            --cnt[cur];
            plugs.insert(cur);
        }
        else if (plugs.find(cur) == plugs.end())
        {
            if (allWillBeUsed())
            {
                plugs.erase(getLastOne(i + 1));
            }
            else
            {
                plugs.erase(getMinUse());
            }
            --cnt[cur];
            plugs.insert(cur);
            ++ans;
        }
    }

    std::cout << ans << '\n';
    return 0;
}