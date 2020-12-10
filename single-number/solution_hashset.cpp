class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hashset;
        for(int i = 0; i < nums.size(); i++) {
            if(hashset.find(nums[i]) != hashset.end()) {
                hashset.erase(nums[i]);
            } else {
                hashset.insert(nums[i]);
            }
        }
        return *hashset.begin();
    }
};