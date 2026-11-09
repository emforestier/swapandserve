#include "Recipe.h"

Recipe::Recipe() : title(""), ingredients({}), substitutes({}) {}

Recipe::Recipe(std::string t, std::vector<std::string> ing) 
    : title(t), ingredients(ing), substitutes({}) {}