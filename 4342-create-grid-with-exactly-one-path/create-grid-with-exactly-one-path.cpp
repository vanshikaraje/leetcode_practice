class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        int i = 0, j = 0;
        grid[0][0] = '.';

        while (i < m - 1 || j < n - 1) {
            if (i == m - 1) {
                j++;
            }
            else if (j == n - 1) {
                i++;
            }
            else {
                // Move right whenever possible
                j++;
            }

            grid[i][j] = '.';
        }

        return grid; 
    }
};