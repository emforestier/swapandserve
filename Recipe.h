#ifndef RECIPE_H
#define RECIPE_H

#include <string>
#include <vector>

class Recipe {
public:
    std::string title;
    std::vector<std::string> ingredients;
    std::vector<std::string> substitutes;

    Recipe();
    Recipe(std::string t, std::vector<std::string> ing);
};

#endif