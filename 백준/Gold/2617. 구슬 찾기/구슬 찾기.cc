#include <iostream>

#include <unordered_set>

const int MAX_V = 100;

int vCnt;

bool isHeavy[MAX_V][MAX_V];

bool isLight[MAX_V][MAX_V];

void floyd(bool isLink[MAX_V][MAX_V])

{

    for (int mid = 1; mid <= vCnt; ++mid)

    {

        for (int from = 1; from <= vCnt; ++from)

        {

            for (int to = 1; to <= vCnt; ++to)

            {

                isLink[from][to] |= isLink[from][mid] & isLink[mid][to]; 

            }

        }

    }

}

int getCnt(bool check[MAX_V][MAX_V], int from)

{

    int cnt = 0;

    for (int to = 1; to <= vCnt; ++to)

    {

        cnt += check[from][to];

    }

    return cnt;

}

int main()

{

    std::cin.tie(0)->sync_with_stdio(0);

    int eCnt;

    std::cin >> vCnt >> eCnt;

    while (eCnt--)

    {

        int from, to;

        std::cin >> from >> to;

        isHeavy[from][to] = true;

        isLight[to][from] = true;

    }

    floyd(isHeavy);

    floyd(isLight);

    int ans = 0;

    int half = vCnt / 2;

    for (int from = 1; from <= vCnt; ++from)

    {

        ans += (

            getCnt(isHeavy, from) > half

            || getCnt(isLight, from) > half - !(vCnt & 1)

        );

    }

    std::cout << ans << '\n';

    return 0;

}