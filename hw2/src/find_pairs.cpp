#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find all pairs of integers in the array that sum up to the target
vector<vector<int>> findPairsWithTargetSum(const vector<int>& nums, int target) {
    vector<vector<int>> result;
    unordered_map<int, int> numCount;

    for (int num : nums) {
        int complement = target - num;
        if (numCount[complement] > 0) {
            result.push_back({complement, num});
            numCount[complement]--;
        } else {
            numCount[num]++;
        }
    }

    return result;
}

int main() {
    // Test case for Problem 1
    vector<int> nums1 = {3, 2, 4};
    int target1 = 6;
    vector<vector<int>> result1 = findPairsWithTargetSum(nums1, target1);
    cout << "Pairs for target " << target1 << ": ";
    for (const auto& pair : result1) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    vector<int> nums2 = {2, 2, 3, 3, 3, 4, 4};
    int target2 = 6;
    vector<vector<int>> result2 = findPairsWithTargetSum(nums2, target2);
    cout << "Pairs for target " << target2 << ": ";
    for (const auto& pair : result2) {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;

    return 0;
}