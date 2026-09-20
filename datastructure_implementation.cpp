#include <iostream>
using namespace std;

#define MAX 100

// Display Array
void displayArray(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Insert Element
void insertElement(int arr[], int &n) {
    if (n >= MAX) {
        cout << "Array is full.\n";
        return;
    }

    int position, value;

    cout << "Enter position (1 to " << n + 1 << "): ";
    cin >> position;

    if (position < 1 || position > n + 1) {
        cout << "Invalid position.\n";
        return;
    }

    cout << "Enter value: ";
    cin >> value;

    // Shift elements to the right
    for (int i = n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = value;
    n++;

    cout << "Element inserted successfully.\n";
}

// Delete Element
void deleteElement(int arr[], int &n) {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    int position;

    cout << "Enter position to delete (1 to " << n << "): ";
    cin >> position;

    if (position < 1 || position > n) {
        cout << "Invalid position.\n";
        return;
    }

    // Shift elements to the left
    for (int i = position - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    cout << "Element deleted successfully.\n";
}

// Linear Search
void linearSearch(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    int key;
    bool found = false;

    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position "
                 << i + 1 << ".\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Element not found.\n";
    }
}

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int temp;

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;
            }
        }

        // Stop if array is already sorted
        if (!swapped)
            break;
    }

    cout << "Array sorted using Bubble Sort.\n";
    cout << "Time Complexity: O(n^2)\n";
}

// Selection Sort
void selectionSort(int arr[], int n) {
    int minIndex, temp;

    for (int i = 0; i < n - 1; i++) {
        minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    cout << "Array sorted using Selection Sort.\n";
    cout << "Time Complexity: O(n^2)\n";
}

// Insertion Sort
void insertionSort(int arr[], int n) {
    int key, j;

    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    cout << "Array sorted using Insertion Sort.\n";
    cout << "Time Complexity: O(n^2) worst case.\n";
}

// Sorting Menu
void sortingMenu(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }

    int choice;

    cout << "\n========== SORTING ==========\n";
    cout << "1. Bubble Sort\n";
    cout << "2. Selection Sort\n";
    cout << "3. Insertion Sort\n";
    cout << "4. Back\n";

    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {

        case 1:
            bubbleSort(arr, n);
            displayArray(arr, n);
            break;

        case 2:
            selectionSort(arr, n);
            displayArray(arr, n);
            break;

        case 3:
            insertionSort(arr, n);
            displayArray(arr, n);
            break;

        case 4:
            return;

        default:
            cout << "Invalid choice.\n";
    }
}

// Main Function
int main() {

    int arr[MAX];
    int n;
    int choice;

    cout << "============================================\n";
    cout << "     DATA STRUCTURE IMPLEMENTATION LAB\n";
    cout << "============================================\n";

    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 0 || n > MAX) {
        cout << "Invalid array size.\n";
        return 0;
    }

    cout << "Enter " << n << " elements:\n";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    do {

        cout << "\n============================================\n";
        cout << "              MAIN MENU\n";
        cout << "============================================\n";
        cout << "1. Display Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Linear Search\n";
        cout << "5. Sorting Algorithms\n";
        cout << "6. Exit\n";
        cout << "============================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                displayArray(arr, n);
                break;

            case 2:
                insertElement(arr, n);
                displayArray(arr, n);
                break;

            case 3:
                deleteElement(arr, n);
                displayArray(arr, n);
                break;

            case 4:
                linearSearch(arr, n);
                break;

            case 5:
                sortingMenu(arr, n);
                break;

            case 6:
                cout << "\nExiting program...\n";
                cout << "Thank you!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}