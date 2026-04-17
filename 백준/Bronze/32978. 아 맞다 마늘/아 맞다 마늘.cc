#include <iostream>
#include <set>

int main(void) {
    std::cin.tie(0)->sync_with_stdio(0);

    int ingredientCount;
    std::string ingredient;
    std::set<std::string> ingredients;

    std::cin >> ingredientCount;
    for (int i = 0; i < ingredientCount; i++) {
        std::cin >> ingredient;
        ingredients.insert(ingredient);
    }

    for (int i = 1; i < ingredientCount; i++) {
        std::cin >> ingredient;
        ingredients.erase(ingredient);
    }

    std::cout << *ingredients.begin() << '\n';
    return 0;
}
