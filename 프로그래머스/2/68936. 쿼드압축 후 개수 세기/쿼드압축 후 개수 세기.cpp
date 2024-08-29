#include <string>
#include <vector>

using namespace std;

int cnt[2];

inline bool isAll(vector<vector<int>> &map,
                 int startY, int startX, int endY, int endX, int value)
{
    for (int y = startY; y < endY; ++y)
    {
        for (int x = startX; x < endX; ++x)
        {
            if (map[y][x] != value)
            {
                return (false);
            }
        }
    }
    return (true);
}

void    quadTree(vector<vector<int>> &map,
                int startY, int startX, int size)
{
    int endY = startY + size;
    int endX = startX + size;

    for (int i = 0; i < 2; ++i)
    {
        if (isAll(map, startY, startX, endY, endX, i))
        {
            ++cnt[i];
            return ;
        }
    }

    size /= 2;
    quadTree(map, startY, startX, size);
    quadTree(map, startY + size, startX, size);
    quadTree(map, startY, startX + size, size);
    quadTree(map, startY + size, startX + size, size);
}

vector<int> solution(vector<vector<int>> arr) {
    quadTree(arr, 0, 0, arr.size());

    vector<int> answer;
    for (int i = 0; i < 2; ++i)
    {
        answer.push_back(cnt[i]);
    }
    return answer;
}