class Solution {
public:
    const int OFFSET = 1000;
    int findTargetSumWays(vector<int>& nums, int S) {
        if(abs(S) > 1000) {
            return 0;
        }
        int dp[2][2001];
        for(int i = -1000; i < 1001; i++) {
            dp[0][i + OFFSET] = 0;
        }
        dp[0][nums[0] + OFFSET] = 1;
        dp[0][-nums[0] + OFFSET] = 1;
        if(nums[0] == 0) {
            dp[0][nums[0] + OFFSET] = 2;
        }
        
        int now = 1;
        for(int i = 1; i < nums.size(); i++, now ^= 1) {
            for(int j = -1000; j <= 1000; j++) {
                dp[now][j + OFFSET] = 0;
                if(j - nums[i] + OFFSET >= 0) {
                    dp[now][j + OFFSET] += dp[now ^ 1][j - nums[i] + OFFSET];
                }
                if(j + nums[i] + OFFSET < 2001) {
                    dp[now][j + OFFSET] += dp[now ^ 1][j + nums[i] + OFFSET];
                }
            }
        }
        return dp[now ^ 1][S + OFFSET];
    }
}; 