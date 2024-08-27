#include <string>
#include <vector>

using namespace std;

const int MAX_SIZE = 1000;
const int dy[] = {1, 0, -1};
const int dx[] = {0, 1, -1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int map[MAX_SIZE][MAX_SIZE];

vector<int> solution(int n) {
    vector<int> answer;

    int prev, num = 0;
    int y = 0, x = 0;

    map[y][x] = ++num;
    do
    {
        prev = num;
        for (int dir = 0; dir < dirSize; ++dir)
        {
            while (true)
            {
                int nextY = y + dy[dir];
                int nextX = x + dx[dir];

                if (nextY == n || nextX == n
                    || map[nextY][nextX] != 0)
                    break ;

                map[y = nextY][x = nextX] = ++num;
            }
        }
    } while (prev != num);

    for (int y = 0; y < n; ++y)
    {
        for (int x = 0; x <= y; ++x)
        {
            answer.push_back(map[y][x]);
        }
    }
    return answer;
}