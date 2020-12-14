class Solution {
public:
    map<int, int> hashmap;
    int encode(int level, int sum) {
        return sum * 21 + level;
    }
    int myfunc(vector<int>& nums, int S, int i) {
        if (i == nums.size()) {
            return S == 0;
        }
        int code = encode(i, S);
        if(hashmap.find(code) == hashmap.end()) {
            hashmap[code] = myfunc(nums, S - nums[i], i + 1) + myfunc(nums, S + nums[i], i + 1);
        } 
        return hashmap[code];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        if(abs(S) > 1000) {
            return 0;
        }
        return myfunc(nums, S, 0);
    }
};