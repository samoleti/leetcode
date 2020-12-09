class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b)
    {
        return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
    }
    static const int MAX_AREA = 40000*40000;
    int minAreaRect(vector<vector<int>>& points) {
       int area = MAX_AREA + 1;
       sort(points.begin(), points.end(), compare);
       unordered_set<int> hashset;
       for(int i = 0; i < points.size(); i++)
       { 
           hashset.insert(points[i][0]*40001 + points[i][1]);
       }
       for(int i = 0; i < points.size(); i++)
       {
            for(int j = points.size() - 1; j >= i + 3; j--)
            {
                if(points[i][1] < points[j][1])
                {
                    int b_x = points[j][0];
                    int b_y = points[i][1];
                    int c_x = points[i][0];
                    int c_y = points[j][1];
                    if(hashset.find(b_x * 40001 + b_y) != hashset.end() && 
                       hashset.find(c_x * 40001 + c_y) != hashset.end())
                    {
                        int x = b_x - c_x;
                        int y = c_y - b_y;
                        if(area > x * y && x * y != 0)
                        {
                            area = x * y;
                        }
                    } 
                }
            }
       }
       return (area > MAX_AREA) ? 0 : area;
    }
};