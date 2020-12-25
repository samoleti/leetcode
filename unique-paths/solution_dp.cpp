class Solution {
public:
    const int MAX_SIZE = 101;
    int uniquePaths(int m, int n) {
        int ways[MAX_SIZE][MAX_SIZE];
        for(int i = 0; i < n; i++) {
            ways[0][i] = 1;
        }
        for(int j = 0; j < m; j++) {
            ways[j][0] = 1;
        }
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                ways[i][j] = ways[i - 1][j] + ways[i][j - 1];
            }
        }
        return ways[m - 1][n - 1];
    }
};