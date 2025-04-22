#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Helper function for DFS
void dfs(vector<vector<int>>& grid, int x, int y, int rows, int cols, int connectivity) {
    grid[x][y] = 0; // Mark as visited
    vector<pair<int, int>> directions;

    if (connectivity == 4) {
        directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // 4-connected
    } else if (connectivity == 8) {
        directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}; // 8-connected
    }

    for (auto [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
            dfs(grid, nx, ny, rows, cols, connectivity);
        }
    }
}

// Function to count islands
int countIslands(vector<vector<int>> grid, int connectivity) {
    int rows = grid.size();
    int cols = grid[0].size();
    int islandCount = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == 1) {
                ++islandCount;
                dfs(grid, i, j, rows, cols, connectivity);
            }
        }
    }

    return islandCount;
}

int main() {
    vector<vector<int>> grid1 = {
        {0, 1, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 1},
        {0, 1, 0, 1}
    };

    vector<vector<int>> grid2 = {
        {1, 0, 0, 0},
        {0, 0, 1, 1},
        {1, 1, 1, 0},
        {0, 0, 1, 1}
    };

    cout << "4-connected (grid1): " << countIslands(grid1, 4) << endl;
    cout << "8-connected (grid1): " << countIslands(grid1, 8) << endl;

    cout << "4-connected (grid2): " << countIslands(grid2, 4) << endl;
    cout << "8-connected (grid2): " << countIslands(grid2, 8) << endl;

    return 0;
}