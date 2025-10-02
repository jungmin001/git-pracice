#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class PotionRecipe {
	public:
	string potionName;
	vector<string> ingredients;

    PotionRecipe() : potionName(""), ingredients{} {}

	PotionRecipe(const string& name, const vector<string>& ingredients)
		: potionName(name), ingredients(ingredients) {}
};

class AlchemyWorkshop {
    private:
    vector<PotionRecipe> recipes;

    public:
    void addRecipe(const string& name, const vector<string>& ingredients) {
        recipes.push_back(PotionRecipe(name, ingredients));
        cout << "레시피" << name << "가 추가 되었습니다" << endl;
    }

    void displayAllRecipes() const {
        if (recipes.empty()) {
            cout << "===레시피 없음===" << endl;
            return;
        }


        cout << "===레시피 목록===" << endl;

        for (size_t i = 0; i < recipes.size(); ++i) {
            cout << "물약 이름: " << recipes[i].potionName << endl;
            cout << "물약 재료: " << endl;
            cout << endl;


            for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) {
                cout << recipes[i].ingredients[j];
                if (j < recipes[i].ingredients.size() - 1) cout << ", ";
            }
            cout << endl;
        }
    }

    PotionRecipe searchRecipeByName(string name) {
        for (const auto& recipe : recipes) {
            if (name == recipe.potionName) {
                return recipe;
            }
        }
        return PotionRecipe("", {});
    }

    vector<PotionRecipe> searchRecipeByIngredient(string ingredient) 
    {
        vector<PotionRecipe> results = {};

        for (const auto& recipe : recipes) {
            for (const auto& i : recipe.ingredients) {
                if (i == ingredient) {
                    results.push_back(recipe);
                }
            }
        }
        return results;
    }
};

 class StockManager {
     private:
     map<string, int> potionStock;
     const int MAX_STOCK = 3;

     public:
     void initializeStock(string potionName) {
        potionStock[potionName] = MAX_STOCK;
     }

     bool dispensePotion(string potionName) {
         if (potionStock.end() != potionStock.find(potionName)
             && 0 < potionStock[potionName]) {
             --potionStock[potionName];
             return true;
         }
         return false;
        }

     void returnPotion(string potionName) {
         if (potionStock.end() != potionStock.find(potionName)
             && 3 > potionStock[potionName]) {
             ++potionStock[potionName];
             cout << ">> " << potionName << "이(가) 반납되었습니다." << endl;
         }
         else {
             cout << ">> " << potionName << "을(를) 반납받지 못했습니다." << endl;
         }
     }

     int getStock(string potionName) const {
             if (potionStock.end() != potionStock.find(potionName)) {
             auto it = potionStock.find(potionName);
             return it->second;
             }
         return -1;
     }
 };

int main() {
    StockManager myStock;
    AlchemyWorkshop myWorkshop;
    
		while (true) {
            system("cls");
 			cout << "연금술 공방 관리 시스템" << endl;
			cout << "1. 레시피 추가" << endl;
			cout << "2. 모든 레시피 출력" << endl;
			cout << "3. 레시피 검색" << endl;
			cout << "4. 재료 검색" << endl;
			cout << "5. 물약 대여" << endl;
			cout << "6. 물약 반납" << endl;
			cout << "7. 재고 확인" << endl;
			cout << "8. 종료" << endl;
			cout << "선택: ";
			
            int choice;
            cin >> choice;

            if (cin.fail()) {
                cout << "잘못된 입력입니다. 숫자를 입력해주세요." << endl;
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            if (choice == 1) {
                string name;
                cout << "물약 이름: ";
                cin.ignore(10000, '\n');
                getline(cin, name);

                vector<string> ingredients_input;
                string ingredient;
                cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << endl;

                while (true) {
                    cout << "재료 입력: ";
                    getline(cin, ingredient);

                    if (ingredient == "끝") {
                        break;
                    }
                    ingredients_input.push_back(ingredient);
                }

                if (!ingredients_input.empty()) {
                    myWorkshop.addRecipe(name, ingredients_input);
                    myStock.initializeStock(name);
                }

                else {
                    cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << endl;
                }

            }

            else if (choice == 2) {
                myWorkshop.displayAllRecipes();
            }

            else if (choice == 3) {
                string name;
                cout << "물약 이름: ";
                cin.ignore(10000, '\n');
                getline(cin, name);

                PotionRecipe recipe = myWorkshop.searchRecipeByName(name);

                if (recipe.potionName.empty()) {
                    cout << name << "이라는 레시피가 존재하지 않습니다." << endl;
                }

                else {
                    cout << name << "이라는 레시피를 찾았습니다." << endl;
                }
            }

            else if (choice == 4) {
                string name;
                cout << "물약 이름: ";
                cin.ignore(10000, '\n');
                getline(cin, name);

                vector<PotionRecipe> recipes = myWorkshop.searchRecipeByIngredient(name);

                if (recipes.empty()) {
                    cout << name << "을(를) 사용하는 레시피가 존재하지 않습니다." << endl;
                }

                else {
                    cout << "=== " << name << "을(를) 사용하는 레시피 ===" << endl;

                    for (size_t i = 0; i < recipes.size(); ++i) {
                        cout << i + 1 << ". " << recipes[i].potionName << endl;
                    }
                }
            }

            else if (choice == 5) {
                string name;
                cout << "물약 이름: ";
                cin.ignore(10000, '\n');
                getline(cin, name);

                bool isDispensed = myStock.dispensePotion(name);

                if (isDispensed) {
                    cout << name << "를 대여했습니다." << endl;
                }

                else {
                    cout << name << "를 대여하지 못했습니다." << endl;
                }
            }

            else if (choice == 6) {
                string name;
                cout << "물약 이름: ";
                cin.ignore(10000, '\n');
                getline(cin, name);

                myStock.returnPotion(name);
            }

            else if (choice == 7) {
                string name;
                cout << "물약 이름: ";
                cin.ignore(10000, '\n');
                getline(cin, name);

                int stock = myStock.getStock(name);
                if (-1 == stock)
                {
                    cout << ">> " << name << "을(를) 찾지 못했습니다." << endl;
                }

                else {
                    cout << ">> 이름: " << name << " / 수량: " << stock << endl;
                }
            }

            else if (choice == 8) {
                cout << "공방 문을 닫습니다..." << endl;
                break;
            }

            else {
                cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
            }

            system("pause");
        }

    return 0;
}