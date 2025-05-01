#include <vector>
#include <iostream>
#include <algorithm>

// Function to find the maximum path sum in a grid
int maxPathSum(std::vector<std::vector<int>>& grid) {
    if (grid.empty() || grid[0].empty()) {
        return 0;
    }

    int m = grid.size();  
    int n = grid[0].size();

    // Initialize the first row (can only come from the left)
    for (int j = 1; j < n; ++j) {
        grid[0][j] += grid[0][j - 1];
    }

    // Initialize the first column (can only come from above)
    for (int i = 1; i < m; ++i) {
        grid[i][0] += grid[i - 1][0];
    }

    // For cell (i, j), the max path sum is grid[i][j] + max(path sum from top, path sum from left)
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            grid[i][j] += std::max(grid[i - 1][j], grid[i][j - 1]);
        }
    }

    // The bottom-right cell contains the maximum path sum
    return grid[m - 1][n - 1];
}

int main() {
    // Case 1
    std::vector<std::vector<int>> grid1 = {
        {1, 3},
        {2, 4}
    };
    std::cout << "Input Grid 1:" << std::endl;
    for(const auto& row : grid1) {
        for(int val : row) std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "Max Path Sum 1: " << maxPathSum(grid1) << std::endl;

    std::cout << "\n---\n" << std::endl;

    // Case 2
    std::vector<std::vector<int>> grid2 = {
        {1, -2, 5,  1},
        {-3, 9, -1, 7},
        {2,  2,  3,  1}
    };
     std::cout << "Input Grid 2:" << std::endl;
    for(const auto& row : grid2) {
        for(int val : row) std::cout << val << " ";
        std::cout << std::endl;
    }
    std::cout << "Max Path Sum 2: " << maxPathSum(grid2) << std::endl; 

    return 0;
}