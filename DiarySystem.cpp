#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function definitions
void addEntry();
void viewEntries();
void deleteEntries();

int main() {
    int choice;
    do {
        cout<< "\n--- Personal Diary Management ---\n";
        cout<< "1. Add Diary Entry\n";
        cout<< "2. View Diary Entries\n";
        cout<< "3. Delete All Entries\n";
        cout<< "4. Exit\n";
        cout<< "Enter your choice: ";
        cin>> choice;

        switch(choice) {
            case 1:
                addEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                deleteEntries();
                break;
            case 4:
                cout<< "\nExited Successfully!\n";
                break;
            default:
                cout<< "Invalid choice! Please try again.\n";
        }
    } while(choice != 4);
    return 0;
}

// Function to add a diary entry
void addEntry() {
    string entry;
    cin.ignore();
    cout<< "\nEnter your diary entry: ";
    getline(cin,entry);

    ofstream file("diary.txt",ios::app);
    if(file) {
        file<< entry<< "\n---\n"; //  "---" as a separator which makes the file easier to read
        file.close();
        cout<< "Entry added successfully!\n";
    } else {
        cout<< "Error: Could not open file.\n";
    }
}

// Function to view all diary entries
void viewEntries() {
    ifstream file("diary.txt");
    if(file) {
        string line;
        cout<< "\n--- Diary Entries ---\n";
        while(getline(file,line)) {
            cout<< line<< endl;
        }
        file.close();
    } else {
        cout<< "\nNo entries found. Pls create a diary!\n";
    }
}

// Function to delete all diary entries
void deleteEntries() {
    ofstream file("diary.txt",ios::trunc); // Truncate file to delete contents
    if(file) {
        file.close();
        cout<< "\nAll entries deleted successfully!\n";
    } else {
        cout<< "\nError: Could not delete all entries!\n";
    }
}
