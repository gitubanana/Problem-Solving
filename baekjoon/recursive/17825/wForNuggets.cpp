#include <iostream>

struct t_space
{
    struct t_space *nextFromStart;
    struct t_space *next;
    int toAdd;
};

const int HORSE_CNT = 4;
const int MOVE_CNT = 10;
const int END = 0;
const int START = -1;

int ans;
int moveNum[MOVE_CNT];
t_space *horses[HORSE_CNT];

void    initSpace(void)
{
    t_space *end = new t_space({NULL, NULL, END});
    t_space *fourty = new t_space({end, end, 40});

    // down from fourty (before 22)
    t_space *thirtyFive = new t_space({fourty, fourty, 35});
    t_space *thirty = new t_space({thirtyFive, thirtyFive, 30});
    t_space *twentyFive = new t_space({thirty, thirty, 25});
    t_space *twentyFour = new t_space({twentyFive, twentyFive, 24});
    t_space *twentyTwo = new t_space({twentyFour, twentyFour, 22});

    // right side of 25 (before 30)
    t_space *twentySix = new t_space({twentyFive, twentyFive, 26});
    t_space *twentySeven = new t_space({twentySix, twentySix, 27});
    t_space *twentyEight = new t_space({twentySeven, twentySeven, 28});

    // right side of end
    t_space *thirtyEight = new t_space({fourty, fourty, 38});
    t_space *thirtySix = new t_space({thirtyEight, thirtyEight, 36});
    t_space *thirtyFour = new t_space({thirtySix, thirtySix, 34});
    t_space *thirtyTwo = new t_space({thirtyFour, thirtyFour, 32});
    t_space *thirty2 = new t_space({twentyEight, thirtyTwo, 30});
    t_space *twentyEight2 = new t_space({thirty2, thirty2, 28});
    t_space *twentySix2 = new t_space({twentyEight2, twentyEight2, 26});
    t_space *twentyFour2 = new t_space({twentySix2, twentySix2, 24});
    t_space *twentyTwo2 = new t_space({twentyFour2, twentyFour2, 22});
    t_space *twenty = new t_space({twentyTwo, twentyTwo2, 20});

    // left side of 20 (before 10)
    t_space *eighteen = new t_space({twenty, twenty, 18});
    t_space *sixteen = new t_space({eighteen, eighteen, 16});
    t_space *fourteen = new t_space({sixteen, sixteen, 14});
    t_space *twelve = new t_space({fourteen, fourteen, 12});

    // left side of 25
    t_space *nineteen = new t_space({twentyFive, twentyFive, 19});
    t_space *sixteen2 = new t_space({nineteen, nineteen, 16});
    t_space *thirteen = new t_space({sixteen2, sixteen2, 13});
    t_space *ten = new t_space({thirteen, twelve, 10});

    // up side of 10
    t_space *eight = new t_space({ten, ten, 8});
    t_space *six = new t_space({eight, eight, 6});
    t_space *four = new t_space({six, six, 4});
    t_space *two = new t_space({four, four, 2});
    t_space *start = new t_space({two, two, START});

    for (int i = 0; i < HORSE_CNT; ++i)
    {
        horses[i] = start;
    }
}

inline bool moveHorse(int moveIdx, int moveCnt)
{
    t_space *&toMove = horses[moveIdx];

    if (toMove->toAdd == END)
        return (false);

    toMove = toMove->nextFromStart;
    while (--moveCnt)
    {
        if (toMove->toAdd == END)
            return (true);
        toMove = toMove->next;
    }

    for (int i = 0; i < HORSE_CNT; ++i)
    {
        if (i == moveIdx)
            continue ;

        if (toMove == horses[i])
            return (false);
    }
    return (true);
}

void    back_tracking(int curScore=0, int depth=0)
{
    if (depth == MOVE_CNT)
    {
        ans = std::max(ans, curScore);
        return ;
    }

    for (int i = 0; i < HORSE_CNT; ++i)
    {
        t_space *origin = horses[i];
        t_space *&toMove = horses[i];

        if (moveHorse(i, moveNum[depth]))
        {
            back_tracking(curScore + toMove->toAdd, depth + 1);
        }

        toMove = origin;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    for (int i = 0; i < MOVE_CNT; ++i)
    {
        std::cin >> moveNum[i];
    }

    initSpace();
    back_tracking();

    std::cout << ans << '\n';

    // del pointers (귀찮다???)
    return (0);
}
