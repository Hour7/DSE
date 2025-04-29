#include <iostream>
using namespace std;

void findDuplicates(int arr[], int size, int searchValue) {
    bool found = false;
    cout << "value is found at index : " << searchValue << ": ";
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchValue) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "None";
    }
    cout << endl;
}

void findNonDuplicates(int arr[], int size, int searchValue) {
    cout << "value is found at index : " << searchValue << ": ";
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchValue) {
            cout << i << endl;
            return;
        }
    }
    cout << "None" << endl;
}


int main() {
    int arr[20], size, choice, searchValue;

    cout << "Enter array size (max 20): ";cin >> size;

    if (size > 20 || size <= 0) {
        cout << "Invalid size! Exiting."<<endl;
        return 0;
    }

    cout << "Enter " << size << " elements:"<<endl;
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": ";cin >> arr[i];
    }

    do {
        cout << "Menu:"<<endl;
        cout << "1. Search duplicates for a number"<<endl;
        cout << "2. Search non-duplicates for a number"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number to search: ";cin >> searchValue;
                findDuplicates(arr, size, searchValue);
                break;

            case 2:
                cout << "Enter the number to search: ";cin >> searchValue;
                findNonDuplicates(arr, size, searchValue);
                break;

            case 0:
                cout << "Exiting program. Goodbye Bro!"<<endl ;
                break;

            default:
                cout << "Invalid choice. Please try again."<<endl;
        }
    } while (choice != 0);

    return 0;
}
