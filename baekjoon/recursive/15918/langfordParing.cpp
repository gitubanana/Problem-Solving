#include <iostream>

const int MAX_SIZE = 12 * 2 + 1;

int ans;
int size;
int arr[MAX_SIZE];
bool visited[MAX_SIZE];
void backTracking(int depth=1)
{
        static const int doubleSize = size * 2;
        static const int depthLimit = doubleSize + 1;

    if (depth == depthLimit)
    {
        ++ans;
        return ;
        }

    if (arr[depth] != 0)
    {
        backTracking(depth + 1);
        return ;
    }

    for (int num = 1; num <= size; ++num)
    {
        bool &numVisited = visited[num];
        if (numVisited)
            continue;

        int other = depth + num + 1;
        if (other > doubleSize
            || arr[other] != 0)
            continue;

        arr[other] = num;
        numVisited = true;

        backTracking(depth + 1);

        numVisited = false;
        arr[other] = 0;
    }
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    int x, y;
    std::cin >> size >> x >> y;

    int num = y - x - 1;
    arr[x] = arr[y] = num;
    visited[num] = true;

    backTracking();
    std::cout << ans << '\n';
    return 0;
}
