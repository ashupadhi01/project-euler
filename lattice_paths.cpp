#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long int  no_of_paths(int m, int n) {
   long long int grid[m + 1][n + 1];
    grid[0][0] = 1;

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0 && j == 0) continue;

            if(i - 1 >= 0 && j - 1 >= 0) {
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
            }

            else if(i - 1 >= 0) {
                grid[i][j] = grid[i - 1][j];
            }

            else {
                grid[i][j] = grid[i][j - 1];
            }
        }
    }

    return grid[m][n];
}

int main(void) {

    cout << no_of_paths(20, 20) << endl;

    return 0;
}

/*

This is an iterative solution. You can only move down or towards the right of the grid. The key insight here is that the number of paths to a node in the grid is equal to the sum of paths to those nodes connected to it and pointing towards it. Here, such nodes are only two, one to the immediate left of it and one at the immediate top of it. So, number of paths to node (i, j) is sum of number of paths to node(i-1, j) and node(i, j-1).

*/
