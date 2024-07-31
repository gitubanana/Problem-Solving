#include <iostream>
#include <vector>
#include <memory>

struct t_space
{
    static std::vector<std::shared_ptr<t_space>> allObjects;

    int num;
    t_space *next;
    t_space *nextFromStart;

    t_space(int num, t_space *next, t_space *nextFromStart)
        : num(num), next(next), nextFromStart(nextFromStart)
    {
        allObjects.emplace_back(this);
    }
};

const int HORSE_CNT = 4;
const int DEPTH_LIMIT = 10;
t_space *end;

int ans;
int move[DEPTH_LIMIT];
t_space *horse[HORSE_CNT];
std::vector<std::shared_ptr<t_space>> t_space::allObjects;

void    buildMap(void)
{
    end = new t_space(0, NULL, NULL);
    t_space *fourty = new t_space(40, end, end);

    // 30 윗 부분
    t_space *thirtyEight = new t_space(38, fourty, fourty);
    t_space *thirtySix = new t_space(36, thirtyEight, thirtyEight);
    t_space *thirtyFour = new t_space(34, thirtySix, thirtySix);
    t_space *thirtyTwo = new t_space(32, thirtyFour, thirtyFour);

    // 40 아랫 부분
    t_space *thirtyFive = new t_space(35, fourty, fourty);
    t_space *thirty = new t_space(30, thirtyFive, thirtyFive);
    t_space *twentyFive = new t_space(25, thirty, thirty);
    t_space *twentyFour = new t_space(24, twentyFive, twentyFive);
    t_space *twentyTwo = new t_space(22, twentyFour, twentyFour);

    // 25 오른쪽 부분
    t_space *twentySix = new t_space(26, twentyFive, twentyFive);
    t_space *twentySeven = new t_space(27, twentySix, twentySix);
    t_space *twentyEight = new t_space(28, twentySeven, twentySeven);
    t_space *thirty2 = new t_space(30, thirtyTwo, twentyEight);

    // 20 오른쪽 부분
    t_space *twentyEight2 = new t_space(28, thirty2, thirty2);
    t_space *twentySix2 = new t_space(26, twentyEight2, twentyEight2);
    t_space *twentyFour2 = new t_space(24, twentySix2, twentySix2);
    t_space *twentyTwo2 = new t_space(22, twentyFour2, twentyFour2);
    t_space *twenty = new t_space(20, twentyTwo2, twentyTwo);

    // 20 왼쪽 부분
    t_space *eighteen = new t_space(18, twenty, twenty);
    t_space *sixteen = new t_space(16, eighteen, eighteen);
    t_space *fourteen = new t_space(14, sixteen, sixteen);
    t_space *twelve = new t_space(12, fourteen, fourteen);

    // 25 왼쪽 부분
    t_space *nineteen = new t_space(19, twentyFive, twentyFive);
    t_space *sixteen2 = new t_space(16, nineteen, nineteen);
    t_space *thirteen = new t_space(13, sixteen2, sixteen2);
    t_space *ten = new t_space(10, twelve, thirteen);

    // 10 윗 부분
    t_space *eight = new t_space(8, ten, ten);
    t_space *six = new t_space(6, eight, eight);
    t_space *four = new t_space(4, six, six);
    t_space *two = new t_space(2, four, four);

    t_space *start = new t_space(0, two, two);
    for (int i = 0; i < HORSE_CNT; ++i)
    {
        horse[i] = start;
    }
}

t_space *moveHorse(t_space *cur, int moveCnt)
{
    cur = cur->nextFromStart;
    while (--moveCnt && cur != end)
    {
        cur = cur->next;
    }

    return (cur);
}

bool isTheSame(t_space *cmp, int num)
{
    if (cmp == end)
        return (false);

    for (int i = 0; i < HORSE_CNT; ++i)
    {
        if (i == num)
            continue ;

        if (horse[i] == cmp)
            return (true);
    }
    return (false);
}

void    backTracking(int curScore=0, int depth=0)
{
    if (depth == DEPTH_LIMIT)
    {
        ans = std::max(ans, curScore);
        return ;
    }

    for (int num = 0; num < HORSE_CNT; ++num)
    {
        t_space *&cur = horse[num];
        if (cur == end)
            continue ;

        t_space *next = moveHorse(cur, move[depth]);
        if (isTheSame(next, num))
            continue ;

        t_space *origin = cur;

        cur = next;
        backTracking(curScore + cur->num, depth + 1);
        cur = origin;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    buildMap();
    for (int i = 0; i < DEPTH_LIMIT; ++i)
    {
        std::cin >> move[i];
    }

    backTracking();
    std::cout << ans << '\n';
    return 0;
}
