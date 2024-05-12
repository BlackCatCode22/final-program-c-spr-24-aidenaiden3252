#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// Linear search function with iteration count
int linearSearch(const vector<int>& arr, int target) {
    int iterations = 0;
    for (int i = 0; i < arr.size(); ++i) {
        iterations++;
        if (arr[i] == target) {
            cout << "Linear Search Iterations: " << iterations << endl;
            return i; // Return index if found
        }
    }
    cout << "Linear Search Iterations: " << iterations << endl;
    return -1; // Return -1 if not found
}

// Recursive binary search function
int binarySearchRecursive(const vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1; // Element not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) {
        return mid; // Element found
    } else if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, right); // Search right half
    } else {
        return binarySearchRecursive(arr, target, left, mid - 1); // Search left half
    }
}

// Error handling function for non-integer input
bool isInteger(const string& s) {
    if (s.empty()) return false;
    for (char c : s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

// Function to time search methods
void timeSearchMethods(const vector<int>& arr, int target) {
    auto start = chrono::steady_clock::now();
    linearSearch(arr, target);
    auto end = chrono::steady_clock::now();
    cout << "Time taken by Linear Search: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;

    start = chrono::steady_clock::now();
    int index = binarySearchRecursive(arr, target, 0, arr.size() - 1);
    end = chrono::steady_clock::now();
    cout << "Time taken by Binary Search: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    cout << "Enter the number to search for: ";
    string input;
    cin >> input;

    if (!isInteger(input)) {
        cout << "Invalid input. Please enter an integer." << endl;
        return 1;
    }

    int target = stoi(input);

    timeSearchMethods(arr, target);

    return 0;
}