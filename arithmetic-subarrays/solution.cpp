class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> result;
        for(int i = 0; i < l.size(); i++) {
            int left = l[i];
            int right = r[i];
            vector<int> temp;
            for(int j = left; j <= right; j++) {
                temp.push_back(nums[j]);
            }
            sort(temp.begin(), temp.end());
            int diff = temp[1] - temp[0];
            bool flag = true;
            for(int j = 1; j < temp.size(); j++) {
                if(temp[j] - temp[j-1] != diff) {
                    result.push_back(false);
                    flag = false;
                    break;
                }
            }
            if(flag == true) {
                result.push_back(true);
            }
        }
        return result;
    }
};