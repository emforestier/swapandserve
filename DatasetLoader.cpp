#include "DatasetLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Recipe> DatasetLoader::loadRecipes(const std::string& filename, int maxRecords) {
    std::vector<Recipe> recipes;
    std::ifstream file(filename);
    std::string line;
    int count = 0;

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file: " << filename << ". Make sure your Python download script has run successfully!\n";
        return recipes;
    }

    // Since your python script generated the CSV with header=False, 
    // every line directly corresponds to a recipe (Title, Ingredients string separated by ';')
    while (std::getline(file, line) && count < maxRecords) {
        if (line.empty()) continue;

        size_t commaPos = line.find(',');
        if (commaPos != std::string::npos) {
            std::string title = line.substr(0, commaPos);
            std::string ingredientStr = line.substr(commaPos + 1);

            std::vector<std::string> ingList;
            std::stringstream ingStream(ingredientStr);
            std::string item;

            // Ingredients are joined by ';' based on your Python formatting function
            while (std::getline(ingStream, item, ';')) {
                if (!item.empty()) {
                    ingList.push_back(item);
                }
            }

            recipes.emplace_back(title, ingList);
            count++;
        }
    }

    file.close();
    std::cout << "[Isabel] Successfully loaded " << recipes.size() << " recipe records from " << filename << " into C++ objects.\n";
    return recipes;
}