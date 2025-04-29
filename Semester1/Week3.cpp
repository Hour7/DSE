#include <iostream>
using namespace std;

void showArray(int arr[], int size) {
    cout << "Array elements:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Array[" << i << "] = " << arr[i] << endl;
    }
}

int insertElement(int arr[], int size, int value) {
    int i;
    if (size > 20) {
        cout << "Array is full, cannot insert more elements." << endl;
        return size;
    }
    
    for (i = size - 1; i >= 0 && arr[i] > value; i--) {
        arr[i] = arr[i + 1];
    }
    arr[i + 1] = value;
    cout << "Inserted " << value << " into the array." << endl;
    return size + 1;
}

int deleteElement(int arr[], int size, int value) {
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

void binarySearch(int arr[], int size, int value) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == value) {
            cout << "Found " << value << " at index " << mid << "." << endl;
            return;
        } else if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << value << " not found in the array." << endl;
}

int main() {
    int arr[20], size, value, choice;

    cout << "Enter the number of elements (max 20): ";cin >> size;
    if (size > 20 || size <= 0) {
        cout << "Invalid size! Exiting." << endl;
        return 0;
    }

    cout << "Enter " << size << " elements in sorted order:" << endl;
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    do {
        cout << endl;
        cout << "Menu:" << endl;
        cout << "1. Show elements" << endl;
        cout << "2. Insert element" << endl;
        cout << "3. Delete element" << endl;
        cout << "4. Search for element" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                showArray(arr, size);
                break;
            case 2:
                cout << "Enter value to insert: ";cin >> value;
                size = insertElement(arr, size, value);
                break;
            case 3:
                cout << "Enter value to delete: ";cin >> value;
                size = deleteElement(arr, size, value);
                break;
            case 4:
                cout << "Enter value to search: ";cin >> value;
                binarySearch(arr, size, value);
                break;
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 5);

    return 0;
}