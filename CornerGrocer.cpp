/*
 * CornerGrocer.cpp
 * Author: Nathan Johnson
 * Purpose: Count produce purchases, display the results,
 * and save the counts in a backup file.
 */

#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <string>

using namespace std;

// GroceryTracker keeps the purchase counts and provides the three reports.
class GroceryTracker {
public:
    // Read the purchase record and count each occurrence of an item.
    bool LoadPurchases(const string& fileName) {
        ifstream inputFile(fileName);
        if (!inputFile) {
            return false;
        }

        string item;
        while (inputFile >> item) {
            ++itemCounts[item];
        }

        // Reaching the end of the file is normal; a bad stream means a read error.
        return !inputFile.bad();
    }

    // Save every item and its count to the required backup file.
    bool SaveBackup(const string& fileName) const {
        ofstream backupFile(fileName);
        if (!backupFile) {
            return false;
        }

        for (const auto& entry : itemCounts) {
            backupFile << entry.first << ' ' << entry.second << '\n';
        }
        return backupFile.good();
    }

    // Return the requested item's count, or zero if it was never purchased.
    int GetFrequency(const string& item) const {
        auto found = itemCounts.find(item);
        if (found == itemCounts.end()) {
            return 0;
        }
        return found->second;
    }

    // Show every item beside the number of times it was purchased.
    void PrintFrequencies() const {
        for (const auto& entry : itemCounts) {
            cout << entry.first << ' ' << entry.second << '\n';
        }
    }

    // Show one asterisk for each purchase of an item.
    void PrintHistogram() const {
        for (const auto& entry : itemCounts) {
            cout << entry.first << ' '
                << string(entry.second, '*') << '\n';
        }
    }

private:
    // The item name is the key; its purchase frequency is the value.
    // A map also keeps the item names in alphabetical order for the reports.
    map<string, int> itemCounts;
};

int main() {
    GroceryTracker tracker;
    const string inputFileName = "CS210_Project_Three_Input_File.txt";

    // Load the supplied records before showing any menu options.
    if (!tracker.LoadPurchases(inputFileName)) {
        cerr << "Could not read " << inputFileName << '\n';
        return 1;
    }

    // Create frequency.dat automatically at startup as the required backup.
    if (!tracker.SaveBackup("frequency.dat")) {
        cerr << "Could not create frequency.dat\n";
        return 1;
    }

    // Keep showing the menu until the user chooses option 4.
    int choice = 0;
    while (choice != 4) {
        cout << "\n1. Look up an item\n"
            << "2. Show all item frequencies\n"
            << "3. Show a histogram\n"
            << "4. Exit\n"
            << "Enter a choice: ";

        // Clear invalid input so the user can enter another menu choice.
        if (!(cin >> choice)) {
            if (cin.eof()) {
                break;
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter 1, 2, 3, or 4.\n";
            continue;
        }

        // Perform the report or search selected from the menu.
        switch (choice) {
        case 1: {
            string item;
            cout << "Enter an item: ";
            if (!(cin >> item)) {
                return 0;
            }
            cout << tracker.GetFrequency(item) << '\n';
            break;
        }
        case 2:
            tracker.PrintFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            break;
        default:
            cout << "Please enter 1, 2, 3, or 4.\n";
            break;
        }
    }

    return 0;
}