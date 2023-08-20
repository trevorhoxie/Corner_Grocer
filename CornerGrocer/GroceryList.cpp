#include "GroceryList.h"

GroceryList::GroceryList() {

}

void GroceryList::FileCreation() {
    string currWord;
    map<string, int> list;
    inFS.open("CS210_Project_Three_Input_File.txt");
    outFS.open("frequency.dat");
    while (!inFS.eof()) {
        getline(inFS, currWord);
        if (list.find(currWord) == list.end()) {
            list[currWord] = 1;
        }
        else {
            list[currWord]++;
        }
    }

    map<string, int>::iterator iter;
    for (iter = list.begin(); iter != list.end(); iter++) {
        outFS << iter->first << " " << iter->second << endl;
    }
    inFS.close();
    outFS.close();
}

void GroceryList::MenuDisplay() {
    cout << "Corner Grocer" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "1. Display frequency for a specific item." << endl;
    cout << "2. Display a list of all items and their frequencies." << endl;
    cout << "3. Display histogram of all items." << endl;
    cout << "4. Exit Application" << endl;
    cout << "Please enter your selection as a number 1-4:" << endl;
}

bool GroceryList::UserInputValidation() {
    int userSelection;
    do {
        FileCreation();
        MenuDisplay();
        cin >> userSelection;
        if (userSelection == 1) {
            MenuOptOne();
            continue;
        }
        else if (userSelection == 2) {
            MenuOptTwo();
            continue;
        }
        else if (userSelection == 3) {
            MenuOptThree();
            continue;
        }
        else if (userSelection == 4) {
            return false;
        }
        else {
            cout << "Please enter a valid selection." << endl;
        }
        return true;
    } while (true);
}

void GroceryList::MenuOptOne() {
    string search;
    string fileList;
    int freq = 0;
    inFS.open("CS210_Project_Three_Input_File.txt");
    cout << "Please enter the item you're looking for: " << endl;
    cin >> search;

    while (!inFS.eof()) {
        getline(inFS, fileList);
        if (fileList == search) {
            freq += 1;
        }
    }

    cout << "Number of times that item appears: " << freq << endl;
    cout << "Press enter to continue..." << endl;
    cin.ignore();
    cin.get();
    inFS.close();
    for (int i = 0; i < 40; ++i) { //Clears the terminal after a selection executes.
    cout << endl;
    }
}

void GroceryList::MenuOptTwo() {
    string currWord;
    map<string, int> list;
    inFS.open("CS210_Project_Three_Input_File.txt");
    while (!inFS.eof()) {
        getline(inFS, currWord);
        if (list.find(currWord) == list.end()) {
            list[currWord] = 1;
        }
        else {
            list[currWord]++;
        }
    }
    cout << "Items on the list and the number of times they show up: " << endl;
    map<string, int>::iterator iter;
    for (iter = list.begin(); iter != list.end(); iter++) {
        cout << iter->first << " " << iter->second << endl;
    }
    cout << "Press enter to continue..." << endl;
    inFS.close();
    cin.ignore();
    cin.get();
    for (int i = 0; i < 40; ++i) { //Clears the terminal after a selection executes.
        cout << endl;
    }
}

void GroceryList::MenuOptThree() {
    string currWord;
    map<string, int> list;
    inFS.open("CS210_Project_Three_Input_File.txt");
    while (!inFS.eof()) {
        getline(inFS, currWord);
        if (list.find(currWord) == list.end()) {
            list[currWord] = 1;
        }
        else {
            list[currWord]++;
        }
    }
    cout << "Item frequency in the form of a histogram: " << endl;
    map<string, int>::iterator iter;
    for (iter = list.begin(); iter != list.end(); iter++) {
        cout << iter->first << " " << string(iter->second, '*') << endl; //Prints out a string of asterisks based on the number in the map.
    }
    cout << "Press enter to continue..." << endl;
    inFS.close();
    cin.ignore();
    cin.get();
    for (int i = 0; i < 40; ++i) { //Clears the terminal after a selection executes.
        cout << endl;
    }
}