class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int result = 0;
        vector<int> count(100, 0);
        for(int i = 0; i < dominoes.size(); i++) {
            if(dominoes[i][0] > dominoes[i][1]) {
                swap(dominoes[i][0], dominoes[i][1]);
            }
            int to_find = dominoes[i][0] * 10 + dominoes[i][1];
            result += count[to_find];
            count[to_find]++;
        }
        return result;
    }
};