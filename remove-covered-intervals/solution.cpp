class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() - 1;
        int res = intervals.size();
        sort(intervals.begin(), intervals.end(), compare);
        int i = 0;
        int j = 1;
        while(j < intervals.size()) {
            if(intervals[i][0] == intervals[j][0]) {
                res--;
                i++;
                j++;
            } else if(intervals[i][1] >= intervals[j][1]) {
                j++;
                res--;
            } else {
                i = j;
                j++;
            }
            n--;
        }
        return res;
    }
};