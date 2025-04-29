#include <iostream>
using namespace std;

void showArray(int arr[], int size) {
   cout << "Array elements: ";
   for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
}

// Function for recursive binary search
int binarySearch(int arr[], int left, int right, int target) {
   if (left > right) {
      return -1; 
   }
   int mid = (right + left) / 2;
   if (arr[mid] == target) {
      return mid;
   }
   if (arr[mid] > target) {
      return binarySearch(arr, left, mid - 1, target);
   } else {
      return binarySearch(arr, mid + 1, right, target);
   }
}

// Function for recursive factorial calculation
int factorial(int n) {
   if (n <= 1) {
      return 1; 
   }
   return n * factorial(n - 1);
}

int main() {
   int arr[100];
   int size;
   int target;
   int option;

   cout << "Enter the number of elements: ";cin >> size;
   
   cout << "Enter the array elements (sorted): ";
   for (int i = 0; i < size; i++) {
      cin >> arr[i];
   }

   do {
      cout << "\n-------------- Menu ---------------\n";
      cout << "1. Show the array elements\n";
      cout << "2. Search the array elements\n";
      cout << "3. Calculate the factorial of a number\n";
      cout << "4. Exit\n";
      cout << "Choose the option: ";cin >> option;

      switch (option) {
         case 1: {
            showArray(arr, size);
            break;
         }
         case 2: {
            cout << "Enter a number to search in the array: ";cin >> target;
            int result = binarySearch(arr, 0, size - 1, target);
            if (result != -1) {
               cout << "Element found at index " << result << endl;
            } else {
               cout << "Element not found in the array." << endl;
            }
            break;
         }
         case 3: {
            int number;
            cout << "Enter a number to calculate factorial: ";cin >> number;
            cout << "Factorial of " << number << " is " << factorial(number) << endl;
            break;
         }
         case 4: {
            cout << "Exiting program." << endl;
            break;
         }
         default:
            cout << "Invalid option selected. Please try again.\n";
      }
   } while (option != 4);

   return 0;
}
