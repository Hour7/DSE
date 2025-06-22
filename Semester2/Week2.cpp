#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 
int arr[MAX_SIZE];
int n = 0;

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {          
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Recursive quicksort
void quicksort(int arr[], int low, int high) { 
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void addElements() {
    cout << "Enter number of elements to add: ";
    cin >> n;
    if (n > MAX_SIZE) {
        cout << "Too many elements! Max is " << MAX_SIZE << endl;
        return;
    }

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Elements added successfully.\n";
}

void showArray() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Elements\n";
        cout << "2. Sort Array (Quicksort)\n";
        cout << "3. Show Array\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addElements();
            break;
        case 2:
            if (n == 0)
                cout << "Array is empty. Please add elements first.\n";
            else {
                quicksort(arr, 0, n - 1);
                cout << "Array sorted successfully.\n";
            }
            break;
        case 3:
            showArray();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
