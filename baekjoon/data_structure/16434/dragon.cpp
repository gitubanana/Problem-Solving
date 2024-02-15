#include <iostream>
#include <climits>

enum e_type
{
    MONSTER = 1,
    POTION
};

struct t_room
{
    int64_t type;
    int64_t AP;
    int64_t HP;
};

const int64_t MAX = 1000000;

t_room rooms[MAX];
int64_t firstAP, roomSize;

inline std::istream &operator>>(std::istream &in, t_room &input)
{
    in >> input.type >> input.AP >> input.HP;
    return (in);
}

bool isPossible(int64_t maxHP)
{
    int64_t curHP = maxHP;
    int64_t curAP = firstAP;

    for (int i = 0; i < roomSize; ++i)
    {
        t_room &curRoom = rooms[i];

        if (curRoom.type == POTION)
        {
            curHP += curRoom.HP;
            if (curHP > maxHP)
                curHP = maxHP;

            curAP += curRoom.AP;
        }
        else
        {
            int64_t lostHP = curRoom.AP * (curRoom.HP / curAP);
            if (curRoom.HP % curAP == 0)
                lostHP -= curRoom.AP;

            if (lostHP >= curHP)
                return (false);
            curHP -= lostHP;
        }
    }
    return (curHP > 0);
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int64_t right = 1;
    int64_t potion = 0;

    std::cin >> roomSize >> firstAP;

    int64_t tmpAP = firstAP;
    for (int i = 0; i < roomSize; ++i)
    {
        t_room &curRoom = rooms[i];

        std::cin >> curRoom;
        if (curRoom.type == POTION)
        {
            potion += curRoom.HP;
            tmpAP += curRoom.AP;
        }
        else
        {
            int64_t lostHP = curRoom.AP * (curRoom.HP / tmpAP);

            if (potion >= lostHP)
            {
                potion -= lostHP;
            }
            else
            {
                potion = 0;
                right += lostHP - potion;
            }
        }
    }

    int64_t ans = LLONG_MAX;
    int64_t left = 1;
    while (left <= right)
    {
        int64_t mid = (left + right) / 2;

        if (isPossible(mid))
        {
            ans = std::min(ans, mid);
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    std::cout << ans << '\n';
    return (0);
}
