#include <iostream>
#include <cmath>
#include <unordered_set>

enum e_space
{
    EMPTY = 0
};

struct t_seat
{
    int y, x;
    int likeCnt;
    int emptyCnt;

    inline bool operator<(const t_seat &other) const
    {
        if (this->likeCnt != other.likeCnt)
            return (this->likeCnt < other.likeCnt);

        if (this->emptyCnt != other.emptyCnt)
            return (this->emptyCnt < other.emptyCnt);

        return (false);
    }
};

const int MAX_SIZE = 20;
const int MAX_PUPIL = MAX_SIZE * MAX_SIZE + 1;
const int LIKE_CNT = 4;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
const int dirSize = sizeof(dy) / sizeof(dy[0]);

int size;
int map[MAX_SIZE][MAX_SIZE];
bool isFriend[MAX_PUPIL][MAX_PUPIL];

inline bool inRange(int y, int x)
{
    return ((0 <= y && y < size)
            && (0 <= x && x < size));
}

t_seat getSeatInfo(int y, int x, int pupilNum)
{
    t_seat seat = {y, x, 0, 0};

    for (int dir = 0; dir < dirSize; ++dir)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        if (!inRange(nextY, nextX))
            continue ;

        int &nextSpace = map[nextY][nextX];
        if (isFriend[pupilNum][nextSpace])
        {
            ++seat.likeCnt;
        }
        else if (nextSpace == EMPTY)
        {
            ++seat.emptyCnt;
        }
    }
    return (seat);
}

void takeAseat(int pupilNum)
{
    t_seat seat = {-1, -1, -1, -1};

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            if (map[y][x] != EMPTY)
                continue ;

            seat = std::max(seat, getSeatInfo(y, x, pupilNum));
        }
    }

    map[seat.y][seat.x] = pupilNum;
}

int    getTotalScore(void)
{
    static const int score[] = {0, 1, 10, 100, 1000};
    int totalScore = 0;

    for (int y = 0; y < size; ++y)
    {
        for (int x = 0; x < size; ++x)
        {
            int likeCnt = 0;
            int &curPupil = map[y][x];

            for (int dir = 0; dir < dirSize; ++dir)
            {
                int nextY = y + dy[dir];
                int nextX = x + dx[dir];

                if (!inRange(nextY, nextX))
                    continue ;

                int &nextPupil = map[nextY][nextX];
                likeCnt += isFriend[curPupil][nextPupil];
            }

            totalScore += score[likeCnt];
        }
    }
    return (totalScore);
}

int main()
{
    std::cin.tie(0)->sync_with_stdio(0);

    std::cin >> size;

    int pupilCnt = size * size;
    while (pupilCnt--)
    {
        int pupilNum;

        std::cin >> pupilNum;
        for (int i = 0; i < LIKE_CNT; ++i)
        {
            int like;

            std::cin >> like;
            isFriend[pupilNum][like] = true;
        }
        takeAseat(pupilNum);
    }

    std::cout << getTotalScore() << '\n';
    return 0;
}
