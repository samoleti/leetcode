class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int occurrences = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (occurrences == 0) {
                majority = nums[i];
                occurrences = 1;
            } else if (majority == nums[i]) {
                occurrences++;
            } else {
                occurrences--;
            }
        }
        return majority;
    }
};