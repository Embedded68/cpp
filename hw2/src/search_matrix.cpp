#include <iostream>
#include <vector>
using namespace std;

// Function to search for a target in a sorted 2D matrix
bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int left = 0, right = rows * cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / cols][mid % cols];

        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    // Test case for Problem 2
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 40, 60}
    };
    int target3 = 30;
    bool found = searchMatrix(matrix, target3);
    cout << "Target " << target3 << " in matrix: " << (found ? "true" : "false") << endl;

    return 0;
}