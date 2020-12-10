class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        vector<vector<int>> B(2, vector<int>(A.size(), 0));
        for(int i = 0; i < A[0].size(); i++) {
            B[0][i] = A[0][i];
        }
        for(int i = 1; i < A.size(); i++) {
            for(int j = 0; j < A.size(); j++) {
                if(j == 0) {
                    B[1][j] = min(B[0][j], B[0][j+1]) + A[i][j];
                } else if(j == A[i].size() - 1) {
                    B[1][j] = min(B[0][j], B[0][j-1]) + A[i][j];
                } else {
                    B[1][j] = min(B[0][j], min(B[0][j-1], B[0][j+1])) + A[i][j];
                }
            }
            for(int j = 0; j < A[0].size(); j++) {
                B[0][j] = B[1][j];
            }
        }
        int min = B[0][0];
        for(int i = 0; i < A.size(); i++) {
            if(min > B[0][i]) {
                min = B[0][i];
            }
        }
        return min;
    }
};