#include <iostream>
#include <vector>
#include <unordered_map>

struct t_meal
{
    std::string buyer;
    int price;
};

const int MAX_WEEK = 10;
const int MAX_DAY = 6;
const int LAST_DAY = MAX_WEEK * 7 + MAX_DAY;

int ans;
std::vector<t_meal> dates[LAST_DAY + 1];
std::unordered_map<std::string, int> myWallet;

void    findMaxConsecutiveMealCnt(void)
{
    int cmp = 0;

    for (int cur = 7; cur <= LAST_DAY; ++cur)
    {
        bool canEat = false;

        for (const t_meal &meal : dates[cur])
        {
            const int &mealPrice = meal.price;
            const int &gotMoney = myWallet[meal.buyer];

            if (mealPrice <= gotMoney)
            {
                canEat = true;
                break ;
            }
        }

        if (canEat)
            ans = std::max(ans, ++cmp);
        else
            cmp = 0;
    }
}

int main(void)
{
    std::cin.tie(0)->sync_with_stdio(0);

    int friendCnt;
    t_meal meal;
    int week, day;
    std::string friendName;
    int gotMoney;

    std::cin >> friendCnt;
    for (int i = 0; i < friendCnt; ++i)
    {
        std::cin >> meal.buyer >> week
                 >> day >> meal.price;

        dates[week * 7 + day].push_back(meal);
    }
    for (int i = 0; i < friendCnt; ++i)
    {
        std::cin >> friendName >> gotMoney;
        myWallet[friendName] = gotMoney;
    }

    findMaxConsecutiveMealCnt();
    std::cout << ans << '\n';
    return (0);
}
