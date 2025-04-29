#include <iostream>
using namespace std;

void bubbleSortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortDescending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int op;
    
    do {
        cout<<"MENU"<<endl;
        cout<<" 1. Show Array"<<endl;
        cout<<" 2. Ascending"<<endl;
        cout<<" 3. Descending"<<endl;
        cout<<" 0. Exit"<<endl;
        cout<<"Enter your option : ";cin>>op;
        switch (op)
        {
        case 1:
            cout << "Original array: ";
            displayArray(arr, size);
        break;
        case 2:
            bubbleSortAscending(arr, size);
            cout << "Sorted array in ascending order: ";
            displayArray(arr, size);
        break;
        case 3:
            bubbleSortDescending(arr, size);
            cout << "Sorted array in descending order: ";
            displayArray(arr, size);
        break;
        case 0:
            cout<<"Bye Bro!"<<endl;
        break;
        default:
            cout<<"Invalid choice. Please try again."<<endl;
            break;
        }
    } while (op != 0);

    return 0;
}