#include <iostream>
using namespace std;

void showElements(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Array[" << i << "] = " << arr[i] << endl;
    }
}

int insertElement(int arr[], int size, int position, int value) {
    if (position < 0 || position > size || size > 20) {
        cout << "Invalid position or array is full!" << endl;
        return size;
    }
    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;

    return size + 1;
}

int deleteByPosition(int arr[], int size, int position) {
    if (position < 0 || position > size) {
        cout << "Invalid position!" << endl;
        return size;
    }
    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    return size - 1;
}

int deleteByValue(int arr[], int size, int value) {
    int i = 0;
    while (i < size) {
        if (arr[i] == value) {
            for (int j = i; j < size - 1; j++) {
                arr[j] = arr[j + 1];
            }
            size--;
        } else {
            i++;
        }
    }
    return size;
}

int main() {
    int arr[20];
    int size;

    cout << "Enter the size of the array (max 20): ";cin >> size;

    if (size > 20 || size <= 0) {
        cout << "Invalid size! Exiting program." << endl;
        return 0;
    }

    cout << "Enter " << size << " elements for the array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Element " << i << ": ";cin >> arr[i];
    }

    int choice;
    do {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Show elements" << endl;
        cout << "2. Insert an element" << endl;
        cout << "3. Delete an element by position" << endl;
        cout << "4. Delete all elements by value" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";cin >> choice;

        switch (choice) {
            case 1:
                showElements(arr, size);
                break;
            case 2: {
                int position, value;
                cout << "Enter position (0 to " << size << "): ";cin >> position;
                cout << "Enter value to insert: ";cin >> value;
                size = insertElement(arr, size, position, value);
                break;
            }
            case 3: {
                int position;
                cout << "Enter position (0 to " << size - 1 << "): ";cin >> position;
                size = deleteByPosition(arr, size, position);
                break;
            }
            case 4: {
                int value;
                cout << "Enter value to delete: ";cin >> value;
                size = deleteByValue(arr, size, value);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
