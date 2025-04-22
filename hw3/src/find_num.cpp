#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int findSecondLargest(const vector<int>& nums) {
    if (nums.size() < 2) {
        throw invalid_argument("Array must contain at least two elements.");
    }

    int largest = INT_MIN, secondLargest = INT_MIN;

    for (int num : nums) {
        if (num > largest) {
            secondLargest = largest;
            largest = num;
        } else if (num > secondLargest && num < largest) {
            secondLargest = num;
        }
    }

    if (secondLargest == INT_MIN) {
        throw invalid_argument("No second largest element found.");
    }

    return secondLargest;
}

int main() {
    vector<int> nums = {3, 5, 1, 2, 4, 5};

    try {
        cout << "Second Largest: " << findSecondLargest(nums) << endl;
    } catch (const exception& e) {
        cerr << e.what() << endl;
    }

    return 0;
}