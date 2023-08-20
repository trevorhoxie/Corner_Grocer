#ifndef GROCERYLIST_H
#define GROCEYRLIST_H
#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <algorithm>
using namespace std;

class GroceryList { 
    public:
        GroceryList();
        void MenuDisplay();
        bool UserInputValidation();
        void FileCreation();
        void MenuOptOne();
        void MenuOptTwo();
        void MenuOptThree();
    private:
        ifstream inFS;
        ofstream outFS;
};
#endif