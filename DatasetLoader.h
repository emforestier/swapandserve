#ifndef DATASET_LOADER_H
#define DATASET_LOADER_H

#include <vector>
#include <string>
#include "Recipe.h"

class DatasetLoader {
public:
    static std::vector<Recipe> loadRecipes(const std::string& filename, int maxRecords = 100000);
};

#endif