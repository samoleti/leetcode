class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int result = 0;
	int sum_odd_left = 0;
        int sum_even_left = 0;
        int sum_odd_right = 0;
        int sum_even_right = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                sum_even_right += nums[i];
            } else {
                sum_odd_right += nums[i];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                sum_even_right -= nums[i];
            } else {
                sum_odd_right -= nums[i];
            }
            if (sum_odd_right + sum_even_left == sum_even_right + sum_odd_left) {
                result++;
            }
            if (i % 2 == 0) {
                sum_even_left += nums[i];
            } else {
                sum_odd_left += nums[i];
            }
        }
        return result;
    }
};