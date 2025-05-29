#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;

struct Recipe {
    string name;
    vector<string> ingredients;
    vector<string> steps;
};

bool checkCinFail();
void printMenu();
void addRecipe(vector<Recipe> &recipes);
void displayRecipes(const vector<Recipe> &recipes);
void searchRecipes(const vector<Recipe> &recipes);
void removeRecipe(vector<Recipe> &recipes);
void showStatistics(const vector<Recipe> &recipes);

int main() {
    vector<Recipe> recipes;
    cout << "DYNAMIC RECIPE MANAGER" << endl;
    cout << "---------------------" << endl;

    int choice = 0;
    do {
        printMenu();
        cout << "Enter choice: ";
        cin >> choice;

        if (checkCinFail()) continue;

        cout << endl;

        switch (choice) {
            case 1:
                addRecipe(recipes);
                break;
            case 2:
                displayRecipes(recipes);
                break;
            case 3:
                searchRecipes(recipes);
                break;
            case 4:
                removeRecipe(recipes);
                break;
            case 5:
                showStatistics(recipes);
                break;
            case 6:
                cout << "Thank you for using recipe manager!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 6." << endl;
        }

    } while (choice != 6);

    return 0;
}

bool checkCinFail() {
    if (cin.fail()) {
        cout << "Invalid input! Please enter a number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true;
    }
    return false;
}

void printMenu() {
    cout << "\nMENU" << endl;
    cout << "1. Add Recipe" << endl;
    cout << "2. Display All Recipes" << endl;
    cout << "3. Search Recipes" << endl;
    cout << "4. Remove Recipe" << endl;
    cout << "5. Show Statistics" << endl;
    cout << "6. Exit" << endl;
}

void addRecipe(vector<Recipe> &recipes) {
    Recipe r;
    int numIng, numSteps;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter recipe name: ";
    getline(cin, r.name);

    do {
        cout << "How many ingredients? ";
        cin >> numIng;
        if (checkCinFail()) continue;
        if (numIng < 1) {
            cout << "Must have at least 1 ingredient!" << endl;
            continue;
        }
        break;
    } while (true);

    cin.ignore();
    for (int i = 0; i < numIng; i++) {
        cout << "Enter ingredient " << i + 1 << ": ";
        string ingredient;
        getline(cin, ingredient);
        r.ingredients.push_back(ingredient);
    }

    do {
        cout << "How many steps? ";
        cin >> numSteps;
        if (checkCinFail()) continue;
        if (numSteps < 1) {
            cout << "Must have at least 1 step!" << endl;
            continue;
        }
        break;
    } while (true);

    cin.ignore();
    for (int i = 0; i < numSteps; i++) {
        cout << "Enter step " << i + 1 << ": ";
        string step;
        getline(cin, step);
        r.steps.push_back(step);
    }

    recipes.push_back(r);
    cout << "\nRecipe added successfully!\n";
}

void displayRecipes(const vector<Recipe> &recipes) {
    if (recipes.empty()) {
        cout << "No recipes available." << endl;
        return;
    }

    cout << "ALL RECIPES:" << endl;
    cout << "-------------" << endl;
    for (int i = 0; i < recipes.size(); i++) {
        cout << "\nRecipe " << i + 1 << ": " << recipes[i].name << endl;
        cout << "Ingredients:" << endl;
        for (const string &ingredient : recipes[i].ingredients) {
            cout << " - " << ingredient << endl;
        }
        cout << "Steps:" << endl;
        for (int j = 0; j < recipes[i].steps.size(); j++) {
            cout << j + 1 << ". " << recipes[i].steps[j] << endl;
        }
    }
}

void searchRecipes(const vector<Recipe> &recipes) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nEnter name or ingredient to search: ";
    string input;
    getline(cin, input);

    bool foundAny = false;

    for (const auto &recipe : recipes) {
        bool found = false;
        if (recipe.name.find(input) != string::npos) {
            found = true;
        } else {
            for (const auto &ingredient : recipe.ingredients) {
                if (ingredient.find(input) != string::npos) {
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            foundAny = true;
            cout << "\nFound Recipe: " << recipe.name << endl;
            cout << "Ingredients:" << endl;
            for (const string &ingredient : recipe.ingredients) {
                cout << " - " << ingredient << endl;
            }
            cout << "Steps:" << endl;
            for (int i = 0; i < recipe.steps.size(); i++) {
                cout << i + 1 << ". " << recipe.steps[i] << endl;
            }
        }
    }

    if (!foundAny) {
        cout << "No matching recipes found." << endl;
    }
}

void removeRecipe(vector<Recipe> &recipes) {
    if (recipes.empty()) {
        cout << "\nNo recipes to remove." << endl;
        return;
    }

    int n;
    do {
        cout << "Enter recipe number to remove (1 to " << recipes.size() << "): ";
        cin >> n;
        if (checkCinFail()) continue;
        if (n < 1 || n > recipes.size()) {
            cout << "Recipe number must be between 1 and " << recipes.size() << endl;
            continue;
        }
        break;
    } while (true);

    recipes.erase(recipes.begin() + (n - 1));
    cout << "Recipe removed successfully.\n";
}

void showStatistics(const vector<Recipe> &recipes) {
    int allRecipes = recipes.size();
    int ingredients = 0;
    int steps = 0;

    for (const auto &recipe : recipes) {
        ingredients += recipe.ingredients.size();
        steps += recipe.steps.size();
    }

    cout << "\nCOLLECTION STATISTICS" << endl;
    cout << "--------------------" << endl;
    cout << "Total recipes: " << allRecipes << endl;
    cout << fixed << setprecision(1);
    cout << "Average ingredients per recipe: " << (allRecipes ? (double)ingredients / allRecipes : 0.0) << endl;
    cout << "Average steps per recipe: " << (allRecipes ? (double)steps / allRecipes : 0.0) << endl;
}
