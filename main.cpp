#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

using namespace std;

void printArray(const vector<int>& arr) {
    for (int value : arr) {
        // print a bar of '#' for each value
        for (int i = 0; i < value; ++i) {
            cout << '#';
        }
        cout << " (" << value << ")\n";
    }
}

void clearScrean() {
    system("clear");
}

void sleepMs(int ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

void bubbleSortVisual(vector<int>& arr, int delayMs = 80) {
    // Bubble Sort with visualization
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;

                // Visualize the array after each swap
                clearScrean();
                printArray(arr);
                sleepMs(delayMs);
            }
        }
        if (!swapped) break; // Array is sorted
    }
}

void insertionSortVisual(vector<int>& arr, int delayMs = 80) {
    // Insertion Sort with visualization
    int n = arr.size();

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;

            // Visualize the array after each shift
            clearScrean();
            printArray(arr);
            sleepMs(delayMs);
        }
        arr[j + 1] = key;

        // Visualize the array after placing the key
        clearScrean();
        printArray(arr);
        sleepMs(delayMs);
    }
}

void selectionSortVisual(vector<int>& arr, int delayMs = 80) {
    // Selection Sort with visualization
    int n = arr.size();

    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            // Swap the found minimum element with the first element
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;

            // Visualize the array after each swap
            clearScrean();
            printArray(arr);
            sleepMs(delayMs);
        }
    }
}

void mergeSortVisual(vector<int>& arr, int left, int right, int delayMs = 80) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSortVisual(arr, left, mid, delayMs);
    mergeSortVisual(arr, mid + 1, right, delayMs);

    // Merge step
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (i = left, k = 0; i <= right; ++i, ++k) {
        arr[i] = temp[k];

        // Visualize the array after each merge operation
        clearScrean();
        printArray(arr);
        sleepMs(delayMs);
    }
}

int main() {
    int n = 15;
    vector<int> arr(n);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 15);

    for (int i = 0; i < n; ++i) {
        arr[i] = dist(gen);
    }

    cout<<"Choose algorithm:\n1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Merge Sort\n";

    int choice;
    cin>>choice;

    clearScrean();
    cout << "Initial Array:\n";
    printArray(arr);
    sleepMs(1000);

    switch (choice) {
        case 1:
            bubbleSortVisual(arr);
            break;
        case 2:
            insertionSortVisual(arr);
            break;
        case 3:
            selectionSortVisual(arr);
            break;
        case 4:
            mergeSortVisual(arr, 0, n - 1);
            break;
        default:
            cout << "Invalid choice!\n";
            return 0;
    }

    clearScrean();
    cout << "Sorted Array:\n";
    printArray(arr);

    return 0;
}
