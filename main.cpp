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

void bubbleSortVisual(vector<int>& arr, int delayMs = 100) {
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

int main() {
    vector<int> arr = {5, 1, 8, 3, 2, 7, 4, 6};


    clearScrean();
    cout << "Initial Array:\n";
    printArray(arr);
    sleepMs(1000);

    bubbleSortVisual(arr, 150);

    clearScrean();
    cout << "Sorted Array:\n";
    printArray(arr);

    return 0;
}
