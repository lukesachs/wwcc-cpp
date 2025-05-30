#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>

using namespace std;

// Function declarations
void displayMenu();
string getTimestamp();
void addEntry();
void viewEntries();
void searchEntries();

int main() {
    int choice;
    do {
        displayMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                searchEntries();
                break;
            case 4:
                cout << "\nExiting journal system. Goodbye!" << endl;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

void displayMenu() {
    cout << "\nPERSONAL JOURNAL SYSTEM\n";
    cout << "-----------------------\n";
    cout << "1. Add New Entry\n";
    cout << "2. View All Entries\n";
    cout << "3. Search Entries\n";
    cout << "4. Exit\n";
}

string getTimestamp() {
	//I was having a hard time figuringout timestamps and ctime, so I did borrow pretty heavily for this function, as I wasn't entirely sure how to go about it.
    time_t current = time(&current);
    tm* time = localtime(&current);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", time);
    return string(buffer);
}

void addEntry() {
    ofstream journalFile("journal.txt", ios::app);

    if (!journalFile) {
		cerr << "Error occurred while opening opening journal.txt for writing." << endl;
        return;
    }
    cout << "\nADD NEW JOURNAL ENTRY\n--------------------" << endl;
    cout << "Enter your journal entry (press Enter twice to finish):" << endl;

    string line, entryText;
    int enterCount = 0;

    while (true) {
        getline(cin, line);
        if (line.empty()) {
            enterCount++;
            if (enterCount == 2) {
				break;
			}
        } else {
            enterCount = 0;
        }
        entryText += line + "\n";
    }

    if (entryText.empty()) {
        cout << "Empty entry. Nothing was saved.\n";
        return;
    }

    journalFile << "Entry Date: " << getTimestamp() << "\n";
    journalFile << entryText;
    journalFile << "----------------------------------------\n";

    journalFile.close();
    cout << "\nEntry saved successfully!\n";
}


void viewEntries() {
    ifstream journalFile("journal.txt");

    if (!journalFile) {
		cerr << "Error occurred while opening journal.txt for reading." << endl;
        return;
    }

    cout << "\nJOURNAL ENTRIES\n---------------\n";

    string line;
    while (getline(journalFile, line)) {
        cout << line << "\n";
    }

    journalFile.close();
}


void searchEntries() {
    ifstream journalFile("journal.txt");
    if (!journalFile) {
        cerr << "Error occurred while opening journal.txt for searching." << endl;
        return;
    }

    cout << "\nSEARCH JOURNAL ENTRIES\n----------------------\n";
    cout << "Enter search keyword: ";
    string keyword;
    getline(cin, keyword);

    string line, entry;
    bool found = false;

    while (getline(journalFile, line)) {
        entry += line + "\n";

        if (line.find("----------------------------------------") != string::npos) {
            if (entry.find(keyword) != string::npos) {
                if (!found) {
                    cout << "\nFound matching entries:\n" << endl;
                }
                cout << entry << endl;
                found = true;
            }
            entry.clear();
        }
	}
    if (!found) {
        cout << "\nNo matching entries found for \"" << keyword << "\"." << endl;
    }

    journalFile.close();
}
